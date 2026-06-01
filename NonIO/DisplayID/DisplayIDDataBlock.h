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
        //returns the human readable form of the given data
        virtual QString getUIData();

        virtual QByteArray getData();
        //returns the data block size in bytes
        int getSize()
        {
            return m_payloadSize+3;
        }
    protected:
        //returns the begining of the ui data shared by all data blocks
        QString getUIDataPartial();
        QByteArray getDataPartial();

        void initialize(QByteArray data);
        void initialize();
        //this is used a couple of ways, but they tend to differ little
        QBitArray m_byteOne;
        int m_payloadSize;
    };
}
