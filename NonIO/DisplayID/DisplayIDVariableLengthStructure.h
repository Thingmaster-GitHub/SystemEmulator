#pragma once

#include "BlockContainerID.h"
#include "BlockCTADisplayID.h"
#include "BlockDetailedTiming.h"
#include "BlockDisplayInterfaceFeatures.h"
#include "BlockDisplayParameters.h"
#include "BlockDynamicVideoTimingRangeLimits.h"
#include "BlockEnumeratedTimingCode.h"
#include "BlockFormulaBasedTiming.h"
#include "BlockInvalid.h"
#include "BlockProductIdentification.h"
#include "BlockReserved.h"
#include "BlockStereoDisplayInterface.h"
#include "BlockTiledDisplayTopology.h"
#include "BlockVendorSpecific.h"

#include <QByteArray>
#include <QVector>

namespace system_emulator
{
    class DisplayIDVariableLengthStructure
    {
    public:
        //default constuctor
        DisplayIDVariableLengthStructure();

        //initializes with the data given
        DisplayIDVariableLengthStructure(QByteArray data);
        //returns the entire processed data packet
        QByteArray getData();
        void addBlock(DisplayIDDataBlock* block);
        QString getDataUI();

        quint8 getUsage()
        {
            return m_usage;
        }
        quint8 getExtetionCount()
        {
            return m_extentionCount;
        }
        quint8 getDataBlockSize()
        {
            return m_dataBlockSize;
        }
        void setUsage(quint8 usage)
        {
            m_usage=usage;
        }
        void setExtentionCount(quint8 count)
        {
            m_extentionCount=count;
        }

    private:
        quint8 calculateCheckSum(QByteArray data);
        //byte 2
        quint8 m_extentionCount;
        //usage (this is required for no clear reason)
        quint8 m_usage;
        //length of variable length data block
        //byte 1
        quint8 m_dataBlockSize;
        //byte m_blockSize+4
        quint8 m_checksum;
        //sets the primary use case
        void setUseCase(int useage);
        //returns a data block initialized with the data given
        //pre - must ony contain data starting at the data block's header
        DisplayIDDataBlock* getDataBlock(QByteArray data);
        QVector<DisplayIDDataBlock*>* m_data;
    };
}
