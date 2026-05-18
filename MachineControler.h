//thingy that controls the whole overcomplicated vm
#pragma once

#include "Component.h"
#include <QDebug>
namespace components
{
    class MachineControler
    {
    public:
        MachineControler() {}

        void runLoop(Component *base);
    };
}
