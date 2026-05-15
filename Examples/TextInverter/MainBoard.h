#pragma once

#include "../../Component.h"
#include "../../NonIO/TMDSControler.h"
#include "../../NonIO/TMDSEncoder.h"
#include "../../NonIO/TMDSDecoder.h"
#include "../../Pinouts/TMDS.h"

#include <QTextStream>
//designed to be the first board initialized
namespace components
{
    class MainBoard : public Component
    {
    public:
        MainBoard();
        void processClockPlus() override;
        void processClockMinus() override{}
    };
}
