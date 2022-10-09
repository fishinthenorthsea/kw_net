#include "class.h"

GcClass* GcObject::GetStaticClass(){
    static GcClass* staticClass = nullptr;
    if(nullptr == staticClass){
        staticClass = new GcClassImpl();
    }
    return staticClass;
}