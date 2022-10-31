#pragma once
#include "utils/common.h"
class CCeil{
public:
    std::string m_name;
    ValueType m_type;
    BYTE* m_data;
};

class CLine{
public:
    std::unordered_map<std::string, CCeil*> m_ceil;
};


class CTable{
public:
    std::vector<CLine*> m_line;                    
    std::string m_tableName;
};


class CTableManager{
public:
    static void CreateInstance();
    //CTable* get(const std::string& name);
    CTable* parseCsv(const char* path);
private:
    //std::unordered_map<std::string, CTable*> m_tables;
};



extern CTableManager* g_tables;
