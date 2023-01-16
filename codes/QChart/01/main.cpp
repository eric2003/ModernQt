#include "mainwindow.h"

#include <QApplication>
#include <QIcon>
#include <QFile>
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QFile file( "../images/printer.png" );
    qDebug() << "QDir::currentPath() = " << QDir::currentPath();
    if ( !file.open(QIODevice::ReadOnly ))
    {
        qDebug() << "not open";
    }
    else
    {
        qDebug() << "open";
    }
    w.setWindowIcon( QIcon("../images/printer.png") );
    //w.setWindowIcon( QIcon("../images/boat.png") );
    w.setWindowTitle("QChart");
    w.resize( 400, 300 );
    w.show();
    return a.exec();
}
