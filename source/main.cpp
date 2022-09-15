#include "utils/Log/Log.h"
#include "utils/TimeStamp/timestamp.cpp"
#include "utils/common.h"
#include "utils/Mutex/mutex.cpp"
uint32 num = 0;
kw::Mutex mutex;
int main(){
    std::cout<<timeStamp::NowSecond()<<std::endl;
    std::cout<<timeStamp::NowMs()<<std::endl;
    std::cout<<timeStamp::formatString()<<std::endl;

    std::cout<<va("wudi %d  %s!\n",5,100);


    
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