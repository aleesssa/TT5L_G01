#ifndef INSTRUCTIONFACTORY_H
#define INSTRUCTIONFACTORY_H

#include "Instruction.h"
#include <string>
using namespace std;


/*=========================================================
Class: InstructionFactory
Author: Aleessa Batrisyia Binti Azwan 
=========================================================*/

class InstructionFactory {
public:
    static Instruction* createInstruction(string tokens[], int tokenCount);
};

#endif