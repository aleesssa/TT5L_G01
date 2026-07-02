#include "StackInstruction.h"
#include "CPU.h"

using namespace std;

StackInstruction::StackInstruction(string op, string op1){
    opcode = op;
    operand1 = op1;
}

void StackInstruction::execute(CPU& cpu){
    int reg = getRegisterIndex(operand1);

    if(opcode == "PUSH"){
        int value = cpu.getRegister(reg);
        cpu.pushStack(value);
    }
    else if(opcode == "POP"){
        int value = cpu.popStack();
        cpu.setRegister(reg, value);
        cpu.updateFlags(value);
    }
}

