#include "utils/common.h"
#include "utils/Log.h"
#include "utils/timestamp.h"
#include "utils/mutex.h"
#include "spdlog/spdlog.h"
#include "game/gameApp.h"
#include <array>
#include <iostream>
#include <memory>
#include <asio.hpp>
#include <asio/experimental/as_tuple.hpp>
#include <asio/experimental/awaitable_operators.hpp>

using asio::awaitable;
using asio::buffer;
using asio::co_spawn;
using asio::detached;
using asio::ip::tcp;
namespace this_coro = asio::this_coro;
using namespace asio::experimental::awaitable_operators;
using std::chrono::steady_clock;
using namespace std::literals::chrono_literals;

constexpr auto use_nothrow_awaitable = asio::experimental::as_tuple(asio::use_awaitable);

awaitable<void> timeout(steady_clock::duration duration)
{
    asio::steady_timer timer(co_await this_coro::executor);
    timer.expires_after(duration);
    co_await timer.async_wait(use_nothrow_awaitable);
}

awaitable<void> proxy(tcp::socket client)
{
    std::array<char, 1024> data;
    for (;;)
    {
        //让人忍不住吐槽这个read_some
        //如果真想处理粘包还得专门写个客户端
        //先收固定长度再收额外长度？
        //异步操作会不会出现数据包接受不到的可能？
        auto result1 = co_await (
            client.async_read_some(buffer(data), use_nothrow_awaitable) ||
            timeout(5s));

        if (result1.index() == 1)
            co_return; // timed out

        auto [e1, n1] = std::get<0>(result1);
        if (e1)
            break;

        auto result2 = co_await (
            async_write(client, buffer(data, n1), use_nothrow_awaitable) ||
            timeout(1s));

        if (result2.index() == 1)
            co_return; // timed out

        auto [e2, n2] = std::get<0>(result2);
        if (e2)
            break;
    }
}

awaitable<void> listen(tcp::acceptor &acceptor)
{
    for (;;)
    {
        std::cout << "listing" << std::endl;
        auto [e, client] = co_await acceptor.async_accept(use_nothrow_awaitable);
        if (e)
            break;

        auto ex = client.get_executor();
        co_spawn(ex, proxy(std::move(client)), detached); //开个协程去处理
    }
}

void init()
{
}

int main(int argc, char *argv[])
{
    try
    {
        init();

        asio::io_context ctx;

        auto listen_endpoint =
            *tcp::resolver(ctx).resolve(
                "",
                "9999",
                tcp::resolver::passive);
        tcp::acceptor acceptor(ctx, listen_endpoint);

        co_spawn(ctx, listen(acceptor), detached);
        

        
        GameApp game;

        ctx.run();
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }
}