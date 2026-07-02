#ifndef CPU_H
#define CPU_H

#include "GeneralRegister.h"
#include "Memory.h"
#include "Stack.h"
#include "FlagRegister.h"

class CPU
{
private:
    GeneralRegister reg[8];
    Memory memory;
    Stack stack;
    FlagRegister flags;
    unsigned char PC;
    unsigned char SI;

public:
    CPU();
    GeneralRegister& getRegister(int i);
    Memory& getMemory();
    Stack& getStack();
    FlagRegister& getFlags();
    int getPC();
    void incrementPC();
    int getSI();
    void setSI(int value);
};

#endif
