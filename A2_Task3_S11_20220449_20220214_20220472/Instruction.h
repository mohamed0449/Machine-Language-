#include <bits/stdc++.h>
#include "Memory.h"
#include "Register.h"
using namespace std;


#ifndef A2_TASK3_S11_20220449_20220214_20220472_INSTRUCTION_H
#define A2_TASK3_S11_20220449_20220214_20220472_INSTRUCTION_H

class Instruction : public Register{
    string IR;
    int PC;
    bool execute = false;
    vector<string> v;
public:

    Instruction(string instruction);
    Instruction();

    void setInstruction(string instruction);
    void setInstructions(bool all=false);

    void printData();

    void operation_1(string s);
    void operation_2(string s);
    void operation_3(string s);
    void operation_4(string s);
    void operation_5(string s);
    void operation_B(string s);
    void operation_C(string s);


    void pushI();
    void setV(string s);
    string getV();
    string getIR();
    string getPC();

    void fetch(vector<string> instructions);

};


#endif //
