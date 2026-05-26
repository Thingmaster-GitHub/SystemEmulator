#include "DisplayIDData.h"

using namespace system_emulator;

QByteArray DisplayIdData::getData()
{
    return QByteArray();//TODO fix me!
}
DisplayIDDataBlock DisplayIdData::getDataBlock(QByteArray data)
{
    switch(data.at(0))
    {
        case (char)0x20:
            return BlockProductIdentification(data);
        case (char)0x21:
            return BlockDisplayParameters(data);
        case (char)0x22:
            return BlockDetailedTiming(data);
        case (char)0x23:
            return BlockEnumeratedTimingCode(data);
        case (char)0x24:
            return BlockFormulaBasedTiming(data);
        case (char)0x25:
            return BlockDynamicVideoTimingRangeLimits(data);
        case (char)0x26:
            return BlockDisplayInterfaceFeatures(data);
        case (char)0x27:
            return BlockStereoDisplayInterface(data);
        case (char)0x28:
            return BlockTiledDisplayTechnology(data);
        case (char)0x29:
            return BlockContainerID(data);
        case (char)0x7E:
            return BlockVendorSpecific(data);
        case (char)0x81:
            return BlockCTADisplayID(data);
        default:
        {
            if(data.at(0)<0x20)
                return BlockReserved(data);
            else
                return BlockInvalid(data);
        }


    }
}
