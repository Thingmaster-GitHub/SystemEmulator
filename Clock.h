//arguably the most important part of the project
//has a way of simulating different clock speeds by ustilizing their ratios
#pragma once

namespace components
{
    class Clock
    {
    public:
        // @param - c number of calls to tick before it is ran
        Clock(int c) :  m_cycles(c),  m_tickCount(0), m_state(true){}

        //initializes m_cycles to a default value of 100
        Clock() :  m_cycles(100),  m_tickCount(0), m_state(true){}
        void tick()
        {
            if(m_cycles==m_tickCount)
                m_state=!m_state;
        }
        bool getState()
        {
            return m_state;
        }
        // @param - number of tick calls per change in clock state at a rate if 1/numCycles
        void setSpeed(int numCycles)
        {
            m_cycles=numCycles;
        }
    private:
        int m_cycles;//the number of calls to the tick function before it is truely ran
        int m_tickCount;//number of times tick has been called since last cycle
        bool m_state;
    };
}
