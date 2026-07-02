#ifndef REGISTER_H
#define REGISTER_H

class Register
{
protected:
    signed char value;

public:
    Register();
    void setValue(signed char v);
    signed char getValue();
};

#endif
