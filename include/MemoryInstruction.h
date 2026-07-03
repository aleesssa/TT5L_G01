#ifndef MEMORYINSTRUCTION_H
#define MEMORYINSTRUCTION_H
#include "Instruction.h"
#include <string>
using namespace std;


/*=========================================================
Class: MemoryInstruction
Author: Aleessa Batrisyia Binti Azwan 
=========================================================*/

class MemoryInstruction : public Instruction{
    private:
        string opcode;
        string operand1;
        string operand2;
    
        int getAddress(CPU& cpu, string operand);

    public:
        MemoryInstruction(string op, string op1, string op2);
        void execute(CPU& cpu);
};

#endif