#include "ShiftInstruction.h"
#include <cstdlib>

using namespace std;

ShiftInstruction::ShiftInstruction(string op, string dest, string c) : operation(op), destination(dest), count(c) {}

void ShiftInstruction::execute(CPU& cpu)
{
    int index = getRegisterIndex(destination);
    signed char regValue = cpu.getRegisterValue(index);
    unsigned char bits = static_cast<unsigned char>(regValue);

    int shift = atoi(count.c_str()) % 8; // Ensure the shift count is within 0-7

    if (operation == "SHL")
    {
        bits <<= shift;
    }
    else if(operation == "SHR")
    {
        bits >>= shift;
    }
    else if(operation == "ROL")
    {
        bits = (bits << shift) | (bits >> (8 - shift));
    }
    else if(operation == "ROR")
    {
        bits = (bits >> shift) | (bits << (8 - shift));
    }

        regValue = static_cast<signed char>(bits);

    cpu.setZeroFlag(regValue == 0);
    cpu.setRegisterValue(index, regValue);

    cpu.incrementPC();
}