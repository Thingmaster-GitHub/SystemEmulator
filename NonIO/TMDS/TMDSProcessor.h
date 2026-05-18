#pragma once

#include "../NonIOComponent.h"
#include <QBitArray>
#include <QByteArray>
namespace components
{
    class TMDSProcessor : public NonIOComponent
    {
    protected:
        QBitArray tmdsLoop(bool operation)
        {
            QBitArray tmp=m_data;
            if(operation)
                for(int i=1;i<8;i++)
                    tmp.setBit(i,xorop(tmp,i));
            else
                for(int i=1;i<8;i++)
                    tmp.setBit(i,xnorop(tmp,i));
            return tmp;
        }
        //xor operation used in loop
        virtual bool xorop(QBitArray tmp,int i)=0;
        //xnor operation used in loop
        virtual bool xnorop(QBitArray tmp,int i)=0;
        //curent data being encoded/decoded
        QBitArray m_data;
        int m_index;
        QByteArray* m_dataStream;
    };
}
