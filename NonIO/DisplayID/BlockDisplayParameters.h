//0x21
#pragma once

#include <QFloat16>
#include "DisplayIDDataBlock.h"
namespace system_emulator
{
    class BlockDisplayParameters : public DisplayIDDataBlock
    {
    public:
        BlockDisplayParameters();
        BlockDisplayParameters(QByteArray data);

        QByteArray getDataPartial() override;
        QString getUIDataPartial() override;
        //sets the 12 bit chromaticity value for x, also called u' in different standards
        void setChromatictyX(int chromaticityNumber,QBitArray data);
        //sets the 12 bit chromaticity value for y, also called v' in different standards
        void setChromatictyY(int chromaticityNumber,QBitArray data);
    private:
        //returns a specific chromaticityNumber
        //0 - m_WhitePointChromaticity
        //1 - m_PrimaryColorOneChromaticity
        //... etc
        QBitArray* getChromaticity(int chromaticityNumber);
        quint16 m_imageSizeHorizontal;
        quint16 m_imageSizeVertical;
        quint16 m_pixelCountHorizontal;
        quint16 m_pixelCountVertical;
        QBitArray m_featureSupportFlags;
        QBitArray m_PrimaryColorOneChromaticity;
        QBitArray m_PrimaryColorTwoChromaticity;
        QBitArray m_PrimaryColorThreeChromaticity;
        QBitArray m_WhitePointChromaticity;
        qfloat16 m_maxLuminenceFull;
        qfloat16 m_maxLuminenceTenPercent;
        qfloat16 m_minimumLuminence;
        QBitArray m_colorDepthAndDisplayTechnologyFlags;
    };
}
