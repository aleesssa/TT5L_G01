#include "GeneralRegister.h"

/*=========================================================
Implementation: GeneralRegister
Author: QAISARAH
=========================================================*/
GeneralRegister::GeneralRegister()
{
    name = "";
}

GeneralRegister::GeneralRegister(string n)
{
    name = n;
}

string GeneralRegister::getName() const
{
    return name;
}
