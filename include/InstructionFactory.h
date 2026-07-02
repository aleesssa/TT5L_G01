#ifndef INSTRUCTIONFACTORY_H
#define INSTRUCTIONFACTORY_H

#include "Instruction.h"
#include <string>
using namespace std;

class InstructionFactory {
public:
    static Instruction* createInstruction(string tokens[], int tokenCount);
};

#endif