#pragma once

class sql{
public:
    virtual void connectSql(const char* addr, const char* user, const char* passwd, const char* tableName) = 0;
    virtual ~sql(){};
private:
};