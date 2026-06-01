#pragma once

#include "DisplayIDVariableLengthStructure.h"
namespace system_emulator
{
    class DisplayIDTable
    {
    public:
        DisplayIDTable() : m_data(new QVector<DisplayIDVariableLengthStructure*>()){}
        DisplayIDTable(QByteArray data);
        //adds a data block in the first avalable position, if none are found a new extention section is created
        void addBlockData(DisplayIDDataBlock* data);
        //returns true if it has been removed, false otherwise
        bool removeVarLengthStructure(int index);
        QString assembleTableWhole();
        DisplayIDDataBlock* getDataBlock(int baseStructure,int dataBlock);
    private:
        //adds an extention section initialized with the given data block
        void addExtensionSection(DisplayIDDataBlock* data);
        QVector<DisplayIDVariableLengthStructure*>* m_data;
    };
}
