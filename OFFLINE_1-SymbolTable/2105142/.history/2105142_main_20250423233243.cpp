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
    // cin.ignore();
    // string line;
    // while(1){
    //     getline(cin,line);
    //     // if (line.empty()) continue; 
    //     cout<<countWords(line.c_str())<<endl;
    // }
}