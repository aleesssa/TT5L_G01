#ifndef SHIFTINSTRUCTION_H
#define SHIFTINSTRUCTION_H

class CPU;

// Instruction class will come from Person 3
class Instruction;

class ShiftInstruction
{
public:
    ShiftInstruction();

    void execute(CPU& cpu);

private:
    void shiftLeft(unsigned char& value);
    void shiftRight(unsigned char& value);
    void rotateLeft(unsigned char& value);
    void rotateRight(unsigned char& value);
};

#endif