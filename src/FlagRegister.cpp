#include "FlagRegister.h"

/*=========================================================
Implementation: FlagRegister
Author: QAISARAH SHAMSUL AZRAN
=========================================================*/
FlagRegister::FlagRegister()
{
    reset();    //whenever the flag register is initialized, all flags are reset
}

void FlagRegister::reset()
{
    OF = false; //all flags are reset aka all flags are set to false/0
    UF = false;
    CF = false;
    ZF = false;
}

void FlagRegister::setOverflow(bool x)
{
    OF = x; //set the overflow flag to the given boolean value
}

void FlagRegister::setUnderflow(bool x)
{
    UF = x; //set the underflow flag to the given boolean value
}

void FlagRegister::setCarry(bool x)
{
    CF = x; //set the carry flag to the given boolean value
}

void FlagRegister::setZero(bool x)
{
    ZF = x; //set the zero flag to the given boolean value
}

bool FlagRegister::getOverflow() const
{
    return OF;  //return the overflow flag boolean value
}

bool FlagRegister::getUnderflow() const
{
    return UF;  //return the underflow flag boolean value
}

bool FlagRegister::getCarry() const
{
    return CF;  //return the carry flag boolean value
}

bool FlagRegister::getZero() const
{
    return ZF;  //return the zero flag boolean value
}