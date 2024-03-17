#include "mythread.h"
#include <QDebug>

MyThread::MyThread() {}

void MyThread::run()
{
    qDebug() << "Running";
}
