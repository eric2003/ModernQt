#include "mythread.h"
#include <QDebug>

MyThread::MyThread() {
}

void MyThread::run()
{
    qDebug() << "Running" << QThread::currentThreadId();
    int num = 0;
    while( true )
    {
        num ++;
        if ( num == 1000000 ){
            break;
        }
        this->msleep(1);
        emit newValue(num);
    }
}
