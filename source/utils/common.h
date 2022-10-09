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
    NONE    = 0,
    BOOL    = 1,    // 'b'
    INT8    = 2;    // 'c'  char
    UINT8   = 3;    // 'y'  byte
    INT16   = 4,    // 'h'  short
    UINT16  = 5,    // 'w'  word
    INT32   = 6,    // 'i'  integer
    UINT32  = 7,    // 'u'  uint
    INT64   = 8,    // 'I'  Interger
    UINT64  = 9,    // 'U'  UInterger

    FLOAT   = 10,   // 'f'  float
    DOUBLE  = 11,   // 'd'  double

    STRING  = 12,   // 's'  string

    OBJECT  = 13,   // 'o'  object
    ARRAY   = 14,   // 'a'  数组
    DICT    = 15,   // 'D'  字典 map
    MEMBLOCK= 16,   // 'm'  memblock
    USERPTR = 17,   // 'p'  玩家指针
    FUNC    = 18,   // 'f'  函数指针

    MAX     = 19
};


char* va(char* fmt, ...);

