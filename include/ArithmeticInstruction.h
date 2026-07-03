#ifndef ARITHMETICINSTRUCTION_H
#define ARITHMETICINSTRUCTION_H

#include "Instruction.h"
#include <string>

class CPU;

using namespace std;

/*=========================================================
Class: ArithmeticInstruction
Author: Aleessa Batrisyia Binti Azwan 
=========================================================*/

class ArithmeticInstruction : public Instruction{
    private:
        string opcode;
        string operand1;
        string operand2;  
        
        int getValue(CPU& cpu, string operand); // get the value stored in register if operand is a register

    public:
        ArithmeticInstruction(string op, string op1, string op2 = " ");
        void execute(CPU& cpu);

};

#endif