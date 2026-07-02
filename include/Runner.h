#ifndef RUNNER_H 
#define RUNNER_H

#include <string>
using namespace std;

class Runner {
private:
    string programLines[100]; //array to hold the program lines
    int lineCount; //number of lines in the program

    //Helper functions
    bool isValidInstruction(const string& instruction);
    bool isValidRegister(const string& reg);

public:
    // Constructor
    Runner();

    //reads an assembly file
    bool loadASMFile(const string& filename);

    //splits 1 instruction into tokens
    void tokenize(const string& line,
                  string tokens[],
                  int& tokenCount);

    //validates 1 instruction
    bool validateSyntax(string tokens[],
                        int tokenCount);

    int getLineCount() const;
    string getLine(int index) const;
};

#endif 