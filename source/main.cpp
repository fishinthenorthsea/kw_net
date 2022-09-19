#include "utils/Log/Log.cpp"
#include "utils/TimeStamp/timestamp.cpp"
#include "utils/common.h"
#include "utils/Mutex/mutex.cpp"

using namespace kw;
uint32 num = 0;
Mutex mutex;
int main(){
    std::cout<<timeStamp::NowSecond()<<std::endl;
    std::cout<<timeStamp::NowMs()<<std::endl;
    std::cout<<timeStamp::formatString()<<std::endl;

   // std::cout<<va("wudi %d  %s!\n",5,100);

    std::string sss("12345");
    LogInfo("sss\n");
    
    // std::thread a([&](){
    //     for(auto i = 0 ; i < 10000000 ; ++i){           
    //         mutex.lock();
    //         ++num;
    //         mutex.unlock();
    //     }
    // });


    // for(auto i = 0 ; i < 10000000 ; ++i){
    //         mutex.lock();
    //         ++num;
    //         mutex.unlock();
    // }
    // a.join();

    // std::cout<<num<<std::endl;
    return 0;
}