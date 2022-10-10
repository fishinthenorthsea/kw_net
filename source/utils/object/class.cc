#include "class.h"


uint32 GcClass::maxComponentID_ = 0;



registerClass& registerClass::getRegisterClass(){
    static registerClass sRegister;
    return sRegister;
}


void registerClassBase::autoRegister(registerClassBase* base){
    auto v = registerClass::getRegisterClass();
    v.headList_.push_back(base);
}


