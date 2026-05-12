//transition minimized differential signaling
#pragma once

#include "TMDSProcessor.h"

#include <QVector>
#include <QDebug>
namespace components
{
    class TMDSDecoder : public TMDSProcessor
    {
    public:
        TMDSDecoder(Component* pins);
        void process() override;
        const char* getOutput();
        void setInput(char* c);//temporary
    private:
        QBitArray undoxor();
        QBitArray undoxnor();
    };
}

