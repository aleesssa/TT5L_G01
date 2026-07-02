#include "ArithmeticInstruction.h"
#include "CPU.h"
#include <iostream>
#include <cstdlib>

using namespace std;

class CPU;

ArithmeticInstruction::ArithmeticInstruction(string op, string op1, string op2){
    opcode = op;
    operand1 = op1;
    operand2 = op2;
}

// Get the register number
int ArithmeticInstruction::getRegisterIndex(string reg){
    return reg[1] - '0';
}

bool ArithmeticInstruction::isRegister(string text){
    return text.length() == 2 &&
        text[0] == 'R' &&
        text[1] >= '0' &&
        text[1] <= '7';
}

int ArithmeticInstruction::getValue(CPU& cpu, string operand){
    if (isRegister(operand)){
        return cpu.getRegister(getRegisterIndex(operand));
    }

    return atoi(operand.c_str());
}

void ArithmeticInstruction::execute(CPU& cpu){
    int dest = getRegisterIndex(operand1);
    int left = cpu.getRegister(dest);
    int result = left;

    if (opcode == "ADD"){
        result = left + getValue(cpu, operand2);
    }
    else if(opcode == "SUB"){
        result = left - getValue(cpu, operand2);
    }
    else if(opcode == "MUL"){
        result = left * getValue(cpu, operand2)
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

    cpu.updateFlags(result);
    cpu.setRegister(dest, result);

}