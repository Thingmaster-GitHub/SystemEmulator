//0x21
#pragma once

#include "DisplayIDDataBlock.h"
namespace system_emulator
{
    class BlockDisplayParameters : public DisplayIDDataBlock
    {
    public:
        BlockDisplayParameters(QByteArray data);
    };
}
