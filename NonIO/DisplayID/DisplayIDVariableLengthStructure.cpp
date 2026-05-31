#include "DisplayIDVariableLengthStructure.h"

using namespace system_emulator;

QByteArray DisplayIDVariableLengthStructure::getData()
{
    return QByteArray();//TODO fix me!
}
DisplayIDDataBlock* DisplayIDVariableLengthStructure::getDataBlock(QByteArray data)
{
    switch(data.at(0))
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
            if(data.at(0)<0x20)
                return new BlockReserved(data);
            else
                return new BlockInvalid(data);
        }


    }
}
quint8 DisplayIDVariableLengthStructure::calculateCheckSum(QByteArray data)
{
    quint64 sum=0;
    for(int i=0;i<m_blockSize+4;i++)
    {
        sum+=data.at(i);
    }
    return (256 - (sum%256))%256;
}
void DisplayIDVariableLengthStructure::addBlock(DisplayIDDataBlock block)
{

}
