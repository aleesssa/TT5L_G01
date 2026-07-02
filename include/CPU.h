#ifndef CPU_H
#define CPU_H

#include "GeneralRegister.h"
#include "Memory.h"
#include "Stack.h"
#include "FlagRegister.h"

class CPU
{
private:

    GeneralRegister registers[8];

    Memory memory;

    Stack stack;

    FlagRegister flags;

    unsigned char PC;
    unsigned char SI;

public:

    CPU();

    void setRegisterValue(int index, signed char value);
    signed char getRegisterValue(int index);

    void writeMemory(int address, signed char value);
    signed char readMemory(int address);

    void pushStack(signed char value);
    signed char popStack();

    void setZeroFlag(bool value);
    bool getZeroFlag();

    void setCarryFlag(bool value);
    bool getCarryFlag();

    void setOverflowFlag(bool value);
    bool getOverflowFlag();

    void setUnderflowFlag(bool value);
    bool getUnderflowFlag();

    void setPC(int value);
    int getPC();
    void incrementPC();

    void setSI(int value);
    int getSI();
};

#endif
