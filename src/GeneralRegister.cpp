#include "GeneralRegister.h"

/*=========================================================
Implementation: GeneralRegister
Author: QAISARAH SHAMSUL AZRAN
=========================================================*/
GeneralRegister::GeneralRegister()
{
    name = "";  //default constructor to initialize register name to ""
}

GeneralRegister::GeneralRegister(string n)
{
    name = n;   //constructor to set register name to given name
}

string GeneralRegister::getName() const
{
    return name;    //return the name of the register aka R0-R7
}