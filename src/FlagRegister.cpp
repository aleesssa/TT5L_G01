#include "FlagRegister.h"

/*=========================================================
Implementation: FlagRegister
Author: QAISARAH
=========================================================*/
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

bool FlagRegister::getOverflow() const
{
    return OF;
}

bool FlagRegister::getUnderflow() const
{
    return UF;
}

bool FlagRegister::getCarry() const
{
    return CF;
}

bool FlagRegister::getZero() const
{
    return ZF;
}
