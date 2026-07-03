#include "InstructionFactory.h"
#include "ArithmeticInstruction.h"
#include "IOInstruction.h"
#include "MovInstruction.h"
#include "StackInstruction.h"
#include "MemoryInstruction.h"
#include "ShiftInstruction.h"
using namespace std;

/*=========================================================
Implementation: InstructionFactory
Author: Aleessa Batrisyia Binti Azwan 
=========================================================*/

Instruction* InstructionFactory::createInstruction(string tokens[], int tokenCount) {
    string op = tokens[0];
    if (op == "ADD" || op == "SUB" || op == "MUL" || op == "DIV") {
        if (tokenCount != 3) { return 0; }
        return new ArithmeticInstruction(op, tokens[1], tokens[2]);
    }
    if (op == "INC" || op == "DEC") {
        if (tokenCount != 2) { return 0; }
        return new ArithmeticInstruction(op, tokens[1]);
    }
    if (op == "INPUT" || op == "DISPLAY") {
        if (tokenCount != 2) { return 0; }
        return new IOInstruction(op, tokens[1]);
    }
    if (op == "MOV") {
        if (tokenCount != 3) { return 0; }
        return new MovInstruction(op, tokens[1], tokens[2]);
    }
    if (op == "PUSH" || op == "POP") {
        if (tokenCount != 2) { return 0; }
        return new StackInstruction(op, tokens[1]);
    }
    if (op == "LOAD" || op == "STORE") {
        if (tokenCount != 3) { return 0; }
        return new MemoryInstruction(op, tokens[1], tokens[2]);
    }
    if (op == "SHL" || op == "SHR" || op == "ROL" || op == "ROR") {
        if (tokenCount != 3) { return 0; }

        return new ShiftInstruction(op, tokens[1], tokens[2]);
    }
    return 0;
}