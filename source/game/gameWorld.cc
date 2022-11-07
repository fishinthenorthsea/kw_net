#include "gameWorld.h"
#include "utils/log.h"
gameWorld *g_world = nullptr;

void gameWorld::createGameWorld()
{
    if (!g_world)
    {
        g_world = new gameWorld();
    }
}

gameWorld::gameWorld()
{
}

gameWorld::~gameWorld()
{
    delete sql_;
}

static void WorldLoadData(){

}

bool gameWorld::Init(){
    if (!BaseClass::Init()){
        RETURN_FALSE;
    }
    // TODO 地图初始化

    // TODO 连接数据库
    // sql_ = new Mysql;
    // sql_->connectSql("127.0.0.1", "root", "", "yc_t16");

    WorldLoadData(); //游戏开启读盘操作
    return true;
}
