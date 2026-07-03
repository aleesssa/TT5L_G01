#include "CPU.h"
#include <iostream>
using namespace std;

/*=========================================================
Implementation: CPU
Author: QAISARAH SHAMSUL AZRAN
=========================================================*/

CPU::CPU()
{
    registers[0] = GeneralRegister("R0");   //initialize each register with the given name from R0-R7
    registers[1] = GeneralRegister("R1");
    registers[2] = GeneralRegister("R2");
    registers[3] = GeneralRegister("R3");
    registers[4] = GeneralRegister("R4");
    registers[5] = GeneralRegister("R5");
    registers[6] = GeneralRegister("R6");
    registers[7] = GeneralRegister("R7");

    PC = 0; //set Program Counter to 0
}

void CPU::setRegisterValue(int index, signed char value)
{
    if(index < 0 || index >= 8)
    {
        cout<<"Invalid register\n";   //if the index value given is more than 8 which is the max number of registers or less than 0, give error message
        return;
    }
    registers[index].setValue(value);   //use member function inherited from Register class to set value of the chosen register at the given index
}

signed char CPU::getRegisterValue(int index) const
{
    if(index < 0 || index >= 8)
    {
        cout<<"Invalid register\n";   //if the index value given is more than 8 which is the max number of registers or less than 0, give error message
        return 0;
    }
    return registers[index].getValue(); //use the member function inherited from Register class to get value stored in the chosen register
}

void CPU::writeMemory(int address, signed char value)
{
    if(address < 0 || address >= 64)
    {
        cout << "Invalid memory address\n"; //give error message if the given memory address is < 0 or >= 64 which is the max number of addresses
        return;
    }
    memory.write(address, value);   //write the value given into the address chosen using the member function from Memory class
}

signed char CPU::readMemory(int address)
{
    if(address < 0 || address >= 64)
    {
        cout << "Invalid memory address\n"; //give error message if the given memory address is < 0 or >= 64 which is the max number of addresses
        return 0;
    }
    return memory.read(address);    //get the value stored in the address given using member function from Memory class
}

void CPU::pushStack(signed char value)
{
    stack.push(value);  //use member function of Stack class (stack operation) to push given value into stack
}

signed char CPU::popStack()
{
    return stack.pop();  //use member function of Stack class (stack operation) to pop the last value from stack
}

void CPU::setZeroFlag(bool value)
{
    flags.setZero(value);   //use member function from Flag Register class to set value for zero flag
}

bool CPU::getZeroFlag() const
{
    return flags.getZero();   //use member function from Flag Register class to get value for zero flag
}

void CPU::setCarryFlag(bool value)
{
    flags.setCarry(value);   //use member function from Flag Register class to set value for carry flag
}

bool CPU::getCarryFlag() const
{
    return flags.getCarry();   //use member function from Flag Register class to get value for carry flag
}

void CPU::setOverflowFlag(bool value)
{
    flags.setOverflow(value);   //use member function from Flag Register class to set value for overflow flag
}

bool CPU::getOverflowFlag() const
{
    return flags.getOverflow();   //use member function from Flag Register class to get value for overflow flag
}

void CPU::setUnderflowFlag(bool value)
{
    flags.setUnderflow(value);   //use member function from Flag Register class to set value for underflow flag
}

bool CPU::getUnderflowFlag() const
{
    return flags.getUnderflow();   //use member function from Flag Register class to get value for underflow flag
}

int CPU::getPC() const
{
    return PC;  //return the current program counter
}

void CPU::incrementPC()
{
    PC++;   //increment program counter by 1
}

int CPU::getSI() const
{
    return stack.getTop() + 1;  //get stack index by getting the top index of stack using member function from Stack class and +1
}

void CPU::reset()
{
    PC = 0; //PC set to 0
    memory.clear(); //memory cleared by setting all to 0
    flags.reset();  //all flags reset aka set to false/0

    while(!stack.isEmpty())
    {
        stack.pop();    //while stack is not empty, keep popping elements until stack is empty
    }

    for(int i = 0; i < 8; i++)
    {
        registers[i].setValue(0);   //set to 0 for all register values
    }
}