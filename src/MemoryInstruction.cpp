#include "MemoryInstruction.h"
#include "CPU.h"
#include <cstdlib>

using namespace std;

MemoryInstruction::MemoryInstruction(string op, string op1, string op2){
    opcode = op;
    operand1 = op1;
    operand2 = op2;
}

int MemoryInstruciton::getAddress(CPU& cpu, string operand){
    if(isMemoryRegister(operand)){
        int reg = operand[2] - '0';
        return cpu.getRegister(reg);
    }

    if(isMemoryAddress(operand)){
        string numberText = operand.substr(1, operand.length() - 2);
        return atoi(numberText.c_str());
    }
}

