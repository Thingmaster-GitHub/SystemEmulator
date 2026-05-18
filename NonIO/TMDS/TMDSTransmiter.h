#pragma once

#include "TMDSComunicator.h"

namespace components
{
    class TMDSTransmiter : public TMDSComunicator
    {
    public:
        TMDSTransmiter(TMDSProcessor* connection,TMDS* pins) : TMDSComunicator(connection,pins){}
        void processClockPlus() override;
        void processClockMinus() override{}
        void setInput(QBitArray data);
    };
}
