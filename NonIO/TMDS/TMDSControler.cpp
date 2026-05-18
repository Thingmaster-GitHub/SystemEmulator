#include "TMDSControler.h"

using namespace components;

TMDSControler::TMDSControler(Clock* c)
{
    initIO();
    m_clock=c;
    TMDS* pins = new TMDS(c);
    TMDSEncoder* encoder = new TMDSEncoder(pins,m_clock);
    TMDSDecoder* decoder = new TMDSDecoder(pins,m_clock);
    pins->addConnection(encoder);
    pins->addConnection((decoder));
    encoder->addConnection(this);
    decoder->addConnection(this);
    addConnection(encoder);//index 0
    addConnection(decoder);//index 1
}
void TMDSControler::setInput(const char* input)
{
    TMDSEncoder* tmp = dynamic_cast<TMDSEncoder*>(m_IO->at(0));
    tmp->setInput(input);
}
void TMDSControler::clearData()
{
    TMDSDecoder* tmp = dynamic_cast<TMDSDecoder*>(m_IO->at(1));
    tmp->clearData();
}
const char* TMDSControler::getOutput()
{
    TMDSDecoder* tmp = dynamic_cast<TMDSDecoder*>(m_IO->at(1));
    return tmp->getOutput();
}


