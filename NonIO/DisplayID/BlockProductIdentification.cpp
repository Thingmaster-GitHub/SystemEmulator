#include "BlockProductIdentification.h"

using namespace system_emulator;

BlockProductIdentification::BlockProductIdentification(QByteArray data)
{
    initialize(data);
    //now onto class specific functionality

    m_OUI               =   data.sliced(3,3);   //3, 3 bytes
    m_productID         =   data.sliced(6,2);   //6, 2 bytes
    m_serialNumber      =   data.sliced(8,4);   //8, 4 bytes
    m_weekManufacture   =   data.at(12);        //12
    m_yearManufacture   =   data.at(13);        //13
    m_nameLength        =   data.at(14);        //14

    m_productName       =   data.sliced(15,14+m_nameLength); //15 , 15 -1 + m_nameLength
}

BlockProductIdentification::BlockProductIdentification()
{
    initialize();
    m_OUI=0;
    m_productID=0;
    m_serialNumber=0;
    m_weekManufacture=0;
    m_yearManufacture=0;
    m_productName=QString("");
    correctPayloadSizeVars();
}
void BlockProductIdentification::correctPayloadSizeVars()
{
    m_nameLength=m_productName.size();
    m_payloadSize=12+m_nameLength;//TODO make sure this is correct
}
QByteArray BlockProductIdentification::getDataPartial()
{
    QByteArray output = QByteArray();
    output.append(m_OUI);
    output.append(m_productID);
    output.append(m_serialNumber);
    output.append(m_weekManufacture);
    output.append(m_yearManufacture);
    output.append(m_nameLength);
    output.append(m_productName.toLocal8Bit());

    return output;
}
QString BlockProductIdentification::getUIDataPartial()
{
    QString output = "";
    output+="OUI: "+QString::number(m_OUI.toInt());
    output+="product id: "+QString::number(m_productID.toInt());
    output+="serial number: "+QString::number(m_serialNumber.toInt());
    output+="week of manufacture: "+QString::number(m_weekManufacture);
    output+="year of manufacture: "+QString::number(m_yearManufacture+2000);
    output+="length of product name: "+QString::number(m_nameLength);
    output+="product name: "+m_productName;
    return output;
}
