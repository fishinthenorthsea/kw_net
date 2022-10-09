#pragma once
#include "utils/common.h"
#include "utils/component/component.h"
#include "class.h"


class GcObject{                                 //对外开放的 可实现动态识别的基类
public:
    static GcClass* GetStaticClass();    

    
private:
};


class GcEntity : public GcObject{
public:
    uint64 getEntityID(){ return entityID_;}

    template<class T>
    T* Component();
    
    template<class T>
    T* addComponent();
private:
    uint64 entityID_;

    std::unordered_map<uint32, std::unique_ptr<class Component>>ComponentMap_;
};