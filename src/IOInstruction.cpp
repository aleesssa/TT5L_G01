#include "IOInstruction.h"
#include "CPU.h"
#include <iostream>

using namespace std;

IOInstruction::IOInstruction(string op, string op1){
    opcode = op;
    operand1 = op1;
}

void IOInstruction::execute(CPU& cpu){
    int reg = getRegisterIndex(operand1);

    if(opcode == "INPUT"){
        int value;

        cout << "? ";
        cin >> value;

        cpu.updateFlags(value);
        cpu.setRegister(reg, value);
    }
    else if(opcode == "DISPLAY"){
        cout << cpu.getRegister(reg) << endl;
    }
}