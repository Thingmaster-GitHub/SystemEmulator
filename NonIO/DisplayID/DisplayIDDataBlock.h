#pragma once

#include <QByteArray>
#include <QBitArray>
namespace system_emulator
{
    class DisplayIDDataBlock
    {
    public:
        DisplayIDDataBlock();
        //returns the human readable form of the given data
        virtual QString getUIData();

        int getDataIndexEnd();//returns the end index of the input data

        virtual QByteArray getData();

    protected:
        //returns the begining of the ui data shared by all data blocks
        QString getUIDataPartial();
        QByteArray getDataPartial();

        void initialize(QByteArray data);

        //this is used a couple of ways, but they tend to differ little
        QBitArray m_byteOne;
        int m_payloadSize;
    };
}
