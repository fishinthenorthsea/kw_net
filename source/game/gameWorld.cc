#include "gameWorld.h"

gameWorld* g_world = nullptr;

void gameWorld::createGameWorld(){
    if(!g_world){
        g_world = new gameWorld();
    }
}


gameWorld::gameWorld(){
    BaseClass::Init();

    //TODO 地图初始化

    //TODO 连接数据库
   // sql_ = new Mysql;
  //  sql_->connectSql("127.0.0.1", "root", "", "yc_t16");

    
    //TODO WorldLoadData  


}


gameWorld::~gameWorld(){
    delete sql_;
}