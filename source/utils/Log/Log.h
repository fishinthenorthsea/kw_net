#pragma once
#include "../common.h"
#include "../TimeStamp/timestamp.h"



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
    snprintf(str,1100,"[%s INFO] %s",kw::timeStamp::formatString().c_str(), msg);
    kw::KwLog::GetInstanceKwLog().write(str);
}
void commonLogError(const char* msg){
    char str[1100];
    snprintf(str,1100,"[%s Error] %s",kw::timeStamp::formatString().c_str(), msg);
    kw::KwLog::GetInstanceKwLog().write(str);
}

//#define LogInfo(...)  {kw::KwLog::GetInstanceKwLog().write("123");va(...);}
#define LogInfo(...)  (commonLogInfo(va(__VA_ARGS__)));



#define ERR_PLACE commonLogError(va("place:[%s:%d]\n",__FILE__,__LINE__))


#define RETURN_FALSE  {ERR_PLACE;return false;}
#define RETURN_TRUE  {ERR_PLACE;return true;}
#define RETURN_VOID  {ERR_PLACE;return ;}
#define RETURN_0  {ERR_PLACE;return false;}
#define RETURN_NULL  {ERR_PLACE;return nullptr;}
#define RETURN_CONTINUE  {ERR_PLACE;return continue;}
#define RETURN_BREAK  {ERR_PLACE;return break;}