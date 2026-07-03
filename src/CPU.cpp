#include "CPU.h"
#include <iostream>
using namespace std;

/*=========================================================
Implementation: CPU
Author: QAISARAH
=========================================================*/

CPU::CPU()
{
    registers[0] = GeneralRegister("R0");
    registers[1] = GeneralRegister("R1");
    registers[2] = GeneralRegister("R2");
    registers[3] = GeneralRegister("R3");
    registers[4] = GeneralRegister("R4");
    registers[5] = GeneralRegister("R5");
    registers[6] = GeneralRegister("R6");
    registers[7] = GeneralRegister("R7");

    PC = 0;
}

void CPU::setRegisterValue(int index, signed char value)
{
    if(index < 0 || index >= 8)
    {
        cout<<"Invalid register\n";
        return;
    }
    registers[index].setValue(value);
}

signed char CPU::getRegisterValue(int index) const
{
    if(index < 0 || index >= 8)
    {
        cout<<"Invalid register\n";
        return 0;
    }
    return registers[index].getValue();
}

void CPU::writeMemory(int address, signed char value)
{
    if(address < 0 || address >= 64)
    {
        cout << "Invalid memory address\n";
        return;
    }
    memory.write(address, value);
}

signed char CPU::readMemory(int address)
{
    if(address < 0 || address >= 64)
    {
        cout << "Invalid memory address\n";
        return 0;
    }
    return memory.read(address);
}

void CPU::pushStack(signed char value)
{
    stack.push(value);
}

signed char CPU::popStack()
{
    return stack.pop();
}

void CPU::setZeroFlag(bool value)
{
    flags.setZero(value);
}

bool CPU::getZeroFlag() const
{
    return flags.getZero();
}

void CPU::setCarryFlag(bool value)
{
    flags.setCarry(value);
}

bool CPU::getCarryFlag() const
{
    return flags.getCarry();
}

void CPU::setOverflowFlag(bool value)
{
    flags.setOverflow(value);
}

bool CPU::getOverflowFlag() const
{
    return flags.getOverflow();
}

void CPU::setUnderflowFlag(bool value)
{
    flags.setUnderflow(value);
}

bool CPU::getUnderflowFlag() const
{
    return flags.getUnderflow();
}

int CPU::getPC() const
{
    return PC;
}

void CPU::incrementPC()
{
    PC++;
}

int CPU::getSI() const
{
    return stack.getTop() + 1;
}

void CPU::reset()
{
    PC = 0;
    memory.clear();
    flags.reset();

    while(!stack.isEmpty())
    {
        stack.pop();
    }

    for(int i = 0; i < 8; i++)
    {
        registers[i].setValue(0);
    }
}
