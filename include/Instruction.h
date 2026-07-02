#ifndef INSTRUCTION_h
#define INSTRUCTION_H

class CPU;

class Instruction{
    public:
        virtual void execute(CPU& cpu) = 0;
        virtual ~Instruction(){}
};

#endif