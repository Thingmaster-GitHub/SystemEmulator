#include "MachineControler.h"
using namespace system_emulator;

void MachineControler::runLoop(Component* base)
{
    while(base->isRunning())
    {
        base->propagate();
    }
}
