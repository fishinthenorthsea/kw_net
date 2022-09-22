#pragma once
#include "common.h"


class Mutex{
public:
    explicit Mutex();
    ~Mutex();
    void lock();
    void unlock();
private:

#ifdef _WIN32
    std::mutex mutex_;
#elif __linux__
    pthread_mutex_t mutex_;
#endif
};



class MutexGuard{
public:
    explicit MutexGuard(Mutex& mutex):mutex_(mutex){};
    ~MutexGuard(){mutex_.unlock();}
private:
    Mutex& mutex_;
};











