#include <QCoreApplication>
#include "mythread.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MyThread mThread1;
    mThread1.name = "mThread1";
    mThread1.start();
    MyThread mThread2;
    mThread2.name = "mThread2";
    mThread2.start();
    MyThread mThread3;
    mThread3.name = "mThread3";
    mThread3.start();

    return a.exec();
}
