#include "TMDSDecoder.h"
using namespace components;
TMDSDecoder::TMDSDecoder(TMDS* pins,Clock* c)
{
    char t = (char)0;
    m_data=QBitArray::fromBits(&t,4);
    //m_data.resize(10);
    initIO();
    m_dataStream=new QByteArray();
    m_clock=c;
    TMDSReceiver* r = new TMDSReceiver(this,pins);
    addConnection(r);//index 0
    m_index=0;
}

const char* TMDSDecoder::getOutput()
{
    return m_dataStream->constData();
}
void TMDSDecoder::decodeInput()
{
    //assumes that all data has been sent
    if(m_data.at(9))
        for(int i=0;i<8;i++)
            m_data.toggleBit(i);

    m_data=tmdsLoop(m_data.at(8));

}

bool TMDSDecoder::xorop(QBitArray tmp, int i)
{
    return m_data.at(i) ^ m_data.at(i-1);
}

bool TMDSDecoder::xnorop(QBitArray tmp, int i)
{
    return m_data.at(i) == m_data.at(i-1);
}


void TMDSDecoder::setInput(QBitArray input)
{
    m_data=input;
}
void TMDSDecoder::processClockPlus()
{
    //qDebug()<<"out: "<<m_data;
    //process input
    if(m_data.size()==10)
    {
        decodeInput();
        m_data.resize(8);
    }
    m_dataStream->append(m_data.bits());
    if(m_data.size()==8)
        m_data.resize(10);


    m_index++;

}
void TMDSDecoder::clearData()
{
    m_dataStream=new QByteArray();
}

