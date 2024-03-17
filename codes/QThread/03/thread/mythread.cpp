#include "mythread.h"
#include <QDebug>
#include <QMutex>


MyThread::MyThread() {}

void MyThread::run()
{
    qDebug() << this->name << " Running";
    for( int i = 0; i < 1000; ++ i )
    {
        QMutex mutex;
        mutex.lock();
        if( this->stop )
        {
            break;
        }
        mutex.unlock();
        qDebug() << this->name << i;
    }
}
