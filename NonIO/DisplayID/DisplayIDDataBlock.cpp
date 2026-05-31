#include "DisplayIDDataBlock.h"
using namespace system_emulator;

void DisplayIDDataBlock::initialize(QByteArray data)
{
    m_byteOne=QBitArray(data.at(1));
    m_payloadSize=data.at(2);
}

QByteArray DisplayIDDataBlock::getDataPartial()
{
    QByteArray output = QByteArray();

    output.append(m_byteOne.bits());
    output.append(m_payloadSize);

    return output;
}

