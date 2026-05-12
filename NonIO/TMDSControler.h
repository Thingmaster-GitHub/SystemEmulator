//a sort of wrapper class for all TMDS protocol things, makes it easier to utilize, almost as if its just a normal way to transfer a variable!
//sort of a virtual cable with built in encoding
#pragma once

#include "NonIOComponent.h"

namespace components
{
    class TMDSControler : public NonIOComponent
    {
        public:
            TMDSControler(Clock* c);
            char getOutput();
            //pre : input must be an 8 bit character
            void setInput(char* input);
            bool outputReady();
    };
}
