#pragma once
#include "../common.h"


class KwLog{
public:
    KwLog& GetInstanceKwLog(){
        
    }
private:
    std::string logName_;
    KwLog(){};
    KwLog(const KwLog&){};
    const KwLog& operator =(const KwLog&){};

};

void test(){
    std::cout<<"44 44"<<std::endl;
}