#include "kw_mysql.h"

void Mysql::connectSql(const char* addr, const char* user, const char* passwd, const char* tableName)
{
    mysql_init(sql_);
    // localhost:服务器 root为账号密码 test为数据库名 3306为端口
    if (!mysql_real_connect(sql_, addr, user, passwd, tableName, 3306, NULL, 0))
    {
        printf("connect mysql is error!\n");
    }
    else
    {
        printf("connect mysql is success!\n");
    }
}
Mysql::Mysql()
{
    sql_ = new MYSQL; // mysql连接
}

Mysql::~Mysql()
{
    mysql_close(sql_);
}