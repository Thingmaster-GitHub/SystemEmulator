#include <QDebug>
#include "../../MachineControler.h"
#include "../../Component.h"
#include "MainBoard.h"
using namespace components;
int main(int argc, char *argv[])
{
    Component *base = new MainBoard();
    MachineControler* m = new MachineControler(base->getClock());
    m->runLoop(base);
    qDebug()<<"hi :)";
    return 0;
}
