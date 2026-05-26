//0x81
#pragma once

#include "DisplayIDDataBlock.h"
namespace system_emulator
{
    class BlockCTADisplayID : public DisplayIDDataBlock
    {
    public:
        BlockCTADisplayID(QByteArray data);
    };
}
