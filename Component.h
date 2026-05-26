
//base class for everything in this project
//above everything in class heirarchy
#include <QVector>

#pragma once

#include "Clock.h"
#include <QDebug>
namespace system_emulator
{
    class Component
    {
    public:
        Component(){}

        Component(Clock* c) : m_clock(c){}

        Component(Component* c) : m_clock(c->getClock()), m_IO(new QVector<Component*>)
        {
            m_IO->append(c);
        }
        void initIO()
        {
            m_IO=new QVector<Component*>();
        }
        //only use this function for the base element
        void propagate()
        {
            QVector<Component*>* a = new QVector<Component*>();
            QVector<Clock*>* b = new QVector<Clock*>();
            propagate(a,b);
        }
        void propagate(QVector<Component*>* callers,QVector<Clock*>* clocks)
        {
            //check if clock needs ticked
            bool needsTick=true;
            for(int i=0;i<clocks->size()&&needsTick;i++)
                if(m_clock==clocks->at(i))
                    needsTick=false;
            if(needsTick)
            {
                clocks->append(m_clock);
                m_clock->tick();
            }

            process();
            callers->append(this);

            for(int i=0;i<m_IO->size();i++)
            {
                //?

                bool needsRan=true;
                for(int j=0;j<callers->size()&&needsRan;j++)
                    if(m_IO->at(i)==callers->at(j))
                        needsRan=false;
                if(needsRan)
                    m_IO->at(i)->propagate(callers,clocks);
            }
        }
        void process()
        {
            if(m_clock->getState()!=m_lastClockState)
            {
                if(m_clock->getState())
                    processClockPlus();
                else
                    processClockMinus();

                m_lastClockState=m_clock->getState();
            }
        }
        //called when clock changes to false
        virtual void processClockMinus()=0;
        //called when clock changes to true
        virtual void processClockPlus()=0;

        void addConnection(Component* c)
        {
            m_IO->append(c);
        }
        bool isRunning(){return m_running;}
        void stop(){m_running=false;}
        Clock* getClock(){return m_clock;}
    protected:
        Clock* m_clock;
        QVector<Component*>* m_IO;//IO ports, a set amount per component where not all ports must be defined (in most cases)
        bool m_running;
        bool m_lastClockState;
    };
}
