#include <bits/stdc++.h>
using namespace std;
 
class symbolInfo
{
private:
    string name;
    string type;
    symbolInfo* next;
public:

    symbolInfo (string name,string type){
        this->name= name;
        this->type=type;
        next = new symbolInfo();
    }
    symbolInfo (string name,string type,symbolInfo* next){
        this->name= name;
        this->type=type;
        this->next = next;
    }
    symbolInfo (){
        next = new symbolInfo();
    }
    string getName(){
            return name; 
        }
    string getType(){
            return type; 
        }
    
    symbolInfo* getNext(){
        return next; 
    }
    
    void setName(string name){
        this->name=name;
    }
    void setType(string type){
        this->type=type;
    }

};  