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
    cout << "#Begin#" << endl;

    cout << "#Registers#";

    for(int i = 0; i < 8; i++)
    {
        cout << setw(4)
             << setfill('0')
             << (int)cpu.getRegisterValue(i)
             << "#";
    }

    cout << endl;

    cout << "#Flags#";
    cout << "OF#" << cpu.getOverflowFlag() << "#";
    cout << "UF#" << cpu.getUnderflowFlag() << "#";
    cout << "CF#" << cpu.getCarryFlag() << "#";
    cout << "ZF#" << cpu.getZeroFlag() << "#";

    cout << endl;

    cout << "#PC#";
    cout << setw(4)
         << setfill('0')
         << cpu.getPC()
         << "#";

    cout << endl;

    cout << "#Memory#" << endl;

    for(int i = 0; i < 64; i++)
    {
        cout << "#"
             << setw(4)
             << setfill('0')
             << (int)cpu.readMemory(i);

        if((i + 1) % 8 == 0)
        {
            cout << "#" << endl;
        }
    }

    cout << "#End#" << endl;
}
