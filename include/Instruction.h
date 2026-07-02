#ifndef INSTRUCTION_h
#define INSTRUCTION_H
#include "CPU.h"

class Instruction{
    protected:
        int getRegisterIndex(string reg);
        bool isRegister(string text);
        bool isMemoryRegister(string text);
        bool isMemoryAddress(string text);
        void updateFlags(CPU& cpu, int result);


    public:
        virtual void execute(CPU& cpu) = 0;
        virtual ~Instruction(){}
};

#endif