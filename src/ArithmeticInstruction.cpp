#include "ArithmeticInstruction.h"
#include "CPU.h"
#include <iostream>
#include <cstdlib>

using namespace std;

ArithmeticInstruction::ArithmeticInstruction(string op, string op1, string op2){
    opcode = op;
    operand1 = op1;
    operand2 = op2;
}

int ArithmeticInstruction::getValue(CPU& cpu, string operand){
    if (isRegister(operand)){
        return cpu.getRegisterValue(getRegisterIndex(operand));
    }

    return atoi(operand.c_str());
}

void ArithmeticInstruction::execute(CPU& cpu){
    int dest = getRegisterIndex(operand1);
    int left = cpu.getRegisterValue(dest);
    int result = left;

    if (opcode == "ADD"){
        result = left + getValue(cpu, operand2);
    }
    else if(opcode == "SUB"){
        result = left - getValue(cpu, operand2);
    }
    else if(opcode == "MUL"){
        result = left * getValue(cpu, operand2);
    }
    else if(opcode == "DIV"){
        int right = getValue(cpu, operand2);
        if(right == 0){
            cout << "Error: Division by zero." << endl;
            return;
        }
        result = left / right;
    }
    else if(opcode == "INC"){
        result = left + 1;
    }
    else if(opcode == "DEC"){
        result = left - 1;
    }
    
    updateFlags(cpu, result);
    cpu.setRegisterValue(dest, result);
}