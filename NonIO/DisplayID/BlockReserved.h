//0x00-0x1F
#pragma once

#include "DisplayIDDataBlock.h"
namespace system_emulator
{
    class BlockReserved : public DisplayIDDataBlock
    {
    public:
        BlockReserved(QByteArray data);
    };
}
