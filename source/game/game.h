#pragma once
#include "utils/common.h"
#include "utils/object/gcObject.h"

class Game{
public:
    GcObject* FindEntityByEid(uint64 eid);

private:
    std::unordered_map<uint64, GcObject*>entityMap_;
};