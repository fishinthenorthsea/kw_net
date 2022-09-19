#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<list>
#include<set>
#include<string>
#include<mutex>
#include<thread>
#include <stdio.h>
#include <stdarg.h>
#include<fstream>
#include "assert.h" 
//#define NDEBUG     开启 assert


#ifdef _WIN32
#include <windows.h>

#elif __linux__

#include<sys/time.h>
#endif










typedef unsigned long long     uint64;
typedef unsigned int           uint32;
typedef unsigned short         uint16;
typedef unsigned char          uint8;



char buffer[1024];




char* va(char* fmt, ...){
    va_list args;
    va_start (args, fmt);
    if(strlen(fmt)>=1024){
        //LogInfo("va size > 1024\n");
        va("va size > 1024\n");
        return buffer;
    }
    int ret = vsnprintf (buffer,1024,fmt, args);
    va_end (args);
    printf("ret : %d\n",ret);
    return buffer;
}