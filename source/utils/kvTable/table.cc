#include "table.h"


CTableManager* g_tables;
void CTableManager::CreateInstance(){
    if(!g_tables)
        g_tables = new CTableManager();
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