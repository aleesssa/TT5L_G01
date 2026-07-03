#include "../include/Runner.h"
#include "../include/CPU.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    if (argc < 2) {
        cout << "Usage: vm <filename.asm>" << endl;
        return 1;
    }

    CPU cpu;
    Runner runner;

    bool loaded = runner.loadASMFile(argv[1]);

    if (!loaded) {
        return 1;
    }

    runner.processProgram(cpu);

    cout << "Program executed successfully." << endl;

    // Later, if Person 4 has dumpState:
    // cpu.dumpState();

    return 0;
}