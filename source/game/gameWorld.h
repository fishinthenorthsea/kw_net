#pragma once
#include "utils/common.h"
#include "utils/sql/kw_mysql.h"
#include "game.h"
class gameWorld :public Game{
public:
    static void createGameWorld();
    void init();
    ~gameWorld();

private:
    gameWorld();
    gameWorld(const gameWorld&){}
    gameWorld& operator =(const gameWorld&){}

    sql* sql_;
};



extern gameWorld* g_world;
