#include "MachineControler.h"

void components::MachineControler::runLoop(Component* base)
{
    while(base->isRunning())
    {
        base->propagate();
        m_clock->tick();//might change this to allow desychronized clocks later (though doing nothing while looping through elements seems odd)
    }
}
