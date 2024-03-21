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


void fun3( int & i )
{
    qDebug() << __FUNCTION__ << " fun3 i = " << i << " " << QThread::currentThreadId();
}

void fun4( int & i )
{
    qDebug() << __FUNCTION__ << " fun4 i step1 = " << i << " " << QThread::currentThreadId();
    i += 1;
    qDebug() << __FUNCTION__ << " fun4 i step2 = " << i << " " << QThread::currentThreadId();
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

    int num1 = 1000;

    QThread * th1 = QThread::create(fun4,std::ref(num1));
    th1->start();

    qDebug() << " num1 = " << num1;

    QThread * th2 = QThread::create(fun4,std::ref(num1));
    th2->start();

    if ( th2->wait() )
    {
        qDebug() << " after th2->wait() num1 = " << num1;
    }

    return a.exec();
}
