//should ideally never appear
#pragma once

#include "DisplayIDDataBlock.h"
namespace system_emulator
{
    class BlockInvalid : public DisplayIDDataBlock
    {
    public:
        BlockInvalid(QByteArray data);
    };
}

