#include "Memory.h"

Memory::Memory()
{
    clear();
}

void Memory::clear()
{
    for(int i = 0; i < 64; i++)
    {
        mem[i] = 0;
    }
}

signed char Memory::read(int address)
{
    return mem[address];
}

void Memory::write(int address, signed char value)
{
    mem[address] = value;
}
