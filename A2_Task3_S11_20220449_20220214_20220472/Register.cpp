#include <bits/stdc++.h>
#include "Register.h"
using namespace std;

Register::Register(){
    for (int i = 0; i < 16; ++i) {
        ARegister[i] = "00";
    }
}


void Register::setRegister(char position, string value){
    int index=position-'0';

    if(isalpha(position)){
        index=position - 55;
    }
    ARegister[index] = value;
};


string Register::getRegister(char position){
    int index=position-'0';

    if(isalpha(position)){
        index=position - 55;
    }
    return ARegister[index];
};


void Register::printRegister(){
    cout << endl;

    for (int i = 0; i < 16; ++i) {
        cout << "R";
        if(i > 9){
            cout << char ('A' + i - 10) <<" ";
        }else
            cout << i <<" ";
        cout << ARegister[i];
        cout << endl;
    }
};