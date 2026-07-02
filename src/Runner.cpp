#include "../include/Runner.h"
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


void Runner::tokenize(const string& line, Vector<string>& tokens) {
    string word = "";

    for (int i = 0; i < line.length(); i++) {
        char ch = line[i];

        if (ch == ' ' || ch == ',' || ch == '\t') {
            if (word != "") {
                tokens.push_back(word);
                word = "";
            }
        } else {
            word += ch;
        }
    }

    if (word != "") {
        tokens.push_back(word);
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
           instruction == "ROR" ||
           instruction == "RESET";
}


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


bool Runner::validateSyntax(Vector<string>& tokens) {
    if (tokens.size() == 0) {
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

        if (tokens.size() != 2) {
            cout << "Syntax Error: " << op << " requires 1 operand." << endl;
            return false;
        }
    } else {
        if (tokens.size() != 3) {
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
        op == "PUSH" || op == "POP") {

        if (!isValidRegister(tokens[1])) {
            cout << "Syntax Error: Invalid register in " << op << endl;
            return false;
        }
    }

    return true;
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