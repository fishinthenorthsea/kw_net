#pragma once
#include "utils/common.h"
#include "utils/object/gcObject.h"

class Game : public GcObject{
    CLASS_DECLARE(Game, GcObject)

    GcObject* FindEntityByEid(uint64 eid);
    bool Init();

private:
    std::unordered_map<uint64, GcObject*>entityMap_;
};