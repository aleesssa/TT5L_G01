#include "DumpState.h"
#include <iostream>
#include <iomanip>

using namespace std;

/*=========================================================
Implementation: DumpState
Author: NUR DAMIA' BATRISYIA
=========================================================*/
void DumpState::display(CPU& cpu)
{
    cout <<"CPU STATE\n";

    cout << "PC : " << cpu.getPC() << endl;
    cout << "SI : " << cpu.getSI() << endl;

    cout << "\nRegisters\n";

    for(int i = 0; i < 8; i++)
    {
        cout << "R" << i << " : "
             << setw(4)
             << setfill('0')
             << (int)cpu.getRegisterValue(i)  << endl;
    }

    cout << "\nFlags\n";
    cout << "ZF : " << cpu.getZeroFlag() << endl;
    cout << "CF : " << cpu.getCarryFlag() << endl;
    cout << "OF : " << cpu.getOverflowFlag() << endl;
    cout << "UF : " << cpu.getUnderflowFlag() << endl;

    cout << "\nMemory\n";

    for(int i = 0; i < 64; i++)
    {
        cout << setw(4)
             << setfill('0')
             << (int)cpu.readMemory(i)
             << " ";

        if((i + 1) % 8 == 0)
        {
            cout << endl;
        }
    }
}