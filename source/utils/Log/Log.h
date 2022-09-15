#pragma once
#include "../common.h"

enum LogGrage : uint32{
    Debug  = 0,
    Info   = 1,
    Error  = 2,
};

#define LogInfo(...)  {va(...);}



class KwLog{
public:
    KwLog& GetInstanceKwLog(){
        
    }
private:
    std::string logName_;
    KwLog(){};
    KwLog(const KwLog&){};
    const KwLog& operator =(const KwLog&){};

};

