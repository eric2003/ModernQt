#include <QCoreApplication>
#include "mythread.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MyThread mThread;
    mThread.start();

    return a.exec();
}
