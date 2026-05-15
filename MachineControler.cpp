#include "MachineControler.h"
using namespace components;

void MachineControler::runLoop(Component* base)
{
    while(base->isRunning())
    {
        base->propagate();
    }
}
