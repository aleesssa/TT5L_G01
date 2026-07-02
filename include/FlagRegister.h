#ifndef FLAGREGISTER_H
#define FLAGREGISTER_H

class FlagRegister
{
private:
    bool OF;
    bool UF;
    bool CF;
    bool ZF;

public:
    FlagRegister();
    void reset();
    void setOverflow(bool x);
    void setUnderflow(bool x);
    void setCarry(bool x);
    void setZero(bool x);
    bool getOverflow();
    bool getUnderflow();
    bool getCarry();
    bool getZero();
};

#endif
