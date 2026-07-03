#include "IOInstruction.h"
#include "CPU.h"
#include <iostream>

using namespace std;

/*=========================================================
Implementation: IOInstruction
Author: Aleessa Batrisyia Binti Azwan 
=========================================================*/

IOInstruction::IOInstruction(string op, string op1){
    opcode = op;
    operand1 = op1;
}

void IOInstruction::execute(CPU& cpu){
    int reg = getRegisterIndex(operand1);

    if(opcode == "INPUT"){
        int value;

        cout << "? ";
        cin >> value; // Get value from user

        updateFlags(cpu, value); // update flags because register is modified
        cpu.setRegisterValue(reg, value);
    }
    else if(opcode == "DISPLAY"){
        cout << cpu.getRegisterValue(reg) << endl; // display value at register
    }
}