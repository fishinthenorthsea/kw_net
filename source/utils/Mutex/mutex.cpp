#include "mutex.h"

namespace kw{

Mutex::Mutex(){

}

Mutex::~Mutex(){
#ifdef _WIN32
#elif __linux__
    ptrhead_mutex_destroy(&mutex_);
#endif
}

void Mutex::lock(){
#ifdef _WIN32
    mutex_.lock();
#elif __linux__
    ptrhead_mutex_lock(&mutex_);
#endif
}

void Mutex::unlock(){
#ifdef _WIN32
    mutex_.unlock();
#elif __linux__
    ptrhead_mutex_lock(&mutex_);
#endif
}
}