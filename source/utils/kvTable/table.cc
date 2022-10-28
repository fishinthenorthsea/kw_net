#include "table.h"


CTableManager* g_tables;
void CTableManager::CreateInstance(){
    if(!g_tables){
        g_tables = new CTableManager();
    }

    //TODO  目前思路就是创建一个总目录文件 config.txt  其内容为不同的 res/table_config.txt 等       table_config.txt 里则为 res/database/system_resources/xxx.csv   的资源


    return ;
}


CTable* CTableManager::get(const std::string& name){
    auto iter = m_tables.find(name);
    if(iter == m_tables.end()){
        return nullptr;
    }
    else{
        return iter->second;
    }

}

CTable* CTableManager::parseCsv(const char* path)
{
    CTable* table = new CTable;
    


    return table;
}