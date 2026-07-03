#ifndef movinstruction_h
#define movinstruction_h

#include "Instruction.h"
#include <string>
using namespace std;


/*=========================================================
Class: MovInstruction
Author: Aleessa Batrisyia Binti Azwan 
=========================================================*/

class MovInstruction : public Instruction{
    private:
        string opcode;
        string operand1;
        string operand2;

        int getAddressFromBracket(string text);

    public:
        MovInstruction(string op, string op1, string op2);
        void execute(CPU& cpu);

};


#endif