#ifndef MEMORY_H
#define MEMORY_H

/*=========================================================
Class: Memory
Author: QAISARAH SHAMSUL AZRAN
=========================================================*/
class Memory
{
private:
    signed char mem[64];    //an array with 64 space is created

public:
    Memory();
    void clear();
    signed char read(int address);
    void write(int address, signed char value);
};

#endif
