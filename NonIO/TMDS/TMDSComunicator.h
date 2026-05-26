//a class intended to be TMDS protocol reciever or transmiter
//kinda odd for this to be non-IO, but it's certainly not IO itself
//definitly io -y er than other TMDS non-IO system_emulator
#pragma once

#include "../NonIOComponent.h"
#include "TMDSProcessor.h"
#include "../../Pinouts/TMDS/TMDS.h"
namespace system_emulator
{
    class TMDSComunicator : public NonIOComponent
    {
    public:
        TMDSComunicator(TMDSProcessor* connection,TMDS* pins);
        TMDS* getTMDSPins();
    protected:
        QBitArray m_data;
        int m_index;
    };
}
