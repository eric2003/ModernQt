#include <QCoreApplication>
#include <QDebug>
#include <QString>
#include "static_lib.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << "haha";
	qDebug() << "a.metaObject()->className() = " << a.metaObject()->className();
    qDebug() << "a.applicationFilePath() = " << a.applicationFilePath();
    a.dumpObjectTree();
    a.dumpObjectInfo();

    qDebug() << " qVersion() = " << qVersion();
	
	Static_lib slib;

    return a.exec();
}
