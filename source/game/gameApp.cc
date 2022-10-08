#include "gameApp.h"
#include "game/gameWorld.h"

GameApp::GameApp(){
    Init();
}

void GameApp::Init(){
    gameWorld::createGameWorld();
}