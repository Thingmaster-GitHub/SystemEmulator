#pragma once

#include "TMDSComunicator.h"
#include "TMDSDecoder.h"
namespace system_emulator
{
    class TMDSReceiver : public TMDSComunicator
    {
    public:
        TMDSReceiver(TMDSProcessor* connection,TMDS* pins) : TMDSComunicator(connection,pins){}

        QBitArray getOutput();
        void processClockPlus() override;
        void processClockMinus() override{}
    };
}
