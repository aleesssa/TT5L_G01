#include "ArithmeticInstruction.h"
#include "CPU.h"
#include <iostream>
#include <cstdlib>

using namespace std;
/*=========================================================
Implementation: ArithmeticInstruction
Author: Aleessa Batrisyia Binti Azwan (Person 3)
=========================================================*/

// Constructor
ArithmeticInstruction::ArithmeticInstruction(string op, string op1, string op2){
    opcode = op;
    operand1 = op1;
    operand2 = op2;
}

// Get value stored in register if operand is a register
int ArithmeticInstruction::getValue(CPU& cpu, string operand){
    if (isRegister(operand)){
        return cpu.getRegisterValue(getRegisterIndex(operand));
    }

    return atoi(operand.c_str());
}

// Execute arithmetic operation based on the opcode
void ArithmeticInstruction::execute(CPU& cpu){
    int dest = getRegisterIndex(operand1); // get register index at operand1
    int left = cpu.getRegisterValue(dest); // assign value stored at dest 
    int result = left; // initial result state 

    if (opcode == "ADD"){
        result = left + getValue(cpu, operand2); // add left with value stored at operand2
    }
    else if(opcode == "SUB"){
        result = left - getValue(cpu, operand2); // subtract left with value stored at operand2
    }
    else if(opcode == "MUL"){
        result = left * getValue(cpu, operand2); //multiply left with value stored at operand2
    }
    else if(opcode == "DIV"){
        int right = getValue(cpu, operand2); // get value at operand2 
        
        // if value at operand2 is 0 then output error division by zero
        if(right == 0){
            cout << "Error: Division by zero." << endl;
            return;
        }
        result = left / right;
    }
    else if(opcode == "INC"){
        result = left + 1; 
    }
    else if(opcode == "DEC"){
        result = left - 1;
    }
    
    updateFlags(cpu, result);
    cpu.setRegisterValue(dest, result);
}