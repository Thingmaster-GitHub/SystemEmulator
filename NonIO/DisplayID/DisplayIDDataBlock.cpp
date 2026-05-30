#include "DisplayIDDataBlock.h"
using namespace system_emulator;

void DisplayIDDataBlock::initialize(QByteArray data)
{
    //size of the data DisplayIDDataBlock
    //don't know why I have to store this so many times, but I'm not questioning it.
    m_blockSize=data.at(1);
    m_usage=data.at(2);
    m_extentionCount=data.at(3);

    m_checksum=data.at(m_blockSize+4);
}
void DisplayIDDataBlock::initialize()
{
    //will only initialize data needed universally whith mostly unchanging values
    m_usage=2;
    m_extentionCount=0;
    m_checksum=0;
}
QByteArray DisplayIDDataBlock::getData()
{
    QByteArray output = QByteArray();
    output.append(0x20);
    output.append(m_blockSize);
    output.append(m_extentionCount);

    output.resize(m_blockSize+5);//4 initial + m_blockSize + 1 for m_checksum

    getSubclassData(&output);

    m_checksum =calculateCheckSum(output);
    output.replace(m_blockSize+4,m_checksum);



    return output;
}
quint8 DisplayIDDataBlock::calculateCheckSum(QByteArray data)
{
    quint64 sum=0;
    for(int i=0;i<m_blockSize+4;i++)
    {
        sum+=data.at(i);
    }
    return (256 - (sum%256))%256;
}
