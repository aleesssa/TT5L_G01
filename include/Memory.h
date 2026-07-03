#ifndef MEMORY_H
#define MEMORY_H

/*=========================================================
Class: Memory
Author: QAISARAH
=========================================================*/
class Memory
{
private:
    signed char mem[64];

public:
    Memory();
    void clear();
    signed char read(int address);
    void write(int address, signed char value);
};

#endif
