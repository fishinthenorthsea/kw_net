#pragma once
#include "common.h"
#include "sql.h"
#include "mysql.h"
class sql;

class Mysql :public sql{
public:
    void connectSql(const char* addr, const char* user, const char* passwd, const char* tableName) override;
    Mysql();
    ~Mysql();


    
    MYSQL* sql_;
};
