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

uint32_t MurmurHash3(string key, uint32_t seed, uint32_t num_buckets) {
    uint32_t hash = seed;
    for (char c : key) {
        hash ^= c;
        hash *= 0x5bd1e995;
        hash ^= hash >> 15;
    }
    return hash % num_buckets;
}



#endif
