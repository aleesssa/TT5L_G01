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