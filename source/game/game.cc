#include "game.h"


GcObject* Game::FindEntityByEid(uint64 eid){
    auto& iter = entityMap_.find(eid);
    if(iter == entityMap_.end()){
        return nullptr;
    }
    return iter->second;
}