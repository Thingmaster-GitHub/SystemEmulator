#include "TMDSTransmiter.h"

using namespace components;

void TMDSTransmiter::setInput(QBitArray data)
{
    m_data=data;
    m_index=0;
}
bool TMDSTransmiter::ready()
{
    return m_index>=10;
}
void TMDSTransmiter::processClockPlus()
{

    getTMDSPins()->setSignal(m_data.at(m_index));
    m_index++;
}
