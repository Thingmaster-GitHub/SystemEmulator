#include "DisplayIDTable.h"
using namespace system_emulator;
DisplayIDTable::DisplayIDTable(QByteArray data) : m_data(new QVector<DisplayIDVariableLengthStructure*>())
{
    //create base variable length structure
    {
        DisplayIDVariableLengthStructure* tmp = new DisplayIDVariableLengthStructure(data);
        m_data->append(tmp);
    }

    //loop through all extensions
    int byteOffset=m_data->at(0)->getDataBlockSize()+4;//+4 for non data block bytes

    for(int i=0;i<m_data->at(0)->getExtesionCount();i++)
    {
        DisplayIDVariableLengthStructure* tmp = new DisplayIDVariableLengthStructure(data.slice(byteOffset));
        byteOffset+=tmp->getDataBlockSize()+4;
        m_data->append(tmp);
    }
    //hopefully no index off by one errors?
}
void DisplayIDTable::addBlockData(DisplayIDDataBlock* data)
{
    for(int i=0;i<m_data->size();i++)
    {
        if(m_data->at(i)->getDataBlockSize()+data->getSize()<=251)
        {
            m_data->at(i)->addBlock(data);
            return;
        }
    }
    addExtensionSection(data);
}
bool DisplayIDTable::removeVarLengthStructure(int index)
{
    if(index<m_data->size())
    {

        if(index!=0)
        {
            m_data->at(0)->decrementExtensionCount();
            m_data->remove(index);
            return true;
        }
        else if(m_data->size()==1)
        {
            m_data->remove(index);
            return true;
        }
        else
            return false;
    }
    else
        return false;
}
QString DisplayIDTable::assembleTableWhole()
{
    QString dataTable="";

    for(int i=0;i<m_data->length();i++)
        dataTable+=m_data->at(i)->getDataUI();

    return dataTable;
}
void DisplayIDTable::addExtensionSection(DisplayIDDataBlock* data)
{
    DisplayIDVariableLengthStructure* tmp = new DisplayIDVariableLengthStructure();
    m_data->at(0)->iterateExtensionCount();
    tmp->addBlock(data);
    tmp->setUsage(0);
    m_data->append(tmp);
}
