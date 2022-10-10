#include "gcObject.h"
#include "utils/log.h"

static autoRegisterClass<GcObject> ___autoClass;

GcClass* GcObject::_staticGetClass(){
    static GcClass* staticClass = nullptr;
    if(nullptr == staticClass){
        staticClass = ___autoClass.GetStaticClass("GcObject");
    }
    return staticClass;
}