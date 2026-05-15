#include "MainBoard.h"
using namespace components;

MainBoard::MainBoard()
{
    m_running=true;
    initIO();
    m_clock=new Clock();
    //just using basic test data for now
    //haven't goten to decoding yet though...
    //const char* c = "some text";
    TMDSControler* t = new TMDSControler(m_clock);
    addConnection(t);//index 0
    //t->setInput(c);
}
void MainBoard::processClockPlus()
{
    if(dynamic_cast<TMDSControler*>(m_IO->at(0))->ready())
    {
        QTextStream in(stdin);
        QTextStream out(stdout);
        out<<"enter something! ";
        dynamic_cast<TMDSControler*>(m_IO->at(0))->setInput(in.readLine().toLocal8Bit());;
        qDebug()<<dynamic_cast<TMDSControler*>(m_IO->at(0))->getOutput();
    }

}
