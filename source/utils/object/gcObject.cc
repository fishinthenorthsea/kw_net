#include "gcObject.h"
#include "utils/log.h"

template<class T>
T* GcObject::Component(){
    uint32 uid = T->uid;
    auto& iter = ComponentMap.find(uid);
    if(iter == ComponentMap.end()){
        return nullptr;
    }
    return iter->second.get();
}


template<class T>
T* GcObject::addComponent(){
    uint32 uid = T->uid;
    auto& iter = ComponentMap.find(uid);
    if(iter != ComponentMap.end()){
        LogInfo("GcObject %lld was having %s \n", getEntityID(), );
    }
    return iter->second.get();
}