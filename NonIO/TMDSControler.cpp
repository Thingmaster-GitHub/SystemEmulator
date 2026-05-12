#include "TMDSControler.h"
#include "../Pinouts/TMDS.h"
#include "TMDSEncoder.h"
#include "TMDSDecoder.h"

components::TMDSControler::TMDSControler(Clock* c)
{
    TMDS* pins = new TMDS(c);
    TMDSEncoder* encoder = new TMDSEncoder(pins);
    TMDSDecoder* decoder = new TMDSDecoder(pins);
    pins->addConnection(encoder);
    pins->addConnection((decoder));
    encoder->addConnection(this);
    decoder->addConnection(this);
    addConnection(encoder);//index 0
    addConnection(decoder);//index 1
}
void components::TMDSControler::setInput(char* input)
{
    if(dynamic_cast<TMDSEncoder*>(m_IO->at(0)))
    {
        TMDSEncoder* tmp = dynamic_cast<TMDSEncoder*>(m_IO->at(0));
        tmp->setInput(input);
    }
}
char components::TMDSControler::getOutput()
{
    if(dynamic_cast<TMDSDecoder*>(m_IO->at(1)))
    {
        TMDSDecoder* tmp = dynamic_cast<TMDSDecoder*>(m_IO->at(1));
        return tmp->getOutput();
    }
    else
        return ' ';
}



