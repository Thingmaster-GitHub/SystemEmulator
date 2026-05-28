#include "DisplayIDData.h"

using namespace system_emulator;

QByteArray DisplayIdData::getData()
{
    return QByteArray();//TODO fix me!
}
DisplayIDDataBlock* DisplayIdData::getDataBlock(QByteArray data)
{
    switch(data.at(4))
    {
        case (char)0x20:
            return new BlockProductIdentification(data);
        case (char)0x21:
            return new BlockDisplayParameters(data);
        case (char)0x22:
            return new BlockDetailedTiming(data);
        case (char)0x23:
            return new BlockEnumeratedTimingCode(data);
        case (char)0x24:
            return new BlockFormulaBasedTiming(data);
        case (char)0x25:
            return new BlockDynamicVideoTimingRangeLimits(data);
        case (char)0x26:
            return new BlockDisplayInterfaceFeatures(data);
        case (char)0x27:
            return new BlockStereoDisplayInterface(data);
        case (char)0x28:
            return new BlockTiledDisplayTechnology(data);
        case (char)0x29:
            return new BlockContainerID(data);
        case (char)0x7E:
            return new BlockVendorSpecific(data);
        case (char)0x81:
            return new BlockCTADisplayID(data);
        default:
        {
            if(data.at(4)<0x20)
                return new BlockReserved(data);
            else
                return new BlockInvalid(data);
        }


    }
}
