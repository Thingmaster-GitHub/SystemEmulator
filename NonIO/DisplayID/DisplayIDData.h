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
//a way of both creating the binary DisplayId and reading its values
//will not allow for editing values within, though it will allow removing data blocks entirely
//very little error checking for simplicity

namespace system_emulator
{
    class DisplayIdData
    {
    public:
        //default constuctor
        DisplayIdData();

        //initializes with the data given
        DisplayIdData(QByteArray data);
        //returns the entire processed data packet
        QByteArray getData();
        void addBlock(DisplayIDDataBlock block);
        QString getDataUI();
    private:
        //returns a data block initialized with the data given
        //pre - must ony contain data starting at the data block's header
        DisplayIDDataBlock getDataBlock(QByteArray data);
        QVector<DisplayIDDataBlock*>* m_data;
    };
}
