#include <QCoreApplication>
#include <QDebug>
#include <QString>
//#include <QFactoryLoader>
//#include "qfactoryloader_p.h"
#include <QPluginLoader>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << "haha";
	qDebug() << "a.metaObject()->className() = " << a.metaObject()->className();
    qDebug() << "a.applicationFilePath() = " << a.applicationFilePath();
    a.dumpObjectTree();
    a.dumpObjectInfo();

    qDebug() << " qVersion() = " << qVersion();

    return a.exec();
}
