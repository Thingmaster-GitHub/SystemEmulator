//0x25
#pragma once

#include "DisplayIDDataBlock.h"
namespace system_emulator
{
    class BlockDynamicVideoTimingRangeLimits : public DisplayIDDataBlock
    {
    public:
        BlockDynamicVideoTimingRangeLimits(QByteArray data);
    };
}
