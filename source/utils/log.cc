#include "log.h"
using namespace kw;


KwFile::KwFile()
              :fp_(::fopen("", "a"))
{
}

KwFile::KwFile(const std::string filename)
              :fp_(::fopen(filename.c_str(), "a"))
{
}
KwFile::~KwFile(){
    ::fclose(fp_);
}

void KwFile::write(const char* str, uint32 len){
    _fwrite_nolock(str, 1, len, fp_);
    ::fflush(fp_);
    printf("%s",str);
}




KwLog::KwLog():file_(new KwFile("loggg.txt"))
{
}

KwLog::KwLog(const std::string filename):file_(new KwFile(filename))
{
}

KwLog::~KwLog(){
    delete file_;
}


void KwLog::write(const char* str){
    file_->write(str,strlen(str));
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
