#pragma once
#include "utils/common.h"
#include "utils/object/gcObject.h"
class Component :public GcObject{
public:
    static uint32 uid = 5;             //属于组件自己的Tid
};