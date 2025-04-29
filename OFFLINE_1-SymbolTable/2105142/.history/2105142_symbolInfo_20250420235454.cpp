#include <bits/stdc++.h>
using namespace std;
 
class symbolInfo
{
private:
    string name;
    string type;
    symbolInfo* next;
public:
    string getName() {
         return name; 
        }
    string getType() {
         return type; 
        }
};  