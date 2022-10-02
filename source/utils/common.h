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




char* va(char* fmt, ...);