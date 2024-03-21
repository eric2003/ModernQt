#include <QCoreApplication>
#include <QThread>


void funadd( int & result )
{
    qDebug() << __FUNCTION__ << " funadd result step1 = " << result << " " << QThread::currentThreadId();
    for( int i = 1; i <= 100; ++ i )
    {
        result += i;
    }
    qDebug() << __FUNCTION__ << " funadd result step2 = " << result << " " << QThread::currentThreadId();
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << "Main Thread ID: " <<QThread::currentThreadId();

    int num1 = 0;

    QThread * th1 = QThread::create(funadd,std::ref(num1));
    th1->start();

    qDebug() << " num1 = " << num1;

    QThread * th2 = QThread::create(funadd,std::ref(num1));
    th2->start();

    if ( th2->wait() )
    {
        qDebug() << " after th2->wait() num1 = " << num1;
    }

    return a.exec();
}
