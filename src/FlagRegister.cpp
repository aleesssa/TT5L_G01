#include "FlagRegister.h"

FlagRegister::FlagRegister()
{
    reset();
}

void FlagRegister::reset()
{
    OF = false;
    UF = false;
    CF = false;
    ZF = false;
}

void FlagRegister::setOverflow(bool x)
{
    OF = x;
}

void FlagRegister::setUnderflow(bool x)
{
    UF = x;
}

void FlagRegister::setCarry(bool x)
{
    CF = x;
}

void FlagRegister::setZero(bool x)
{
    ZF = x;
}

bool FlagRegister::getOverflow()
{
    return OF;
}

bool FlagRegister::getUnderflow()
{
    return UF;
}

bool FlagRegister::getCarry()
{
    return CF;
}

bool FlagRegister::getZero()
{
    return ZF;
}
