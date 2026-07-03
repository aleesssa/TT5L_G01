#ifndef INSTRUCTION_H
#define INSTRUCTION_H
#include <string>
#include "CPU.h"


/*=========================================================
Class: Instruction (Abstract base class)
Author: Aleessa Batrisyia Binti Azwan 
=========================================================*/

class Instruction{
    protected:
        int getRegisterIndex(string reg); // get the register index without the R
        bool isRegister(string text); // verify if operand is a register
        bool isMemoryRegister(string text); // verify if operand is memory register
        bool isMemoryAddress(string text); // verify if operand is memory address
        void updateFlags(CPU& cpu, int result); // update flags for when destination register is modified


    public:
        virtual void execute(CPU& cpu) = 0;
        virtual ~Instruction(){}
};

#endif