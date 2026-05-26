//0x26
#pragma once

#include "DisplayIDDataBlock.h"
namespace system_emulator
{
    class BlockDisplayInterfaceFeatures : public DisplayIDDataBlock
    {
    public:
        BlockDisplayInterfaceFeatures(QByteArray data);
    };
}
