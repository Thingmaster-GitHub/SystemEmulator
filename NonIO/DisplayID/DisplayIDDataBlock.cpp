#include "DisplayIDDataBlock.h"
using namespace system_emulator;

void DisplayIDDataBlock::initialize(QByteArray data)
{
    m_byteOne=QBitArray(data.at(1));
    m_payloadSize=data.at(2);
}
void DisplayIDDataBlock::initialize()
{
    m_byteOne=QBitArray(0);
    m_payloadSize=0;
}
QByteArray DisplayIDDataBlock::getDataPartial()
{
    QByteArray output = QByteArray();

    output.append(m_byteOne.bits());
    output.append(m_payloadSize);

    return output;
}
QString DisplayIDDataBlock::getUIData()
{
    return QString("byte one: %1").arg(m_byteOne.bits()) + QString("\npayload size: %1").arg(m_payloadSize);
}
