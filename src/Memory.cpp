#include "../include/Memory.h"
#include <iostream>
using namespace std;

/*=========================================================
Implementation: Memory
Author: QAISARAH SHAMSUL AZRAN
=========================================================*/
Memory::Memory()
{
    clear();    //whenever the memory is initialized, it is cleared
}

void Memory::clear()
{
    for(int i = 0; i < 64; i++)
    {
        mem[i] = 0; //set to 0 for all memory address
    }
}

signed char Memory::read(int address)
{
    if(address < 0 || address >= 64)
    {
        cout << "Invalid memory address\n"; //give error message if the given memory address is < 0 or >= 64 which is the max number of addresses
        return 0;
    }
    return mem[address];    //return the value at the address aka index
}

void Memory::write(int address, signed char value)
{
    if(address < 0 || address >= 64)
    {
        cout << "Invalid memory address\n"; //give error message if the given memory address is < 0 or >= 64 which is the max number of addresses
        return;
    }
    mem[address] = value;   //assign the given value to the address aka the index position in the array
}