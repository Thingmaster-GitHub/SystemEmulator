#pragma once

#include <QString>

#include "DisplayIDDataBlock.h"
namespace system_emulator
{
    class BlockProductIdentification : public DisplayIDDataBlock
    {
    public:
        BlockProductIdentification();
        BlockProductIdentification(QByteArray data);

        QByteArray getDataPartial() override;
        QString getUIDataPartial() override;
        void setOUI(quint32 OUI)
        {
            m_OUI=QByteArray::number(OUI);
            m_OUI.resize(3);
        }
        void setProductID(quint16 ID)
        {
            m_productID=QByteArray::number(ID);
        }
        void setSerialNumber(quint32 number)
        {
            m_serialNumber=QByteArray::number(number);
        }
        void setWeekManufacture(quint8 week)
        {
            m_weekManufacture=week;
        }
        void setYearManufacture(quint8 year)
        {
            m_yearManufacture=year;
        }
        void setProductName(QString name)
        {
            m_productName=name;
            correctPayloadSizeVars();
        }
    private:
        //corrects the stored size of the payload
        void correctPayloadSizeVars();

        QByteArray m_OUI;//             3 bytes, Organizationally Unique Identifier
        QByteArray m_productID;//       2 bytes
        QByteArray m_serialNumber;//    4 bytes
        quint8 m_weekManufacture;
        quint8 m_yearManufacture;
        quint8 m_nameLength;
        QString m_productName;
    };
}
