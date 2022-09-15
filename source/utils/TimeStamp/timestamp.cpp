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


uint64 timeStamp::now(){
   /* std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
	std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);
	std::tm* now_tm = std::localtime(&now_time_t);

	char buffer[128];
	strftime(buffer, sizeof(buffer), "%F %T", now_tm);

	std::ostringstream ss;
	ss.fill('0');

	std::chrono::milliseconds ms;
	std::chrono::microseconds cs;
	std::chrono::nanoseconds ns;
	
	switch (time_stamp_type)
	{
	case 0:
		ss << buffer;
		break;
	case 1:
		ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;
		ss << buffer << ":" << ms.count();
		break;
	case 2:
		ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;
		cs = std::chrono::duration_cast<std::chrono::microseconds>(now.time_since_epoch()) % 1000000;
		ss << buffer << ":" << ms.count() << ":" << cs.count() % 1000;
		break;
	case 3:
		ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;
		cs = std::chrono::duration_cast<std::chrono::microseconds>(now.time_since_epoch()) % 1000000;
		ns = std::chrono::duration_cast<std::chrono::nanoseconds>(now.time_since_epoch()) % 1000000000;
		ss << buffer << ":" << ms.count() << ":" << cs.count() % 1000 << ":" << ns.count() % 1000;
		break;
	default:
		ss << buffer;
		break;
	}

	return ss.str();
*/
	auto nowTime = std::chrono::system_clock::now();
	return std::chrono::duration_cast<std::chrono::microseconds>(nowTime.time_since_epoch()).count();
}