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

    QThread * th1 = QThread::create(fun1,1234);
    th1->start();

    QThread * th2 = QThread::create(fun1,2345);
    th2->start();

    QThread * th3 = QThread::create(fun1,3456);
    th3->start();

    QThread * th4 = QThread::create(fun1,4567);
    th4->start();

    QThread * th5 = QThread::create(fun1,456789);
    th5->start();

    QThread * th6 = QThread::create(fun1,4567890);
    th6->start();

    QThread * th7 = QThread::create(fun1,7777);
    th7->start();

    QThread * th8 = QThread::create(fun1,8888);
    th8->start();

    QThread * th9 = QThread::create(fun2,8888);
    th9->start();

    QThread * th10 = QThread::create(fun2,9999);
    th10->start();

    int num1 = 333;

    QThread * th11 = QThread::create(fun1,num1);
    th11->start();

    int num2 = 444;

    QThread * th12 = QThread::create(fun1,num2);
    th12->start();

    int num3 = 3000;

    QThread * th13 = QThread::create(fun2,num3);
    th13->start();

    int num4 = 4000;

    QThread * th14 = QThread::create(fun2,num4);
    th14->start();

    const int num5 = 5000;

    QThread * th15 = QThread::create(fun2,num5);
    th15->start();

    const int num6 = 6000;

    QThread * th16 = QThread::create(fun2,std::ref(num6));
    th16->start();

    return a.exec();
}
