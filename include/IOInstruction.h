#ifndef IOINSTRUCTION_H
#define IOINSTRUCTION_H
#include "CPU.h"
#include "Instruction.h"
#include <string>

using namespace std;



/*=========================================================
Class: IOInstruction
Author: Aleessa Batrisyia Binti Azwan 
=========================================================*/

class IOInstruction : public Instruction{
    private:
        string opcode;
        string operand1;

    public:
        IOInstruction(string op, string op1);
        void execute(CPU& cpu);
};

#endif