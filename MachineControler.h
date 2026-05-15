//thingy that controls the whole overcomplicated vm
#pragma once

#include "Component.h"
#include <QDebug>
namespace components
{
    class MachineControler
    {
    public:
        MachineControler(Clock *c) : m_clock(c) {}

        void runLoop(Component *base);


    private:
    Clock* m_clock;
    };
}
