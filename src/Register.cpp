#include "Register.h"

Register::Register()
{
    value = 0;
}

void Register::setValue(signed char v)
{
    value = v;
}

signed char Register::getValue()
{
    return value;
}
