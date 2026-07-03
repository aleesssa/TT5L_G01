#ifndef CPU_H
#define CPU_H

#include "GeneralRegister.h"
#include "Memory.h"
#include "Stack.h"
#include "FlagRegister.h"

/*=========================================================
Class: CPU
Author: QAISARAH
=========================================================*/

class CPU
{
private:
    GeneralRegister registers[8];
    Memory memory;
    Stack stack;
    FlagRegister flags;
    unsigned char PC;

public:
    CPU();

    void setRegisterValue(int index, signed char value);
    signed char getRegisterValue(int index) const;

    void writeMemory(int address, signed char value);
    signed char readMemory(int address);

    void pushStack(signed char value);
    signed char popStack();

    void setZeroFlag(bool value);
    bool getZeroFlag() const;

    void setCarryFlag(bool value);
    bool getCarryFlag() const;

    void setOverflowFlag(bool value);
    bool getOverflowFlag() const;

    void setUnderflowFlag(bool value);
    bool getUnderflowFlag() const;

    int getPC() const;
    void incrementPC();

    int getSI() const;

    void reset();
};

#endif
