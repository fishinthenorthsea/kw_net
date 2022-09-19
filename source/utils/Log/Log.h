#pragma once
#include "../common.h"
#include "../TimeStamp/timestamp.cpp"

namespace kw{

enum LogGrage : uint32{
    Debug  = 0,
    Info   = 1,
    Error  = 2,
};




class KwFile{
public:
    KwFile();
    ~KwFile();
    const KwFile& operator =(const KwFile&) = delete;
    KwFile(const std::string filename);
    void write(const char* str, uint32 len);
private:
    std::string logName_;
    FILE* fp_;
};


class KwLog{
public:
    static KwLog& GetInstanceKwLog(){
        static KwLog kvLog;
        return kvLog;
    }
    void write(const char* str);
    ~KwLog();
private:
    KwLog();
    
    KwLog(const std::string filename);
    KwFile* file_;
};
}








void commonLogInfo(const char* msg){
    char str[1100];
    snprintf(str,1100,"[%s INFO] %s\n",kw::timeStamp::formatString().c_str(), msg);
    kw::KwLog::GetInstanceKwLog().write(str);
}


//#define LogInfo(...)  {kw::KwLog::GetInstanceKwLog().write("123");va(...);}
#define LogInfo(...)  (commonLogInfo(va(__VA_ARGS__)));