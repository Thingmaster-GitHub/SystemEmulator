//transition minimized differential signaling
#pragma once

#include "TMDSProcessor.h"
#include "TMDSReceiver.h"
#include <QVector>
#include <QDebug>
namespace components
{
    class TMDSDecoder : public TMDSProcessor
    {
    public:
        TMDSDecoder(TMDS* pins,Clock* c);
        void processClockPlus() override;
        void processClockMinus() override{}
        const char* getOutput();
        void setInput(QBitArray input);//temporary
    protected:
        bool xorop(QBitArray tmp,int i) override;
        bool xnorop(QBitArray tmp,int i) override;
    private:
        void decodeInput();
    };
}

