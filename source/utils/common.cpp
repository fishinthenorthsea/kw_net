#include "common.h"


char buffer[1024];




char* va(char* fmt, ...){
    va_list args;
    va_start (args, fmt);
    if(strlen(fmt)>=1024){
        //LogInfo("va size > 1024\n");
        va("va size > 1024\n");
        return buffer;
    }
    int ret = vsnprintf(buffer,1024,fmt, args);
    va_end (args);
    return buffer;
}