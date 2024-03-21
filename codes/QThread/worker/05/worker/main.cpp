#include <QCoreApplication>
#include <QThread>

void fun()
{
    qDebug() << __FUNCTION__ << QThread::currentThreadId();
}

void funadd( int &result )
{
    for( int i = 1; i <= 100; ++ i )
    {
        result += i;
    }
    qDebug() << __FUNCTION__ << " result = " << result << " " << QThread::currentThreadId();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << "Main Thread ID: " <<QThread::currentThreadId();

    QThread * th1 = QThread::create(fun);
    th1->start();
    QThread * th2 = QThread::create(fun);
    th2->start();

    //QThread * th1 = QThread::create(funadd,sum);
    //th1->start();


    return a.exec();
}
