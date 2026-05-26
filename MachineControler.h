//thingy that controls the whole overcomplicated vm
#pragma once

#include "Component.h"
#include <QDebug>
namespace system_emulator
{
    class MachineControler
    {
    public:
        MachineControler() {}

        void runLoop(Component *base);
    };
}
