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
#include <assert.h> 
#include <memory>

//#define NDEBUG     开启 assert


#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN 
#include <windows.h>

#elif __linux__

#include<sys/time.h>
#endif


typedef unsigned long long     uint64;
typedef unsigned int           uint32;
typedef unsigned short         uint16;
typedef unsigned char          uint8;
typedef unsigned char          BYTE;




enum ValueType{
    KNONE    = 0,
    KBOOL    = 1,    // 'b'
    KINT8    = 2,    // 'c'  char
    kINT8   = 3,    // 'y'  byte
    kINT16   = 4,    // 'h'  short
    kUINT16  = 5,    // 'w'  word
    kINT32   = 6,    // 'i'  integer
    kUINT32  = 7,    // 'u'  uint
    kINT64   = 8,    // 'I'  Interger
    kUINT64  = 9,    // 'U'  UInterger

    kFLOAT   = 10,   // 'f'  float
    kDOUBLE  = 11,   // 'd'  double

    kSTRING  = 12,   // 's'  string

    kOBJECT  = 13,   // 'o'  object
    kARRAY   = 14,   // 'a'  数组
    kDICT    = 15,   // 'D'  字典 map
    kMEMBLOCK= 16,   // 'm'  memblock
    kUSERPTR = 17,   // 'p'  玩家指针
    kFUNC    = 18,   // 'f'  函数指针

    kMAX     = 19
};


char* va(char* fmt, ...);

