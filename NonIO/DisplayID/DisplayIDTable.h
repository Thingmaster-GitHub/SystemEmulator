#pragma once

#include "DisplayIDVariableLengthStructure.h"
namespace system_emulator
{
    class DisplayIDTable
    {
    public:
        DisplayIDTable() : m_data(new QVector<DisplayIDVariableLengthStructure*>()){}

        //adds a data block in the first avalable position, if none are found a new extention section is created
        void addBlockData(DisplayIDDataBlock* data);
        //returns true if it has been removed, false otherwise
        bool removeVarLengthStructure(int index);
        DisplayIDDataBlock* getDataBlock(int baseStructure,int dataBlock);
    private:
        QVector<DisplayIDVariableLengthStructure*>* m_data;
    };
}
