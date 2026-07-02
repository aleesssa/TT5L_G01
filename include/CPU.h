#ifndef CPU_H
#define CPU_H

#include <iostream>
using namespace std;

class CPU {
private:
    int registers[8];
    int memory[64];
    int stack[8];
    int stackTop;

    bool OF;
    bool UF;
    bool CF;
    bool ZF;

public:
    CPU() {
        for (int i = 0; i < 8; i++) {
            registers[i] = 0;
            stack[i] = 0;
        }

        for (int i = 0; i < 64; i++) {
            memory[i] = 0;
        }

        stackTop = 0;

        OF = false;
        UF = false;
        CF = false;
        ZF = false;
    }

    int getRegister(int index) {
        return registers[index];
    }

    void setRegister(int index, int value) {
        registers[index] = value;
    }

    int readMemory(int address) {
        return memory[address];
    }

    void writeMemory(int address, int value) {
        memory[address] = value;
    }

    void updateFlags(int result) {
        OF = result > 127;
        UF = result < -128;
        CF = result > 255 || result < -255;
        ZF = result == 0;
    }

    void pushStack(int value) {
        if (stackTop >= 8) {
            cout << "Error: Stack overflow." << endl;
            return;
        }

        stack[stackTop] = value;
        stackTop++;
    }

    int popStack() {
        if (stackTop <= 0) {
            cout << "Error: Stack underflow." << endl;
            return 0;
        }

        stackTop--;
        return stack[stackTop];
    }
};

#endif