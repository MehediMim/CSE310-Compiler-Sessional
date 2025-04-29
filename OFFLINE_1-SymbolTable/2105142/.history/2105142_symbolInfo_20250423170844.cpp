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
    SymbolInfo (string name,string type,SymbolInfo* next){
        this->name= name;
        this->type=type;
        this->next = next;
    }
    SymbolInfo (){
        next = nullptr;
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