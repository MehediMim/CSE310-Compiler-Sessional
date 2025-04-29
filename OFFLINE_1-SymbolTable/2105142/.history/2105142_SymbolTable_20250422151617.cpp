#include <bits/stdc++.h>
using namespace std;

#include "2105142_symbolInfo.cpp"
#include "2105142_scopeTable.cpp"
class SymbolTable
{
private:
    int num_buckets;
    ScopeTable* current_scopetable;

public:

    SymbolTable(int num_buckets){
        current_scopetable= new ScopeTable(num_buckets);
        current_scopetable->setParent(nullptr); 
        // Creating a new hashTable with null parent
    }


    void EnterScope();
    void ExitScope();
    bool Insert(string name,string type);
    void EnterScope();
    
};

void SymbolTable::EnterScope(){
    ScopeTable* newScopeTable = new ScopeTable();
    newScopeTable->setParent(current_scopetable);
}

void SymbolTable::ExitScope(){
    if(current_scopetable->getParent()==nullptr){
        // I dont know..may be it is good to keep this :(
    }
    else{
        ScopeTable* toDelete = current_scopetable;
        current_scopetable=current_scopetable->getParent();
        delete toDelete;
        // May be Done...Not sure
    }
}

bool SymbolTable::Insert(string name,string type){

}