
//base class for everything in this project
//above everything in class heirarchy
#include <QVector>

#pragma once

#include "Clock.h"

namespace components
{
    class Component
    {
    public:
        Component(){}

        Component(Clock* c) : m_clock(c) {}

        Component(Component* c) : m_clock(c->getClock()), m_IO(new QVector<Component*>)
        {
            m_IO->append(c);
        }

        //only use this function for the base element
        void propagate()
        {
            QVector<Component*>* a = new QVector<Component*>();
            a->append(this);
            propagate(a);
        }
        void propagate(QVector<Component*>* callers)
        {
            process();
            callers->append(this);
            for(int i=0;i<m_IO->size();i++)
            {
                bool needsRan=true;
                for(int j=0;j<callers->size()&&needsRan;j++)
                    if(m_IO->at(i)==callers->at(j))
                        needsRan=false;
                if(needsRan)
                    m_IO->at(i)->propagate();
            }
        }
        virtual void process()=0;

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
    };
}
