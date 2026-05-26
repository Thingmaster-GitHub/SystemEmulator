//0x7E
#pragma once

#include "DisplayIDDataBlock.h"
namespace system_emulator
{
    class BlockVendorSpecific : public DisplayIDDataBlock
    {
    public:
        BlockVendorSpecific(QByteArray data);
    };
}
