#include "TMDSEncoder.h"
using namespace components;

TMDSEncoder::TMDSEncoder(TMDS* pins,Clock* c)
{
    m_clock=c;
    m_counter=0;
    m_IO = new QVector<Component*>();
    m_dataStream = new QByteArray();
    m_index=0;
    char tmp = 0;
    setInput(&tmp);
    addConnection(new TMDSTransmiter(this,pins));
}
void TMDSEncoder::EncodeOutput(char* input)
{
    m_data=QBitArray::fromBits(input,8);
    m_data.resize(10);
    //now to encode!
    bool algorithm = chooseOutput();
    m_data=tmdsLoop(algorithm);

    if(algorithm)
        m_data.setBit(8,1);
    //check if should be inverted

    QBitArray inverted=m_data;
    for(int i=0;i<8;i++)
        inverted.toggleBit(i);
    int r1=getDistanceResult(m_data);
    int r2=getDistanceResult(inverted);

    // check the totals
    if(qAbs(r1)>=qAbs(r2))
    {
        m_data=inverted;
        m_counter=r2;
        m_data.setBit(9,true);
    }
    else
        m_counter=r1;

}
void TMDSEncoder::setInput(const char* input)
{
    m_index=0;
    m_dataStream = new QByteArray(input);
}
bool TMDSEncoder::xnorop(QBitArray tmp,int i)
{
    return tmp.at(i) == tmp.at(i-1);
}
bool TMDSEncoder::xorop(QBitArray tmp,int i)
{
    return tmp.at(i) ^ tmp.at(i-1);
}

int TMDSEncoder::getDistanceResult(QBitArray b)
{
    int result = m_counter;
    for(int i=0;i<b.size();i++)
    {
        if(b.at(i))
            result++;
        else
            result--;
    }
    return result;
}
bool TMDSEncoder::chooseOutput()
{
    //using that weird technique to chose which output is used.
    int bitSum=0;//sum of 1s in m_data
    for(int i=0;i<8;i++)
    {
        if(m_data.at(i))
        {
            bitSum++;
        }
    }

    return !(bitSum>4||(bitSum==4&&!m_data.at(0)));
}
TMDSTransmiter* TMDSEncoder::getTransmiter()
{
    return dynamic_cast<TMDSTransmiter*>(m_IO->at(0));
}
bool TMDSEncoder::ready()
{
    return m_index==m_dataStream->size();
}
void TMDSEncoder::processClockPlus()
{
    char tmp;
    if(m_index!=m_dataStream->size())
    {
        tmp = m_dataStream->at(m_index);
    }
    else
    {
        tmp = (char)0;
    }
    EncodeOutput(&tmp);
    getTransmiter()->setInput(m_data);
    if(m_index<m_dataStream->size())
        m_index++;

}
