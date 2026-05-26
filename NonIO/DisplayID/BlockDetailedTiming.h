//0x22
#pragma once

#include "DisplayIDDataBlock.h"
namespace system_emulator
{
    class BlockDetailedTiming : public DisplayIDDataBlock
    {
    public:
        BlockDetailedTiming(QByteArray data);
    };
}
