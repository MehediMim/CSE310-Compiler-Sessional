#include <bits/stdc++.h>
using namespace std;

#include "2105142_SymbolTable.cpp"
 
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



int main()
{
    int num_buckets;
    cout <<"num_buckets_ ";
    cin >> num_buckets;
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
        for(int j=0;j<i;j++){
            cout<<arr[j]<<" "<<endl;
        }
        cout<<endl;

        if(arr->empty() or arr[0].empty()){
            break;
        }

        else if(arr[0]=="I"){
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
            cout<<"<"<<symbolName<<","<<symbolType<<">"<<endl;

        }
        else if(arr[0]=="L"){}
        else if(arr[0]=="D"){}
        else if(arr[0]=="S"){}
        else if(arr[0]=="E"){}
        else if(arr[0]=="Q"){}
    }
}