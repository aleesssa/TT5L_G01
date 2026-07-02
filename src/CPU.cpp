#include "CPU.h"

CPU::CPU()
{
    reg[0] = GeneralRegister("R0");
    reg[1] = GeneralRegister("R1");
    reg[2] = GeneralRegister("R2");
    reg[3] = GeneralRegister("R3");
    reg[4] = GeneralRegister("R4");
    reg[5] = GeneralRegister("R5");
    reg[6] = GeneralRegister("R6");
    reg[7] = GeneralRegister("R7");

    PC = 0;
    SI = 0;
}

GeneralRegister& CPU::getRegister(int i)
{
    return reg[i];
}

Memory& CPU::getMemory()
{
    return memory;
}

Stack& CPU::getStack()
{
    return stack;
}

FlagRegister& CPU::getFlags()
{
    return flags;
}

int CPU::getPC()
{
    return PC;
}

void CPU::incrementPC()
{
    PC++;
}

int CPU::getSI()
{
    return SI;
}

void CPU::setSI(int value)
{
    SI = value;
}
