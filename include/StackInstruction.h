#ifndef STACKINSTRUCTION_Hd
#define STACKINSTRUCTION_H

#include "Instruction.h"
#include <string>

using namespace std;

class StackInstruction : public Instruction{
    private:
        string opcode;
        string operand1;
    
    public:
        StackInstruction(string op, string op1);
        void execute(CPU& cpu);
};

#endif