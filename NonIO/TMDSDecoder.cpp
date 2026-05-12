#include "TMDSDecoder.h"
components::TMDSDecoder::TMDSDecoder(Component* pins)
{

}

const char* components::TMDSDecoder::getOutput()
{
    //assumes that all data has been sent
    if(m_data.at(9))
        for(int i=0;i<8;i++)
            m_data.toggleBit(i);

    if(m_data.at(8))
        m_data=undoxor();
    else
        m_data=undoxnor();

    return m_data.bits();
}

QBitArray components::TMDSDecoder::undoxor()
{
    QBitArray tmp = m_data;
    for(int i=1;i<8;i++)
    {
        tmp.setBit(i,m_data.at(i) ^ m_data.at(i-1));
    }
    return tmp;
}
QBitArray components::TMDSDecoder::undoxnor()
{
    QBitArray tmp = m_data;
    for(int i=1;i<8;i++)
    {
        tmp.setBit(i,m_data.at(i) == m_data.at(i-1));
    }
    return tmp;
}

void components::TMDSDecoder::setInput(char* c)
{
    m_data=QBitArray::fromBits(c,8);

    qDebug()<<undoxor();
}
void components::TMDSDecoder::process()
{
}

