#include "timestamp.h"
#include <chrono>
timeStamp::timeStamp(){
    secondCount = 0;
}

timeStamp::timeStamp(const uint64 &time){
    secondCount = time;
}


std::string timeStamp::formatString(){
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
	std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);
	std::tm* tm_time = std::localtime(&now_time_t);
    char buf[128];
   // int microseconds = static_cast<int>(microSecondsSinceEpoch_ % kMicroSecondsPerSecond);
    // snprintf(buf, sizeof(buf), "%4d%02d%02d %02d:%02d:%02d.%06d",
    //          tm_time->tm_year + 1900, tm_time->tm_mon + 1, tm_time->tm_mday,              //年月日
    //          tm_time->tm_hour, tm_time->tm_min, tm_time->tm_sec,                          //时分秒
    //          microseconds);                                                               //毫秒

	snprintf(buf, sizeof(buf), "%4d%02d%02d %02d:%02d:%02d",
             tm_time->tm_year + 1900, tm_time->tm_mon + 1, tm_time->tm_mday,              //年月日
             tm_time->tm_hour, tm_time->tm_min, tm_time->tm_sec                         //时分秒
    );                                                               //毫秒

	return buf;
}


uint64 timeStamp::NowSecond(){
	auto nowTime = std::chrono::system_clock::now();
	return std::chrono::duration_cast<std::chrono::seconds>(nowTime.time_since_epoch()).count();
}



uint64 timeStamp::NowMs(){
#ifdef _WIN32
	// SYSTEMTIME sys_time;
    // GetLocalTime(&sys_time);
    // printf( "%4d/%02d/%02d %02d:%02d:%02d.%03d  %1d\n", sys_time.wYear,   sys_time.wMonth, sys_time.wDay, sys_time.wHour, sys_time.wMinute, sys_time.wSecond,sys_time.wMilliseconds,sys_time.wDayOfWeek);
	auto nowTime = std::chrono::system_clock::now();
	return std::chrono::duration_cast<std::chrono::milliseconds>(nowTime.time_since_epoch()).count();
#elif __linux__
    struct timeval tv;
    gettimeofday(&tv, NULL);
    int64_t seconds = tv.tv_sec;
    return seconds * 1000 + tv.tv_usec;
#endif
}