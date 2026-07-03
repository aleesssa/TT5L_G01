#ifndef SHIFTINSTRUCTION_H
#define SHIFTINSTRUCTION_H

#include <string>
#include "Instruction.h"

using namespace std;

/*=========================================================
Class: ShiftInstruction
Author: NUR DAMIA' BATRISYIA
=========================================================*/

class ShiftInstruction : public Instruction
{
private:
    string operation; // SHL, SHR, ROL, ROR
    string destination; // Register name (R0...)
    string count;

public:
    ShiftInstruction(string op, string dest, string c);

    void execute(CPU& cpu) override;
};

#endif