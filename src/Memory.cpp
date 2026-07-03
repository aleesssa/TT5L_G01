#include "../include/Memory.h"
#include <iostream>
using namespace std;

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
    if(address < 0 || address >= 64)
    {
        cout << "Invalid memory address\n";
        return 0;
    }
    return mem[address];
}

void Memory::write(int address, signed char value)
{
    if(address < 0 || address >= 64)
    {
        cout << "Invalid memory address\n";
        return;
    }
    mem[address] = value;
}
