#include "Register.h"

/*=========================================================
Implementation: Register
Author: QAISARAH
=========================================================*/
Register::Register()
{
    value = 0;
}

void Register::setValue(signed char v)
{
    value = v;
}

signed char Register::getValue() const
{
    return value;
}
