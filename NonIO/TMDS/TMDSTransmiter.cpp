#include "TMDSTransmiter.h"

using namespace system_emulator;

void TMDSTransmiter::setInput(QBitArray data)
{
    m_data=data;
    m_index=0;
}
void TMDSTransmiter::processClockPlus()
{

    getTMDSPins()->setSignal(m_data.at(m_index));
    m_index++;
}
