#pragma once

#include <QByteArray>
#include <QBitArray>
namespace system_emulator
{
    class DisplayIDDataBlock
    {
    public:
        DisplayIDDataBlock();

        int getDataIndexEnd();//returns the end index of the input data

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
        }
        void setExtentionCount(quint8 count)
        {
            m_extentionCount=count;
        }


        QByteArray getData();

    protected:

        virtual void getSubclassData(QByteArray* data);

        void initialize(QByteArray data);
        void initialize();
        void setBlockSize(quint8 size)
        {
            m_blockSize=size;
        }

    private:
        quint8 calculateCheckSum(QByteArray data);
        //byte 2
        quint8 m_extentionCount;
        //usage (this is required for no clear reason)
        quint8 m_usage;
        //length of variable length data block
        //byte 1
        quint8 m_blockSize;
        //byte m_blockSize+4
        quint8 m_checksum;

    };
}
