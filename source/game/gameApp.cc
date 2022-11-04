#include "gameApp.h"
#include "game/gameWorld.h"
#include "utils/kvTable/table.h"
GameApp::GameApp(){
    Init();
}

void GameApp::Init(){
    CTableManager::CreateInstance();    //table 初始化



    gameWorld::createGameWorld();      // g_world
    g_world->Init();                   // 游戏世界初始化
}