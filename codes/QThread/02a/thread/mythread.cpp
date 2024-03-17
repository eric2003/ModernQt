#include "mythread.h"
#include <QDebug>

MyThread::MyThread() {}

void MyThread::run()
{
    qDebug() << this->name << " Running";
    for( int i = 0; i < 1000; ++ i )
    {
        qDebug() << this->name << i;

    }
}
