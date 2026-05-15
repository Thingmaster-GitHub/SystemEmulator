#include "TMDSComunicator.h"

using namespace components;

TMDSComunicator::TMDSComunicator(TMDSProcessor* connection,TMDS* pins)
{
    char t = (char)0;
    m_data=QBitArray::fromBits(&t,8);
    m_data.resize(10);
    initIO();
    m_clock = new Clock(connection->getClock()->getSpeed()/10);
    addConnection(connection);
    addConnection(pins);
    m_index=0;
}
TMDS* TMDSComunicator::getTMDSPins()
{
    return dynamic_cast<TMDS*>(m_IO->at(findIOComponent(1)));
}

