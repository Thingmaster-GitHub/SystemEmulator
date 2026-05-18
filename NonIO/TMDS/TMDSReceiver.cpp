#include "TMDSReceiver.h"

using namespace components;

void TMDSReceiver::processClockPlus()
{
    m_data.setBit(m_index,getTMDSPins()->getSignalPlus());
    m_index++;
    // qDebug()<<m_data<<" "<<m_index;

    if(m_index>=10)
    {
        m_index=0;
        dynamic_cast<TMDSDecoder*>(m_IO->at(0))->setInput(m_data);
    }
}
QBitArray TMDSReceiver::getOutput()
{
    return m_data;
}

