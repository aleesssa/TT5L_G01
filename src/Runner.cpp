#include "../include/Runner.h"
#include "../include/InstructionFactory.h"
#include <iostream>
#include <fstream>

using namespace std;


Runner::Runner() {
}


bool Runner::loadASMFile(const string& filename) {
    ifstream inputFile(filename.c_str());

    if (!inputFile) {
        cout << "Error: Cannot open ASM file." << endl;
        return false;
    }

    string line;

    while (getline(inputFile, line)) {
        if (line != "") {
            programLines.push_back(line);
        }
    }

    inputFile.close();
    return true;
}


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
           instruction == "ROR";
}


bool Runner::isValidRegister(const string& reg) {
    return reg.length() == 2 &&
           reg[0] == 'R' &&
           reg[1] >= '0' &&
           reg[1] <= '7';
}


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
        op == "PUSH" || op == "POP") {

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

    if (op == "ADD" || op == "SUB" ||
        op == "MUL" || op == "DIV") {

        if (!isValidRegister(tokens[1]) || !isValidRegister(tokens[2])) {
            cout << "Syntax Error: Invalid register in " << op << endl;
            return false;
        }
    }

    if (op == "INC" || op == "DEC" ||
        op == "INPUT" || op == "DISPLAY" ||
        op == "PUSH" || op == "POP" ||
        op == "SHL" || op == "SHR" ||
        op == "ROL" || op == "ROR") {

        if (!isValidRegister(tokens[1])) {
            cout << "Syntax Error: Invalid register in " << op << endl;
            return false;
        }
    }

    return true;
}


void Runner::processProgram(CPU& cpu) {
    for (int i = 0; i < programLines.size(); i++) {
        string tokens[5];
        int tokenCount = 0;

        tokenize(programLines[i], tokens, tokenCount);

        if (!validateSyntax(tokens, tokenCount)) {
            cout << "Error found in line " << i + 1 << endl;
            return;
        }

        Instruction* instruction =
            InstructionFactory::createInstruction(tokens, tokenCount);

        if (instruction == 0) {
            cout << "Error: Cannot create instruction at line "
                 << i + 1 << endl;
            return;
        }

        instruction->execute(cpu);

        if (tokens[0] != "SHL" &&
            tokens[0] != "SHR" &&
            tokens[0] != "ROL" &&
            tokens[0] != "ROR") {
            cpu.incrementPC();
        }

        delete instruction;
    }
}


int Runner::getLineCount() {
    return programLines.size();
}


string Runner::getLine(int index) {
    if (index >= 0 && index < programLines.size()) {
        return programLines[index];
    }

    return "";
}