#include "Register.h"

/*=========================================================
Implementation: Register
Author: QAISARAH SHAMSUL AZRAN
=========================================================*/
Register::Register()
{
    value = 0;  //all register value initially 0
}

void Register::setValue(signed char v)
{
    value = v;  //set value of the chosen register to the given value
}

signed char Register::getValue() const
{
    return value;   //get the value associated with the chosen register
}