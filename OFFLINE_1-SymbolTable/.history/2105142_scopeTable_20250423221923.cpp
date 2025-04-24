#ifndef SCOPETABLE_H
#define SCOPETABLE_H


#include <bits/stdc++.h>
#include "2105142_symbolInfo.cpp"

using namespace std;
class ScopeTable
{
private:
    int scopetableNumber;
    int num_buckets;
    ScopeTable* parent;
    SymbolInfo** symbolinfoList;

    unsigned int SDBMHash ( string str , unsigned int num_buckets ) {
        unsigned int hash = 0;
        unsigned int len = str. length ();
        for ( unsigned int i = 0; i < len ; i ++){
            hash = (( str[i]) + ( hash << 6) + ( hash << 16) - hash ) %
            num_buckets ;
        }
        return hash ;
    }


public:

    ScopeTable(int num_buckets,ScopeTable* parent){
        this->num_buckets=num_buckets;
        this->parent=parent;
        symbolinfoList= new SymbolInfo*[num_buckets]();
        if(parent==nullptr){
            scopetableNumber=1;
        }
        else{
            scopetableNumber=parent->getscopetableNumber()+1;
        }
    }


    ScopeTable* getParent();
    void setParent(ScopeTable* parent);
    int getscopetableNumber();
    // void setscopetableNumber(int scopetableNumber);
    int getnum_buckets();
    // void setnum_buckets(int num_buckets);
    bool Insert(string name,string type);
    SymbolInfo* LookUp(string name);
    bool Delete(string name);
    void Print();



};

ScopeTable* ScopeTable::getParent(){
    return this->parent;
}
void ScopeTable::setParent(ScopeTable* parent){
    this->parent= parent;
}
int ScopeTable::getscopetableNumber(){
    return scopetableNumber;
}
// void ScopeTable::setscopetableNumber(int scopetableNumber){
    // this->scopetableNumber=scopetableNumber;
// }
int ScopeTable::getnum_buckets(){
    return num_buckets;
}
// void ScopeTable::setnum_buckets(int num_buckets){
    // this->num_buckets=num_buckets;
// }
bool ScopeTable::Insert(string name,string type){
    int idx=SDBMHash(name,num_buckets);
    if(symbolinfoList[idx]==nullptr){
        cout<<"Inserted in new address : "<<idx<<endl;
        symbolinfoList[idx]=new SymbolInfo(name,type);
        return true;
    }
    else {
        SymbolInfo* curr=symbolinfoList[idx];
        while(curr->getNext()!=nullptr){
            if(curr->getName()==name){
                cout<<"This already exists"<<endl;
                return false;
            }
            curr= curr->getNext();
        }
        SymbolInfo *temp = new SymbolInfo(name,type);
        curr->setNext(temp);
        cout<<"New Element inserted at:  "<<idx<<endl;
    }

}
SymbolInfo* ScopeTable::LookUp(string name){
    int idx = SDBMHash(name,num_buckets);
    if(symbolinfoList[idx]==nullptr){
        cout<<"Doesnot Exists"<<endl;
        return nullptr;
    }
    SymbolInfo *curr = symbolinfoList[idx];
    while(curr->getNext()!=nullptr){
        if(curr->getName()==name){
            cout<<"FOUND"<<endl;
            return curr;
        }
        curr=curr->getNext();
    }
    cout<<"Nah man I couldnot find"<<endl;
    return nullptr;

}
bool ScopeTable::Delete(string name){
    int idx = SDBMHash(name,num_buckets);
    if(symbolinfoList[idx]==nullptr){     
        //Nothing in this address
        cout<<"Nothing to delete"<<endl;
        return false;
    }
    if(symbolinfoList[idx]->getName()==name){ 
        //Found in the first element
        cout<<"First one"<<endl;
        SymbolInfo *toDelete = symbolinfoList[idx];
        symbolinfoList[idx]=symbolinfoList[idx]->getNext();
        delete toDelete;
        toDelete = nullptr;
        cout <<"Deleted"<<endl;
        return true;
    }
    if(symbolinfoList[idx]->getNext()==nullptr){
        cout <<"Couldnot Find"<<endl;
        return false;
    }
    else{
        SymbolInfo* parent =symbolinfoList[idx];
        SymbolInfo* curr =symbolinfoList[idx]->getNext();
        while(curr->getNext()!=nullptr){
            if(curr->getName()==name){
                cout<<"Found"<<endl;
                parent->setNext(curr->getNext());
                SymbolInfo* toDelete = curr;
                delete toDelete;
                toDelete = nullptr;
                cout<<"Deleted"<<endl;
                return true;
            }
            parent= curr;
            curr=curr->getNext();
        }
        
        
    }
}
void ScopeTable::Print(){
    // cout<<"called158..."<<endl;
    for(int i=0;i<num_buckets;i++){
        cout<<"address: "<<i;
        SymbolInfo* iterate = symbolinfoList[i];
        while(iterate!=nullptr){
            cout <<" <"<<iterate->getName()<<","<<iterate->getType()<<"> ";
            iterate=iterate->getNext();
        }
        cout<<endl;
    }
}

// int main(){
//     ScopeTable* st = new ScopeTable(10,nullptr);
//     cout<<st->getnum_buckets()<<endl;
//     // cout<<st->getscopetableNumber();
//     st->Insert("a","INT");
//     st->Insert("b","DOUBLE");
//     for(int i=0;i<20;i++){
//         st->Insert(to_string(i+56),"INT");
//     }
//     cout<<st->LookUp("56");
//     st->Delete("56");
//     st->Print();
//     st->LookUp("56");
// }
#endif
