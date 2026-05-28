#pragma once

#include <QByteArray>
#include <QBitArray>
namespace system_emulator
{
    class DisplayIDDataBlock
    {
    public:
        DisplayIDDataBlock();
        DisplayIDDataBlock(QByteArray data){}

        int getDataIndexEnd();//returns the end index of the input data
        virtual QString getDataUI();//returns the human readable data

        quint8 getUsage()
        {
            return m_usage;
        }
        quint8 getExtetionCount()
        {
            return m_extentionCount;
        }
        quint8 getblockSize()
        {
            return m_blockSize;
        }
        void setUsage(quint8 usage)
        {
            m_usage=usage;
            calculateCheckSum();
        }
        void setExtentionCount(quint8 count)
        {
            m_extentionCount=count;
            calculateCheckSum();
        }


        QByteArray getData();

    protected:

        virtual void getSubclassData(QByteArray* data);

        void initialize(QByteArray data);

        void setBlockSize(quint8 size)
        {
            m_blockSize=size;
            calculateCheckSum();
        }

    private:
        void calculateCheckSum();
        //byte 2
        quint8 m_extentionCount;
        //usage (this is required for no clear reason)
        quint8 m_usage;
        //length of variable length data block
        //byte 1
        quint8 m_blockSize;
        //byte m_blockSize+4
        QBitArray m_checksum;

    };
}
