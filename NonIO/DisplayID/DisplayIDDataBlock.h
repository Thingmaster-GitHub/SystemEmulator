#pragma once

#include <QByteArray>
namespace system_emulator
{
    class DisplayIDDataBlock
    {
    public:
        DisplayIDDataBlock();
        DisplayIDDataBlock(QByteArray data);

        int getDataIndexEnd();//returns the end index of the input data
        virtual QString getDataUI();//returns the human readable data
    };
}
