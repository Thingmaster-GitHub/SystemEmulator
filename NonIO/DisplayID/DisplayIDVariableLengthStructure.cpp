#include "DisplayIDVariableLengthStructure.h"

using namespace system_emulator;

DisplayIDVariableLengthStructure::DisplayIDVariableLengthStructure()
{
    m_data=new QVector<DisplayIDDataBlock*>();
    m_dataBlockSize=0;
    m_extensionCount=0;
    m_usage=2;
}
DisplayIDVariableLengthStructure::DisplayIDVariableLengthStructure(QByteArray data)
{
    m_dataBlockSize=data.at(1);
    m_usage=data.at(2);
    m_extensionCount=data.at(3);
    int byteOffset=4;
    while(byteOffset<m_dataBlockSize+3)//+3 for initial bytes
    {
        DisplayIDDataBlock* tmp = getDataBlock(data.slice(byteOffset));
        byteOffset+=tmp->getSize();
        m_data->append(tmp);
    }
    if(calculateCheckSum(data.slice(0,data.size()-2))!=data.at(data.size()-1))//minus two to exclude precalculated checksum byte
    {
        //whatever code transfered this data has failed
        //TODO actually impliment what this does
    }

}
QByteArray DisplayIDVariableLengthStructure::getData()
{
    QByteArray output;
    //variable length structure data
    output.append(0x20);//byte 0
    output.append(m_dataBlockSize);//byte 1
    output.append(m_usage);//byte 2
    output.append(m_extensionCount);//byte 3

    //data blocks
    for(int i=0;i<m_data->size();i++)
    {
        output += m_data->at(i)->getData();
    }

    //and finally, the checksum
    output.append(calculateCheckSum(output));
    return output;
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
    for(int i=0;i<m_dataBlockSize+4;i++)
    {
        sum+=data.at(i);
    }
    return (256 - (sum%256))%256;
}
void DisplayIDVariableLengthStructure::addBlock(DisplayIDDataBlock* block)
{
    m_data->append(block);
    m_dataBlockSize+=block->getSize();
}
