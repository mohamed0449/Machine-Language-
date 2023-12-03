#include <bits/stdc++.h>
#include "Memory.h"
using namespace std;

Memory::Memory(){
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {
            AMemory[i][j] = "00";
        }
    }
}


void Memory::setMemory(string position, string value){
    int firstDM=position[0]-'0',secondDM=position[1]-'0';

    if(isalpha(position[0])){
        firstDM=position[0] - 55;
    }
    if(isalpha(position[1]))
        secondDM=position[1] - 55;
    AMemory[firstDM][secondDM] = value;
};


string Memory::getMemory(string position){
    int firstDM=position[0]-'0',secondDM=position[1]-'0';

    if(isalpha(position[0])){
        firstDM=position[0] - 55;
    }
    if(isalpha(position[1]))
        secondDM=position[1] - 55;
    return AMemory[firstDM][secondDM];
};

void Memory::printMemory(){
    cout << endl;
    cout << "  ";
    for (int i = 0; i < 16; ++i) {
        if(i > 9){
            cout << char(65 + i - 10) <<"  ";
        }else
            cout << i <<"  ";
    }
    cout <<endl;
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {
            if(j==0){
                if(i > 9){
                    cout << char ('A' + i - 10) <<" ";
                }else
                    cout << i <<" ";
            }
            cout << AMemory[i][j] << " ";
        }
        cout << endl;
    }
};