//0x23
#pragma once

#include "DisplayIDDataBlock.h"
namespace system_emulator
{
    class BlockEnumeratedTimingCode : public DisplayIDDataBlock
    {
    public:
        BlockEnumeratedTimingCode(QByteArray data);
    };
}
