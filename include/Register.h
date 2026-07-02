#ifndef REGISTER_H
#define REGISTER_H

class Register
{
private:
    signed char value;

public:
    Register();
    void setValue(signed char v);
    signed char getValue() const;
};

#endif
