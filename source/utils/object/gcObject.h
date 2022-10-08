#pragma once
#include "utils/common.h"
#include "utils/component/component.h"
class GcObject{
public:
     
    template<class T>
    T* Component();
    
    template<class T>
    T* addComponent();

    uint64 getEntityID(){ return EntityID;}
private:
    uint64 EntityID;
    std::unordered_map<uint32, std::unique_ptr<class Component>>ComponentMap;
};