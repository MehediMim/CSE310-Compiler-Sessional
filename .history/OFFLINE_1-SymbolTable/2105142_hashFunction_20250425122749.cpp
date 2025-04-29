#ifndef HASHFUNCTION_H
#define HASHFUNCTION_H
#include <bits/stdc++.h>
using namespace std;


unsigned int SDBMHash ( string str , unsigned int num_buckets ) {
    unsigned int hash = 0;
    unsigned int len = str. length ();
    for ( unsigned int i = 0; i < len ; i ++){
        hash = (( str[i]) + ( hash << 6) + ( hash << 16) - hash ) %
        num_buckets ;
    }
    return hash ;
}

unsigned int DJB2Hash(string str, unsigned int num_buckets) {
    unsigned int hash = 5381;
    for (char c : str) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
        hash %= num_buckets;
    }
    return hash;
}

unsigned int LoseLoseHash(string str, unsigned int num_buckets) {
    unsigned int hash = 0;
    for (char c : str) {
        hash += c;
        hash %= num_buckets; 
    }
    return hash;
}


#endif
