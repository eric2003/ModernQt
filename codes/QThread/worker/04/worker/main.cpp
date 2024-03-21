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

void fun2( int i )
{
    qDebug() << __FUNCTION__ << " i = " << i << " " << QThread::currentThreadId();
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

    QThread * th3 = QThread::create(fun);
    th3->start();

    fun();
    fun2(1234);
    fun2(2345);

    QThread * th4 = QThread::create(fun2,5678);
    th4->start();



    return a.exec();
}
