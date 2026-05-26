//0x29
#pragma once

#include "DisplayIDDataBlock.h"
namespace system_emulator
{
    class BlockContainerID : public DisplayIDDataBlock
    {
    public:
        BlockContainerID(QByteArray data);
    };
}
