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
        quint8 getExtesionCount()
        {
            return m_extensionCount;
        }
        quint8 getDataBlockSize()
        {
            return m_dataBlockSize;
        }
        //sets the primary use case
        void setUsage(quint8 usage)
        {
            m_usage=usage;
        }
        void setExtensionCount(quint8 count)
        {
            m_extensionCount=count;
        }
        void iterateExtensionCount()
        {
            m_extensionCount++;
        }
        void decrementExtensionCount()
        {
            m_extensionCount--;
        }

    private:
        quint8 calculateCheckSum(QByteArray data);
        //byte 2
        quint8 m_extensionCount;
        //usage (this is required for no clear reason)
        quint8 m_usage;
        //length of variable length data block
        //byte 1
        quint8 m_dataBlockSize;

        //returns a data block initialized with the data given
        //pre - must ony contain data starting at the data block's block tag
        DisplayIDDataBlock* getDataBlock(QByteArray data);
        QVector<DisplayIDDataBlock*>* m_data;
    };
}
