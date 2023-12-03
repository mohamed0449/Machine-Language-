

#include <bits/stdc++.h>
using namespace std;
#ifndef A2_TASK3_S11_20220449_20220214_20220472_MEMORY_H
#define A2_TASK3_S11_20220449_20220214_20220472_MEMORY_H

class Memory{
    string AMemory[16][16];

public:
    Memory();
    void setMemory(string position,string value);
    string getMemory(string position);
    void printMemory();
};


#endif
