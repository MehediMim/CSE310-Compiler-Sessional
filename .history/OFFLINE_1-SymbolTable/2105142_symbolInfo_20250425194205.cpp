#ifndef SYMBOLINFO_H
#define SYMBOLINFO_H

#include <bits/stdc++.h>
using namespace std;
 
class SymbolInfo
{
private:
    string name;
    string type;
    SymbolInfo* next;
public:

    SymbolInfo (string name,string type){
        this->name= name;
        this->type=type;
        next = nullptr;
    }
    // SymbolInfo (string name,string type,SymbolInfo* next){
    //     this->name= name;
    //     this->type=type;
    //     this->next = next;
    // }
    SymbolInfo (){
        next = nullptr;
    }
    ~SymbolInfo() {
        if (next != nullptr) {
            delete next;
            next = nullptr;
        }
    }

    string getName(){
        return name; 
    }

    string getType(){
        return type; 
    }
    
    SymbolInfo* getNext(){
        return next; 
    }

    void setNext(SymbolInfo *next){
        this->next=next;
    }

    void setName(string name){
        this->name=name;
    }

    void setType(string type){
        this->type=type;
    }

};  

// int main(){
//     SymbolInfo *si = new SymbolInfo("a","INT");
//     cout << si->getName() << " " << si->getType() << endl;
//     si->setName("b");
//     si->setType("FLOAT");
//     cout << si->getName() << " " << si->getType() << endl;
//     SymbolInfo *si2 = new SymbolInfo("c","DOUBLE");
//     si->setNext(si2);
//     SymbolInfo *si3 = new SymbolInfo("d","DOUBLE");
//     si2->setNext(si3);
//     cout << si->getNext()->getName() << " " << si->getNext()->getType() << endl;
//     cout << si->getNext()->getNext()->getName() << " " << si->getNext()->getNext()->getType() << endl;

// }
#endif
