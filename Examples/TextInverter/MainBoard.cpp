#include "MainBoard.h"
using namespace components;

MainBoard::MainBoard()
{
    m_running=true;
    initIO();
    m_clock=new Clock();
    //const char* c = "some text";
    TMDSControler* t = new TMDSControler(m_clock);
    addConnection(t);//index 0
    //t->setInput(c);
    m_index=0;
    m_inputSize=-1;
}
void MainBoard::processClockPlus()
{
    m_index++;
    if(m_index>m_inputSize)
    {
        QTextStream in(stdin);
        QTextStream out(stdout);
        QString data(dynamic_cast<TMDSControler*>(m_IO->at(0))->getOutput());

        QString inverse("");
        for(int i=data.size()-1;i>=0;i--)
        {
            inverse.append(data.at(i));
        }
        out<<inverse<<"\n";
        out<<"enter something! "<<Qt::flush;
        dynamic_cast<TMDSControler*>(m_IO->at(0))->clearData();
        QByteArray tmp = in.readLine().toLocal8Bit();
        m_index=0;
        m_inputSize=tmp.size();
        dynamic_cast<TMDSControler*>(m_IO->at(0))->setInput(tmp);;
    }


}
