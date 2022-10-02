#pragma once
#include "common.h"

namespace kw{

class timeStamp{
public:
    timeStamp();
    timeStamp(const uint64 &time);

    static std::string formatString();
    static void formatString(time_t time);
    static uint64 NowSecond();               //1970.1.1 至今的 秒数
    static uint64 NowMs();                   //1970.1.1 至今的 毫秒数
private:
    uint64 secondCount;
};



}