#pragma once

#include <QByteArray>
#include <QBitArray>
#include <QString>
namespace system_emulator
{
    class DisplayIDDataBlock
    {
    public:
        DisplayIDDataBlock();
        QString getUIData();
        QByteArray getData();
        //returns the human readable form of the given data

        //returns the data block size in bytes
        int getSize()
        {
            return m_payloadSize+3;
        }
    protected:
        virtual QString getUIDataPartial();
        virtual QByteArray getDataPartial();

        void initialize(QByteArray data);
        void initialize();
        //this is used a couple of ways, but they tend to differ little
        QBitArray m_byteOne;
        int m_payloadSize;
    };
}
