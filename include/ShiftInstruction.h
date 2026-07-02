#ifndef SHIFTINSTRUCTION_H
#define SHIFTINSTRUCTION_H

#include <string>
#include "Instruction.h"

using namespace std;

class ShiftInstruction : public Instruction
{
private:
    string operation; // SHL, SHR, ROL, ROR
    string destination; // Register name (R0...)

public:
    ShiftInstruction(string op, string dest) : operation(op), destination(dest) {}

    void execute(CPU& cpu);
};

#endif