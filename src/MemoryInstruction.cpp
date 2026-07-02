#include "MemoryInstruction.h"
#include "CPU.h"
#include <cstdlib>

using namespace std;

MemoryInstruction::MemoryInstruction(string op, string op1, string op2){
    opcode = op;
    operand1 = op1;
    operand2 = op2;
}

int MemoryInstruction::getAddress(CPU& cpu, string operand){
    if(isMemoryRegister(operand)){
        int reg = operand[2] - '0';
        return cpu.getRegisterValue(reg);
    }

    if(isMemoryAddress(operand)){
        string numberText = operand.substr(1, operand.length() - 2);
        return atoi(numberText.c_str());
    }

    return atoi(operand.c_str());
}

void MemoryInstruction::execute(CPU& cpu){
    if(opcode == "LOAD"){
        int dest = getRegisterIndex(operand1);
        int address = getAddress(cpu, operand2);

        int value = cpu.readMemory(address);

        cpu.setRegisterValue(dest, value);
        updateFlags(cpu, value);
    }
    else if(opcode == "STORE"){
        int value;
        int address;

        if(isRegister(operand1)){
            value = cpu.getRegisterValue(getRegisterIndex(operand1));
            address = getAddress(cpu, operand2);
        }

        cpu.writeMemory(address, value);
    }
}
