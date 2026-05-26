//0x27
#pragma once

#include "DisplayIDDataBlock.h"
namespace system_emulator
{
    class BlockStereoDisplayInterface : public DisplayIDDataBlock
    {
    public:
        BlockStereoDisplayInterface(QByteArray data);
    };
}
