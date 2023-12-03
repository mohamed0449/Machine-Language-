#ifndef A2_TASK3_S11_20220449_20220214_20220472_REGISTER_H
#define A2_TASK3_S11_20220449_20220214_20220472_REGISTER_H
#include <bits/stdc++.h>
#include "Memory.h"

using namespace std;

class Register:public Memory{
    string ARegister [16];

public:
    Register();
    void setRegister(char position,string value);
    string getRegister(char position);
    void printRegister();
};

#endif
