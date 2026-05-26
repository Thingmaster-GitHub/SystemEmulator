//0x24
#pragma once

#include "DisplayIDDataBlock.h"
namespace system_emulator
{
    class BlockFormulaBasedTiming : public DisplayIDDataBlock
    {
    public:
        BlockFormulaBasedTiming(QByteArray data);
    };
}
