#include <bits/stdc++.h>
using namespace std;

#include "2105142_SymbolTable.cpp"
#include "2105142_global.cpp"

int tableCounter=1;
 
int countWords(const char* line) {
    if (line == nullptr || strlen(line) == 0) return 0;

    int count = 0;
    char* temp = new char[strlen(line) + 1];
    strcpy(temp, line);

    char* token = strtok(temp, " ");
    while (token != nullptr) {
        count++;
        token = strtok(nullptr, " ");
    }

    delete[] temp;
    return count;
}


/*

\\\\\\\//\//\\\//\/\/\/\/\/\/\DONT FORGET DISTRUCTOR/\/\\/\/\/\/\/\/\/\/\/\/\/\\/

*/
int main()
{
    int num_buckets;
    cout <<"num_buckets_ ";
    cin >> num_buckets;
    SymbolTable* symbolTable = new SymbolTable(num_buckets);
    cin.ignore();
    string line;
    while(1){
        getline(cin,line);

        int tokenSize=countWords(line.c_str());
        string arr[tokenSize];
        char* token = strtok((char*)line.c_str(), " ");
        int i=0;
        while (token != nullptr) {
            arr[i++] = token;
            token = strtok(nullptr, " ");
        }
        // for(int j=0;j<i;j++){
            // cout<<arr[j]<<" "<<endl;
        // }
        // cout<<endl;

        if(arr->empty() or arr[0].empty()){
            break;
        }

        else if(arr[0]=="I"){ //.............................Insert
            //Insert
            string symbolName = arr[1];
            string symbolType = arr[2];
            

            if(symbolType=="FUNCTION"){
                symbolType.append(",");
                symbolType.append(arr[3]);
                symbolType.append("<==(");
                for(int i=4;i<tokenSize-1;i++){
                    symbolType.append(arr[i]);
                    symbolType.append(",");
                }
                symbolType.append(arr[tokenSize-1]);
                symbolType.append(")");
            }

            else if (symbolType=="STRUCT"){
                cout<<"Start"<<endl;
                symbolType.append(",{");
                
                
                
                for(int i=3;i<tokenSize-2;i+=2){
                    symbolType.append("(");
                    symbolType.append(arr[i]);
                    symbolType.append(",");
                    symbolType.append(arr[i+1]);
                    symbolType.append("),");
                }
                
                symbolType.append("(");
                symbolType.append(arr[tokenSize-2]);
                symbolType.append(",");
                symbolType.append(arr[tokenSize-1]);
                symbolType.append(")");
                
                symbolType.append("}");

                cout<<"End"<<endl;
                
            }
            
            
            else if (symbolType=="==" or symbolType=="<=" or symbolType==">=" or symbolType=="!=" ){
            }
            else{
                string symbolName = arr[1];
                string symbolType = arr[2];
            }
            
            cout<<symbolName<<endl;
            cout<<symbolType<<endl;
            symbolTable->Insert(symbolName,symbolType);
            cout<<"End Again"<<endl;


        }
        else if(arr[0]=="L"){ //..........................Look Up
            string symbolName = arr[1];
            // string symbolType = arr[2];

            if(tokenSize>2){
                cout<<"Number of parameters mismatch for the command L"<<endl;
            }
            else {
                // cout<<"Going"<<endl;
                symbolTable->LookUp(symbolName);
            }
        }
        else if(arr[0]=="D"){ //............................Deletion
            if(tokenSize<2){
                cout<<"Number of parameters mismatch for the command D"<<endl;
            }
            symbolTable->Remove(arr[1]);
        }
        else if(arr[0]=="P"){ //............................print
            
            if(arr[1]=="C"){
                symbolTable->PrintCurrentScopeTable();
            }
            if(arr[1]=="A"){
                symbolTable->PrintAllScopeTable();
            }
        }
        else if(arr[0]=="S"){ //.............................Scope change
            // cout<<"HELLLL"<<endl;
            symbolTable->EnterScope();
        }
        else if(arr[0]=="E"){ //.............................Exit Scope
            symbolTable->ExitScope();
        }
        else if(arr[0]=="Q"){}
    }
}