#include "gameApp.h"
#include "game/gameWorld.h"
#include "utils/kvTable/table.h"
GameApp::GameApp(){
    Init();
}

void GameApp::Init(){
    CTableManager::CreateInstance();

    gameWorld::createGameWorld();
}