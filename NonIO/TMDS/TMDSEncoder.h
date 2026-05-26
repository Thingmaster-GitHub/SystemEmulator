//transition minimized differential signaling
#pragma once

#include "TMDSProcessor.h"
#include "TMDSTransmiter.h"

#include <QVector>
#include <QtNumeric>
#include <QDebug>
#include <QByteArray>
namespace system_emulator
{
    class TMDSEncoder : public TMDSProcessor
    {
    public:
        TMDSEncoder(TMDS* pins,Clock* c);
        void processClockPlus() override;
        void processClockMinus() override{}

        void setInput(const char* input);
    protected:
        bool xorop(QBitArray tmp,int i) override;
        bool xnorop(QBitArray tmp,int i) override;
    private:
        void EncodeOutput(char* input);
        TMDSTransmiter* getTransmiter();
        void sendInput();
        //dc balance maintnence
        int m_counter; //counts # on ones minus number of zeros

        int getDistanceResult(QBitArray b);
        //returns true if option 2 should be used (xnor)
        bool chooseOutput();

    };
}

