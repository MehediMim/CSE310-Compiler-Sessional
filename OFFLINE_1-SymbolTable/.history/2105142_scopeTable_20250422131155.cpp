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
    ScopeTable(ScopeTable* parent){
        this->parent=parent;
    }

    ScopeTable(int num_buckets){
        this->parent=parent;
        symbolinfoList= new SymbolInfo*[num_buckets]();
    }

    int getscopetableNumber(){
        return scopetableNumber;
    }

    int getnum_buckets(){
        return num_buckets;
    }

    bool Insert(string name,string type){
        int idx=SDBMHash(name,num_buckets);
        if(symbolinfoList[idx]==nullptr){
            cout<<"Inserted"<<endl;
            symbolinfoList[idx]=new SymbolInfo(name,type);
            return true;
        }
        else {
            SymbolInfo* curr=symbolinfoList[idx];
            while(curr->getNext()!=nullptr){
                if(curr->getName()==name){
                    cout<<"already exists"<<endl;
                    return false;
                }
                curr= curr->getNext();
            }
            SymbolInfo *temp = new SymbolInfo(name,type);
            curr->setNext(temp);
            cout<<"New Element inserted"<<endl;
        }

    }

    SymbolInfo* LookUp(string name){
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

    bool Delete(string name){
        int idx = SDBMHash(name,num_buckets);
        if(symbolinfoList[idx]==nullptr){     //Nothing in this address
            cout<<"Nothing to delete"<<endl;
            return false;
        }
        if(symbolinfoList[idx]->getName()==name){ //Found in the first element
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

    void Print(){
        for(int i=0;i<num_buckets;i++){
            cout<<"address: "<<i;
            SymbolInfo* iterate = symbolinfoList[i];
            while(iterate!=nullptr){
                cout <<" <"<<iterate->getName()<<","<<iterate->getType()<<"> ";
            }
            cout<<endl;
        }
    }



};

