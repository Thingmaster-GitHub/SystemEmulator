#pragma once

#include "../Component.h"
#include <QVector>
//a more IO focused virtual component subclass
//intended specifically for pin behavior
namespace components
{
    class PinableIO : public Component
    {
    public:
        //doesn't actually need to do anything, connected devices will call this class themselves
        void processClockPlus() override{}
        void processClockMinus() override{}
        bool getPinState(int i)
        {
            return m_pinStates.at(i);
        }
        int getPinCount()
        {
            return m_pinStates.size();
        }
    protected:
        QVector<bool> m_pinStates;
    };
}
