#ifndef GENERALREGISTER_H
#define GENERALREGISTER_H
#include "Register.h"
#include <string>
using namespace std;

class GeneralRegister : public Register
{
private:
    string name;

public:
    GeneralRegister();
    GeneralRegister(string n);
    string getName() const;
};

#endif
