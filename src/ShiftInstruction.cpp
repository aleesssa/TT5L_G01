#include "ShiftInstruction.h"

void ShiftInstruction::execute(CPU& cpu)
{
    int index = getRegisterIndex(destination);
    signed char regValue = cpu.getRegisterValue(index);

    if (operation == "SHL")
    {
        regValue <<= 1;
    }
    else if (operation == "SHR")
    {
        regValue >>= 1;
    }
    else if (operation == "ROL")
    {
        unsigned char temp = static_cast<unsigned char>(regValue);
        temp = (temp << 1) | (temp >> 7);
        regValue = static_cast<signed char>(temp);
    }
    else if (operation == "ROR")
    {
        unsigned char temp = static_cast<unsigned char>(regValue);
        temp = (temp >> 1) | (temp << 7);
        regValue = static_cast<signed char>(temp);
    }

    cpu.setRegisterValue(index, regValue);
    cpu.setZeroFlag(regValue == 0);
    cpu.incrementPC();
}
