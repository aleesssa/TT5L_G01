#include "MovInstruction.h"
#include "CPU.h"
#include <cstdlib>

using namespace std;

MovInstruction::MovInstruction(string op, string op1, string op2){
    opcode = op;
    operand1 = op1;
    operand2 = op2;
}

int MovInstruction::getAddressFromBracket(string text){
    string numberText = text.substr(1, text.length() - 2);
    return atoi(numberText.c_str());
}

void MovInstruction::execute(CPU& cpu){
    int dest = getRegisterIndex(operand1);
    int value = 0;

    if(isRegister(operand2)){
        int src = getRegisterIndex(operand2);
        value = cpu.getRegisterValue(src);
    }
    else if(isMemoryRegister(operand2)){
        int srcReg = operand2[2] - '0';
        int address = cpu.getRegisterValue(srcReg);
        value = cpu.readMemory(address);
    }
    else if(isMemoryAddress(operand2)){
        int address = getAddressFromBracket(operand2);
        value = cpu.readMemory(address);
    }
    else{
        value = atoi(operand2.c_str());
    }

    updateFlags(cpu, value);
    cpu.setRegisterValue(dest, value);
}