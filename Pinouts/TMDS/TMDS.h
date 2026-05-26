#pragma once

#include "../PinableIO.h"

//transition-minimized differential signaling
namespace system_emulator
{
    class TMDS : public PinableIO
    {
    public:
        TMDS();
        TMDS(Clock* c);
        bool getSignalPlus();
        bool getSignalMinus();
        void setSignal(bool b);
    private:
        void initialize();
    };
}
