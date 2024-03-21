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

    QThread * th1 = QThread::create(fun3,std::ref(num1));
    th1->start();

    int num2 = 2000;

    QThread * th2 = QThread::create(fun3,std::ref(num2));
    th2->start();

    /*

    const int num3 = 3000;

    QThread * th3 = QThread::create(fun3,std::ref(num3));
    th3->start();
   */

    return a.exec();
}
