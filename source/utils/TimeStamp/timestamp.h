#pragma once
#include "../common.h"


class timeStamp{
public:
    timeStamp();
    timeStamp(const uint64 &time);
    static std::string formatString();
    static uint64 now();
private:
    uint64 secondCount;
};