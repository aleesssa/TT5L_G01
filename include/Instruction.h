#ifndef INSTRUCTION_H
#define INSTRUCTION_H
#include <string>
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