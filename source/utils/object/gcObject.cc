#include "gcObject.h"
#include "utils/log.h"

GcClass* GcObject::GetStaticClass(){
    static GcClass* staticClass = nullptr;
    if(nullptr == staticClass){
        staticClass = new GcClassImpl();
    }
    return staticClass;
}