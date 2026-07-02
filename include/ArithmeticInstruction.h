#ifndef ARITHMETICINSTRUCTION_H
#define ARITHMETICINSTRUCTION_H

#include "Instruction.h"
#include <string>

class CPU;

using namespace std;

class ArithmeticInstruction : public Instruction{
    private:
        string opcode;
        string operand1;
        string operand2;  

        int getRegisterIndex(string reg);
        bool isRegister(string text);
        int getValue(CPU& cpu, string operand);

    public:
        ArithmeticInstruction(string op, string op1, string op2 = " ");
        void execute(CPU& cpu);

};

#endif