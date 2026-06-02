#include "BlockDisplayParameters.h"

using namespace system_emulator;

void BlockDisplayParameters::setChromatictyX(int chromaticityNumber,QBitArray data)
{
    QBitArray* tmp = getChromaticity(chromaticityNumber);
    for(int i=0;i<12;i++)
    {
        tmp->setBit(i,data.at(i));
    }
}

void BlockDisplayParameters::setChromatictyY(int chromaticityNumber,QBitArray data)
{
    QBitArray* tmp = getChromaticity(chromaticityNumber);
    for(int i=0;i<12;i++)
    {
        tmp->setBit(i+12,data.at(i));
    }
}
BlockDisplayParameters::BlockDisplayParameters()
{
    initialize();
    m_payloadSize=29;
    m_imageSizeHorizontal=1920;
    m_imageSizeVertical=1080;
    m_pixelCountHorizontal=1920;
    m_imageSizeVertical=1080;

    m_featureSupportFlags=QBitArray(8,false);//helpfully, all defaults are set to false (0)
    m_PrimaryColorOneChromaticity=QBitArray(24,true);
    m_PrimaryColorTwoChromaticity=QBitArray(24,true);
    m_PrimaryColorThreeChromaticity=QBitArray(24,true);
    m_WhitePointChromaticity=QBitArray(24,true);

    m_maxLuminenceFull=1.0;
    m_maxLuminenceTenPercent=1.0;
    m_minimumLuminence=0.0;

    m_colorDepthAndDisplayTechnologyFlags=QBitArray(8);
    m_gammaEOTF=255;

}
QBitArray* BlockDisplayParameters::getChromaticity(int chromaticityNumber)
{
    switch(chromaticityNumber)
    {
        case 0:
            return &m_WhitePointChromaticity;
        case 1:
            return &m_PrimaryColorOneChromaticity;
        case 2:
            return &m_PrimaryColorTwoChromaticity;
        case 3:
            return &m_PrimaryColorThreeChromaticity;
        default:
            return nullptr;
    }
}
