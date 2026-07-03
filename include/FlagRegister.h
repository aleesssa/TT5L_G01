#ifndef FLAGREGISTER_H
#define FLAGREGISTER_H

/*=========================================================
Class: FlagRegister
Author: QAISARAH SHAMSUL AZRAN
=========================================================*/
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
    bool getOverflow() const;
    bool getUnderflow() const;
    bool getCarry() const;
    bool getZero() const;
};

#endif
