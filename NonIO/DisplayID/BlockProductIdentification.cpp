#include "BlockProductIdentification.h"

using namespace system_emulator;

BlockProductIdentification::BlockProductIdentification(QByteArray data)
{
    initialize(data);
    //now onto class specific functionality
    //all bytes must be read relitive to the 4 proceeding bytes
    //in the reference page, this means to add 4 to listed indices
    m_numPayloadBytes   =   data.at(6);         //2 +4
    m_OUI               =   data.sliced(7,3);   //3 +4, 3 bytes
    m_productID         =   data.sliced(10,2);  //6 +4, 2 bytes
    m_serialNumber      =   data.sliced(12,4);  //8 +4, 4 bytes
    m_weekManufacture   =   data.at(16);        //12 +4
    m_yearManufacture   =   data.at(17);        //13 +4
    m_nameLength        =   data.at(18);        //14 +4

    m_productName       =   data.sliced(19,18+m_nameLength); //15 +4, 19 -1 + m_nameLength
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
}
