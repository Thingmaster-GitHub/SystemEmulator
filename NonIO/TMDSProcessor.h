#pragma once

#include "NonIOComponent.h"
#include <QBitArray>
namespace components
{
    class TMDSProcessor : public NonIOComponent
    {
    protected:
        //curent data being encoded/decoded
        QBitArray m_data;
    };
}
