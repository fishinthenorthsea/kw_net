#pragma once

#include "utils/common.h"
#include "field.h"


class GcClass{                                 //真正提供动态识别支持的基类
public:
    template<class T>
    T* Component();
    
    template<class T>
    T* addComponent();
private:
    std::string           strName_;          //类名
    uint32                autoComponentID_;  //类唯一ID
    static uint32         maxComponentID_;   //类唯一ID 的最大值

    

};


class GcClassImpl : public GcClass{      // 其实GcClass 应该是个虚基类，但是暂时不懂为什么
public:

private:
    //扩展内容   
    std::vector<GcField*>                         allFields_;        //该类的所有的字段
    std::vector<GcField*>                         syncFields_;       //需要进行同步的字段      用于视野同步

    std::unordered_map<std::string, GcField*>     name2FiledMap_;
    std::vector<BYTE>                             syncGroup_;        //同步分组   

};