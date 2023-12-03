#include <bits/stdc++.h>
#include "Memory.h"
#include "Instruction.h"
using namespace std;




Instruction::Instruction(string instruction){
    this->setInstruction(instruction);
    this->PC=48;
}


Instruction::Instruction(){
    this->IR="0000";
    this->PC=48;
}

void Instruction::printData(){
    this->printRegister();
    this->printMemory();
}

void Instruction::setInstruction(string instruction) {
    this->IR="0000";
    if(this->execute)
        return;
    this->IR=instruction;

    string s = instruction.substr(1);
    switch (instruction[0]) {
        case '1':
            operation_1(s);
            break;
        case '2':
            operation_2(s);
            break;
        case '3':
            operation_3(s);
            break;
        case '4':
            operation_4(s);
            break;
        case '5':
            operation_5(s);
            break;
        case 'B':
            operation_B(s);
            break;
        case 'C':
            operation_C(s);
            break;
        default:
            cout << "invalid instruction"<<endl;
            break;
    }

}

void Instruction::operation_1(string s){ // 4 01
    this->setRegister(s[0],this->getMemory(s.substr(1)));
}
void Instruction::operation_2(string s){
    this->setRegister(s[0],s.substr(1));
}
void Instruction::operation_3(string s){
    cout << s<<endl;
    this->setMemory(s.substr(1),this->getRegister(s[0]));
    if(s.substr(1) == "00")
        this->printMemory();
}
void Instruction::operation_4(string s){
    this->setRegister(s[2],this->getRegister(s[1]));

}
void Instruction::operation_5(string s){
    string hex1 = this->getRegister(s[1]); //R2
    string hex2 = this->getRegister(s[2]);  //R1

    // Convert hexadecimal strings to decimal integers
    int num1, num2;
    stringstream(hex1) >> hex >> num1;
    stringstream(hex2) >> hex >> num2;
    int sum = num1+num2;
    stringstream resultHexStream;
    resultHexStream << hex << sum;
    string hex = resultHexStream.str();
    char* c = &hex[0];
    while (*c) {
        *c = toupper((char) *c);
        c++;
    }
    if(hex.size()==1){
        hex='0'+hex;
    }
    this->setRegister(s[0] , hex.substr(hex.length()-2));
}
void Instruction::operation_B(string s){
    if(this->getRegister(s[0]) == this->getRegister('0')){
        int num1;
        stringstream(s.substr(1)) >> hex >> num1;
        PC = num1;
        this->setInstructions();
    }
    return;

}
void Instruction::operation_C(string s){
    this->execute= true;
    return;
}


void Instruction::setInstructions(bool all){
    int first = PC++;
    int second = PC++;
    stringstream resultHexStream;
    stringstream resultHexStream2;

    resultHexStream << hex << first;

    resultHexStream2 << hex << second;
    string hex1 = resultHexStream.str();
    string hex2 = resultHexStream2.str();

    if(hex1.size()==1)
        hex1 = '0' + hex1;
    if(hex2.size()==1)
        hex2 = '0' + hex2;

    char* c = &hex1[0];

    while (*c) {
        *c = toupper((char) *c);
        c++;
    }

    c = &hex2[0];

    while (*c) {
        *c = toupper((char) *c);
        c++;
    }
    if(this->getMemory(hex1)=="00"){
        PC = max(0,PC-2);
        return;
    }
    string mem1=this->getMemory(hex1),mem2= getMemory(hex2);
    this->setInstruction(mem1+mem2);

    IR = mem1+mem2;

    if(all)
        setInstructions(all);
};

void Instruction::setV(string s) {
    v.push_back(s);
};
string Instruction::getV() {
    string instruct;
    instruct=v[0];
    v.erase(v.begin());

    return instruct;
}
void Instruction::pushI() {
    string instruct;
    while(v.size()){
        instruct=getV();
        setInstruction(instruct);
    }
}

void Instruction::fetch(vector<string> instructions){
    int s = PC;
    for (auto instruction:instructions) {

        int sum = PC;
        stringstream resultHexStream;
        resultHexStream << hex << sum;
        string hex = resultHexStream.str();
        if(hex.length() ==1)
            hex = '0'+hex;
        char* c = &hex[0];
        while (*c) {
            *c = toupper((char) *c);
            c++;
        }
        this->setMemory(hex,instruction.substr(0,2));
        PC++;

        sum = PC;
        hex="";
        stringstream resultHexStream2;
        resultHexStream2 << std::hex << sum;
        hex = resultHexStream2.str();
        if(hex.length() ==1)
            hex = '0'+hex;
        c = &hex[0];

        while (*c) {
            *c = toupper((char) *c);
            c++;
        }
        this->setMemory(hex,instruction.substr(2,4));
        ++PC;
    }
    PC =s;
}

string Instruction::getPC() {
    stringstream s;
    string pc= to_string(PC);
    s<<hex<<pc;
    string hex = s.str();
    if(hex.length() ==1)
        hex = '0'+hex;
    char* c = &hex[0];

    while (*c) {
        *c = toupper((char) *c);
        c++;
    }
    return hex;
}

string Instruction::getIR() {
    return IR;
}
