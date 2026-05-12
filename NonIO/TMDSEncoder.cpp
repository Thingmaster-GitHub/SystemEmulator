#include "TMDSEncoder.h"

components::TMDSEncoder::TMDSEncoder(Component* pins)
{
    m_IO = new QVector<Component*>();
    addConnection(pins);//index 0
    char tmp = 0;
    setInput(&tmp);
}
void components::TMDSEncoder::setInput(char* input)
{

    m_data=QBitArray::fromBits(input,8);
    m_data.resize(10);
    //now to encode!
    m_data=getOptimal();
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
QBitArray components::TMDSEncoder::getOptimal()
{

    if(chooseOutput())
        return tmdsxnor();
    else
        return tmdsxor();
}
QBitArray components::TMDSEncoder::tmdsxor()
{
    QBitArray tmp = m_data;
    for(int i=1;i<8;i++)
    {
        tmp.setBit(i,tmp.at(i) ^ tmp.at(i-1));
    }
    tmp.setBit(8,1);

    return tmp;
}
QBitArray components::TMDSEncoder::tmdsxnor()
{
    QBitArray tmp = m_data;
    for(int i=1;i<8;i++)
    {
        tmp.setBit(i,tmp.at(i) == tmp.at(i-1));
    }
    return tmp;
}


int components::TMDSEncoder::getDistanceResult(QBitArray b)
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
bool components::TMDSEncoder::chooseOutput()
{
    //using that weird technique to chose which output is used.
    int bitSum=0;//sum of 1s in m_data
    for(int i=0;i<8;i++)
        if(m_data.at(i))
            bitSum++;
    return false;
    //return bitSum>4||(bitSum==4&&!m_data.at(0));

}

void components::TMDSEncoder::process()
{

}
