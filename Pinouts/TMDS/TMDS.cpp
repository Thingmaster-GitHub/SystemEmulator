#include "TMDS.h"
using namespace components;

void TMDS::initialize()
{
    initIO();
    //signal +
    m_pinStates.append(true);
    //signal -
    m_pinStates.append(false);
}
TMDS::TMDS(Clock* c)
{
    m_clock=c;
    initialize();
}

TMDS::TMDS()
{
    initialize();
}
bool TMDS::getSignalPlus()
{
    return m_pinStates.at(0);
}
bool TMDS::getSignalMinus()
{
    return m_pinStates.at(1);
}
void TMDS::setSignal(bool b)
{
    m_pinStates.replace(0,b);
    m_pinStates.replace(1,!b);
}


