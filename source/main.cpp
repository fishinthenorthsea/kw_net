#include "utils/Log/Log.h"
#include "utils/TimeStamp/timestamp.cpp"
#include "utils/common.h"
#include "utils/Mutex/mutex.cpp"
uint32 num = 0;
kw::Mutex mutex;
int main(){
    test();
    std::cout<<timeStamp::now()<<std::endl;
    std::cout<<timeStamp::formatString()<<std::endl;

    std::thread a([&](){
        for(auto i = 0 ; i < 10000000 ; ++i){
            
            mutex.lock();
            ++num;
            mutex.unlock();
        }
    });


    for(auto i = 0 ; i < 10000000 ; ++i){
            mutex.lock();
            ++num;
            mutex.unlock();
        }
    a.join();

    std::cout<<num<<std::endl;
    return 0;
}