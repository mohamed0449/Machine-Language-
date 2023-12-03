// Mohamed Gomaa Mohamed     20220449 mhmd2004221@gmail.com


#include <bits/stdc++.h>
#include "Memory.h"
#include "Instruction.h"

using namespace std;

int main(){
    Instruction* n;
    n = new Instruction();
    vector<string> inputs;

    string fileName;
    cout << "1-fetch (execute one instruction)\n";
    cout << "2-execute all instructions\n";
    cout << "3-show memory\n";
    cout << "4-show Registers\n";
    cout << "5-clear Data\n";
    cout << "6-Show last instruction(IR) & counter(PC)\n";
    cout << "7-Load from file\n";
    cout << "0-Exit";
    cout<<endl;
    int choise;
    n->fetch(inputs);
    while (cin >>choise){
        switch (choise) {
            case 0:
                return 0;
            case 1:
                n->setInstructions();
                break;
            case 2:
                n->setInstructions(true);
                break;
            case 3:
                n->printMemory();
                break;
            case 4:
                n->printRegister();
                break;
            case 5:{
                Instruction* t =n;
                n = new Instruction();
                delete t;
                inputs.clear();
                break;
            }
            case 6:{
                cout << "IR: "<<n->getIR()<<endl;
                cout << "PC: "<<n->getPC()<<endl;
                break;
            }
            case 7:
                cout << "Enter the file name: ";
                cin >> fileName;
                ifstream f(fileName);
                if(f.is_open()){
                    while (f>>fileName){
                        inputs.push_back(fileName);
                    }
                    n->fetch(inputs);
                }else{
                    cout <<"File is not exist"<<endl;
                }
                break;
        }

        cout << "1-fetch (execute one instruction)\n";
        cout << "2-execute all instructions\n";
        cout << "3-show memory\n";
        cout << "4-show Registers\n";
        cout << "5-clear Data\n";
        cout << "6-Show last instruction(IR) & counter(PC)\n";
        cout << "7-Load from file\n";
        cout << "0-Exit";
        cout<<endl;
    }
    return 0;
}
