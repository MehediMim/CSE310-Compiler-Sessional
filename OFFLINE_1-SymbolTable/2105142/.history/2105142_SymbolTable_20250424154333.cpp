#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

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
        this->num_buckets=num_buckets;
        current_scopetable= new ScopeTable(num_buckets,nullptr);
        // current_scopetable->setParent(nullptr); 
        // Creating a new hashTable with null parent
    }

    SymbolTable::~SymbolTable() {
        while (current_scopetable != nullptr) {
            ScopeTable* temp = current_scopetable;
            current_scopetable = current_scopetable->getParent();
            delete temp;
        }
    }
    


    void EnterScope();
    void ExitScope();
    bool Insert(string name,string type);
    bool Remove(string name);
    SymbolInfo* LookUp(string name);
    void PrintCurrentScopeTable();
    void PrintAllScopeTable();
    
};

void SymbolTable::EnterScope(){
    // cout<<current_scopetable->getnum_buckets()<<" "<<this->num_buckets<<endl;
    ScopeTable* newScopeTable = new ScopeTable(this->num_buckets,current_scopetable);
    current_scopetable=newScopeTable;
    // cout<<current_scopetable->getnum_buckets()<<endl;
    
    // newScopeTable->setParent(current_scopetable);
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
    return current_scopetable->Insert(name,type);
}
bool SymbolTable::Remove(string name){
    return current_scopetable->Delete(name);
}

SymbolInfo* SymbolTable::LookUp(string name){
    SymbolInfo* currentLookUp= current_scopetable->LookUp(name);
    ScopeTable* iterate=current_scopetable;
    if(currentLookUp!=nullptr){
        return currentLookUp;
    }
    else {
        while(1){
            iterate=iterate->getParent();
            if(iterate==nullptr){
                cout<<'\t'<<"'"<<name<<"' not found in any of the ScopeTables"<<endl;
                return nullptr;
            }
            else{
                SymbolInfo* x=iterate->LookUp(name);
                if(x!=nullptr){
                    return x;
                }
            }
        }
    }
}

void SymbolTable::PrintCurrentScopeTable(){
    current_scopetable->Print(0);
}

void SymbolTable::PrintAllScopeTable(){
    ScopeTable* iterate=current_scopetable;
    int i=0;
    while(iterate!=nullptr){
        iterate->Print(i);
        iterate=iterate->getParent();
        i++;
    }
}

#endif