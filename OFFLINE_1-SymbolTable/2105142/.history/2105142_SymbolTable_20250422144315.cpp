#include <bits/stdc++.h>
using namespace std;

#include "2105142_symbolInfo.cpp"
#include "2105142_scopeTable.cpp"
class SymbolTable
{
private:

    ScopeTable* current_scopetable;

public:

    void EnterScope();
    void ExitScope();
    bool Insert(string name,string type);
    void EnterScope();
    
};

void SymbolTable::EnterScope(){
    ScopeTable* newScopeTable = new ScopeTable();
    newScopeTable->setParent(current_scopetable);
}