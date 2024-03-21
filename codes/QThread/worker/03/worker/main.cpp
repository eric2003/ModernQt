#include <QCoreApplication>
#include <QThread>
#include "work.h"

class WorkerThread : public QThread
{
public:
    void run() override
    {
        qDebug() << __FUNCTION__ << QThread::currentThreadId();
    }
};

void fun()
{
    qDebug() << __FUNCTION__ << QThread::currentThreadId();
}

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
    fun();

    WorkerThread worker_th;
    worker_th.start();


    return a.exec();
}
