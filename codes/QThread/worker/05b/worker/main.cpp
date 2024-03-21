#include <QCoreApplication>
#include <QThread>

void fun()
{
    qDebug() << __FUNCTION__ << QThread::currentThreadId();
}

void fun1( int i )
{
    qDebug() << __FUNCTION__ << " fun1 i = " << i << " " << QThread::currentThreadId();
}


void fun2( const int & i )
{
    qDebug() << __FUNCTION__ << " fun2 i = " << i << " " << QThread::currentThreadId();
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

    QThread * th3 = QThread::create(fun1,1234);
    th3->start();

    QThread * th4 = QThread::create(fun1,2345);
    th4->start();

    QThread * th5 = QThread::create(fun2,1234);
    th5->start();

    QThread * th6 = QThread::create(fun2,2345);
    th6->start();

    int m1 = 12345;
    int m2 = 23456;

    QThread * th7 = QThread::create(fun2,m1);
    th7->start();

    QThread * th8 = QThread::create(fun2,m2);
    th8->start();

    return a.exec();
}
