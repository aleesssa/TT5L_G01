#include "CPU.h"

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
    SI = 0;
}

void CPU::setRegisterValue(int index, signed char value)
{
    registers[index].setValue(value);
}

signed char CPU::getRegisterValue(int index)
{
    return registers[index].getValue();
}

void CPU::writeMemory(int address, signed char value)
{
    memory.write(address, value);
}

signed char CPU::readMemory(int address)
{
    return memory.read(address);
}

void CPU::pushStack(signed char value)
{
    stack.push(value);
    SI++;
}

signed char CPU::popStack()
{
    SI--;
    return stack.pop();
}

void CPU::setZeroFlag(bool value)
{
    flags.setZero(value);
}

bool CPU::getZeroFlag()
{
    return flags.getZero();
}

void CPU::setCarryFlag(bool value)
{
    flags.setCarry(value);
}

bool CPU::getCarryFlag()
{
    return flags.getCarry();
}

void CPU::setOverflowFlag(bool value)
{
    flags.setOverflow(value);
}

bool CPU::getOverflowFlag()
{
    return flags.getOverflow();
}

void CPU::setUnderflowFlag(bool value)
{
    flags.setUnderflow(value);
}

bool CPU::getUnderflowFlag()
{
    return flags.getUnderflow();
}

void CPU::setPC(int value)
{
    PC = value;
}

int CPU::getPC()
{
    return PC;
}

void CPU::incrementPC()
{
    PC++;
}

void CPU::setSI(int value)
{
    SI = value;
}

int CPU::getSI()
{
    return SI;
}
