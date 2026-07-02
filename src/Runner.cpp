#include "../include/Runner.h"
#include <iostream>
#include <fstream>

using namespace std;

// Written by: Person 2
// Purpose: Constructor initializes number of program lines to 0
Runner::Runner() {
    lineCount = 0;
}

// Written by: Person 2
// Purpose: Reads assembly file line by line
bool Runner::loadASMFile(const string& filename) {
    ifstream inputFile(filename.c_str());

    if (!inputFile) {
        cout << "Error: Cannot open ASM file." << endl;
        return false;
    }

    string line;

    while (getline(inputFile, line)) {
        if (line != "") {
            programLines[lineCount] = line;
            lineCount++;
        }
    }

    inputFile.close();
    return true;
}

// Written by: Person 2
// Purpose: Splits one instruction line into tokens
void Runner::tokenize(const string& line, string tokens[], int& tokenCount) {
    tokenCount = 0;
    string word = "";

    for (int i = 0; i < line.length(); i++) {
        char ch = line[i];

        if (ch == ' ' || ch == ',' || ch == '\t') {
            if (word != "") {
                tokens[tokenCount] = word;
                tokenCount++;
                word = "";
            }
        } else {
            word += ch;
        }
    }

    if (word != "") {
        tokens[tokenCount] = word;
        tokenCount++;
    }
}

// Written by: Person 2
// Purpose: Checks valid instruction names
bool Runner::isValidInstruction(const string& instruction) {
    return instruction == "MOV" ||
           instruction == "ADD" ||
           instruction == "SUB" ||
           instruction == "MUL" ||
           instruction == "DIV" ||
           instruction == "INC" ||
           instruction == "DEC" ||
           instruction == "INPUT" ||
           instruction == "DISPLAY" ||
           instruction == "LOAD" ||
           instruction == "STORE" ||
           instruction == "PUSH" ||
           instruction == "POP" ||
           instruction == "SHL" ||
           instruction == "SHR" ||
           instruction == "ROL" ||
           instruction == "ROR" ||
           instruction == "RESET";
}

// Written by: Person 2
// Purpose: Checks register format R0 to R7
bool Runner::isValidRegister(const string& reg) {
    if (reg.length() != 2) {
        return false;
    }

    if (reg[0] != 'R') {
        return false;
    }

    if (reg[1] < '0' || reg[1] > '7') {
        return false;
    }

    return true;
}

// Written by: Person 2
// Purpose: Validates syntax based on instruction and operand count
bool Runner::validateSyntax(string tokens[], int tokenCount) {
    if (tokenCount == 0) {
        return false;
    }

    string op = tokens[0];

    if (!isValidInstruction(op)) {
        cout << "Syntax Error: Invalid instruction " << op << endl;
        return false;
    }

    if (op == "INC" || op == "DEC" ||
        op == "INPUT" || op == "DISPLAY" ||
        op == "PUSH" || op == "POP" ||
        op == "RESET") {

        if (tokenCount != 2) {
            cout << "Syntax Error: " << op << " requires 1 operand." << endl;
            return false;
        }
    } else {
        if (tokenCount != 3) {
            cout << "Syntax Error: " << op << " requires 2 operands." << endl;
            return false;
        }
    }

    // Register validation for common cases
    if (op == "ADD" || op == "SUB" ||
        op == "MUL" || op == "DIV") {

        if (!isValidRegister(tokens[1]) || !isValidRegister(tokens[2])) {
            cout << "Syntax Error: Invalid register in " << op << endl;
            return false;
        }
    }

    if (op == "INC" || op == "DEC" ||
        op == "INPUT" || op == "DISPLAY" ||
        op == "PUSH" || op == "POP") {

        if (!isValidRegister(tokens[1])) {
            cout << "Syntax Error: Invalid register in " << op << endl;
            return false;
        }
    }

    return true;
}

// Written by: Person 2
// Purpose: Returns number of loaded instructions
int Runner::getLineCount() const {
    return lineCount;
}

// Written by: Person 2
// Purpose: Returns one instruction line
string Runner::getLine(int index) const {
    if (index >= 0 && index < lineCount) {
        return programLines[index];
    }

    return "";
}