#include "ShiftInstruction.h"

ShiftInstruction::ShiftInstruction()
{
}

void ShiftInstruction::shiftLeft(unsigned char& value)
{
    value <<= 1;
}

void ShiftInstruction::shiftRight(unsigned char& value)
{
    value >>= 1;
}

void ShiftInstruction::rotateLeft(unsigned char& value)
{
    value = (value << 1) | (value >> 7);
}

void ShiftInstruction::rotateRight(unsigned char& value)
{
    value = (value >> 1) | (value << 7);
}

void ShiftInstruction::execute(CPU& cpu)
{
    // Will be completed after CPU interface is available.
}