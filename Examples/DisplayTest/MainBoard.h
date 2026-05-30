#pragma once

#include "../../Component.h"
#include "../../NonIO/TMDS/TMDSControler.h"
#include "../../NonIO/TMDS/TMDSEncoder.h"
#include "../../NonIO/TMDS/TMDSDecoder.h"
#include "../../Pinouts/TMDS/TMDS.h"

#include <QTextStream>
//designed to be the first board initialized
namespace system_emulator
{
    class MainBoard : public Component
    {
    public:
        MainBoard();
        void processClockPlus() override;
        void processClockMinus() override{}
    private:
        int m_inputSize;
        int m_index;
    };
}
