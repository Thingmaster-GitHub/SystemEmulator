//transition minimized differential signaling
#pragma once

#include "TMDSProcessor.h"
#include <QVector>
#include <QtNumeric>
#include <QDebug>
namespace components
{
    class TMDSEncoder : public TMDSProcessor
    {
    public:
        TMDSEncoder(Component* pins);
        void process() override;
        void setInput(char* input);
    private:
        //dc balance maintnence
        QBitArray tmdsxor();
        QBitArray tmdsxnor();
        int getDistanceResult(QBitArray b);
        QBitArray getOptimal();
        //returns true if option 2 should be used (xnor)
        bool chooseOutput();
    };
}

