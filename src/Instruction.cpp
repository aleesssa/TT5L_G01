#include "Instruction.h"

int Instruction::getRegisterIndex(string reg){
    return reg[1] - '0';
}

bool Instruction::isRegister(string text){
    return text.length() == 2 &&
        text[0] == 'R' &&
        text[1] >= '0' &&
        text[1] <= '7';
}

bool Instruction::isMemoryRegister(string text){
    return text.length() == 4 &&
           text[0] == '[' &&
           text[1] == 'R' &&
           text[2] >= '0' &&
           text[2] <= '7' &&
           text[3] == ']';
}


bool Instruction::isMemoryAddress(string text){
    return text.length() >= 3 &&
           text[0] == '[' &&
           text[text.length() - 1] == ']';
}

void Instruction::updateFlags(CPU& cpu, int result) {
    cpu.setOverflowFlag(result > 127);
    cpu.setUnderflowFlag(result < -128);
    cpu.setCarryFlag(result > 255 || result < -255);
    cpu.setZeroFlag(result == 0);
}