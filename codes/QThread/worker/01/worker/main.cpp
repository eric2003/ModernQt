#include <QCoreApplication>
#include <QThread>
#include "work.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << "Main Thread ID: " <<QThread::currentThreadId();
    QThread * th = new QThread(&a);
    Work * work = new Work;
    QObject::connect(work, &Work::startWorking, work, &Work::working );
    QObject::connect(th,&QThread::started,&a,[=](){ emit work->startWorking();});
    work->moveToThread(th);
    th->start();


    return a.exec();
}
