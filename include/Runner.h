#ifndef RUNNER_H
#define RUNNER_H

#include <string>
#include "Vector.h"
#include "CPU.h"

using namespace std;

/*=========================================================
Class: Runner
Author: NUR ALYA IMAN
=========================================================*/
class Runner
{
private:
    Vector<string> programLines;

    bool isValidInstruction(const string& instruction);
    bool isValidRegister(const string& reg);

public:
    Runner();

    bool loadASMFile(const string& filename);

    void tokenize(const string& line,
                  string tokens[],
                  int& tokenCount);

    bool validateSyntax(string tokens[],
                        int tokenCount);

    void processProgram(CPU& cpu);

    int getLineCount();
    string getLine(int index);
};

#endif