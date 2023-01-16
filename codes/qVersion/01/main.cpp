#include <QCoreApplication>
#include <QDebug>
//#include <QString>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << " qVersion() = " << qVersion();

    return a.exec();
}
