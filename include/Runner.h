#ifndef RUNNER_H 
#define RUNNER_H

#include <string>
#include "Vector.h"

using namespace std;

class Runner {
private:
    // Stores all cleaned instructions from the .asm file
    Vector<std::string> programLines;

    //Helper functions
    bool isValidInstruction(const std::string& instruction);
    bool isValidRegister(const std::string& reg);

public:
    // Constructor
    Runner();

    //reads an assembly file
    bool loadASMFile(const std::string& filename);

    //splits 1 instruction into tokens
    void tokenize(const std::string& line,
                    Vector<std::string>& tokens);

    //validates 1 instruction
    bool validateSyntax(const Vector<std::string>& tokens);
    
    //gives other classes access to the loaded program
    const Vector<std::string>& getProgramLines() const;
};

#endif 