//0x20
#pragma once

#include "DisplayIDDataBlock.h"
namespace system_emulator
{
    class BlockProductIdentification : public DisplayIDDataBlock
    {
    public:
        BlockProductIdentification(QByteArray data);
    };
}
