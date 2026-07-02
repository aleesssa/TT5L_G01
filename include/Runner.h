#ifndef RUNNER_H
#define RUNNER_H

#include <string>
#include "Vector.h"

using namespace std;

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

    void processProgram();

    int getLineCount();
    string getLine(int index);
};

#endif