#pragma once

#include "utils/common.h"
#include "field.h"


class GcClass{                                 //真正提供动态识别支持的基类
public:
    GcClass() = default;
    virtual ~GcClass() = default;

    std::string           strName_;          //类名
    uint32                autoComponentID_;  //类唯一ID
    static uint32         maxComponentID_;   //类唯一ID 的最大值

    uint32                serializeTypeID_;  //序列化ID
};


class GcClassImpl : public GcClass{      // 其实GcClass 应该是个虚基类，但是暂时不懂为什么
public:
    GcClassImpl(const char* className){
        strName_ = className;
    }

private:
    //扩展内容   
    std::vector<GcField*>                         allFields_;        //该类的所有的字段
    std::vector<GcField*>                         syncFields_;       //需要进行同步的字段      用于视野同步

    std::unordered_map<std::string, GcField*>     name2FiledMap_;
    std::vector<BYTE>                             syncGroup_;        //同步分组   

};





//全自动注册节点基类
class registerClassBase{
public:
    static void autoRegister(registerClassBase* base);
    virtual GcClass* Register() = 0; 

    GcClass* GetStaticClass(const char* className){
        GcClassImpl* cls = new GcClassImpl(className);
        return cls;
    }
private:
};


//全自动注册节点
template<class TClass>
class autoRegisterClass: public registerClassBase{
public:
    autoRegisterClass(){
        autoRegister(this);
    }   //构造后自动加入到静态链表中 ------>即运行期前保证全部注册完毕

    GcClass* Register() override{
        return TClass::GetStaticClass();
    }
private:
};





//静态链表实例
class registerClass{
public:
    std::list<registerClassBase*>headList_;
    static registerClass& getRegisterClass();
    registerClass(){}
    registerClass(const registerClass&){}
    registerClass& operator =(const registerClass&){}
private:
    
    
};


//对外开放的管理结构
class GcClassManager{
public:
    GcClassManager();
private:
};




#define  CLASS_DECLARE(TCLASS, TBASECLASS) \
private: \
    static GcClass* _staticGetClass();\
    static void _classMemberRegister(GcClass* cls);\
    static GcObject* _classCreateInstance();\
public: \
    typedef TBASECLASS BaseClass;\
    typedef TCLASS ThisClass;\
    static GcClass* GetStaticClass() { return _staticGetClass();}\
    static GcClass* GetClass() { return ThisClass::_staticGetClass();}








#define CLASS_IMPL_BEGIN(TCLASS, serializeID) \
    static autoRegisterClass<TCLASS> autoClass##TCLASS; \
    GcClass* TCLASS::_staticGetClass(){ \
        static GcClass* _staticClass = nullptr; \
        if(nullptr == _staticClass) { \
            _staticClass = autoClass##TCLASS.GetStaticClass(#TCLASS);    \
        } \
        return _staticClass;\
    }


#define CLASS_IMPL_END(TCLASS) \
    void TCLASS::_classMemberRegister(GcClass* cls){ 




#define CLASS_IMPL_GENERAL(TCLASS) \
    CLASS_IMPL_BEGIN(TCLASS)\
    GcObject* TCLASS::_classCreateInstance() { return new TCLASS(); } \
    CLASS_IMPL_END(TCLASS)


#define CLASS_IMPL_GENERAL_END() }