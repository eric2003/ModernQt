#include <QCoreApplication>
#include <QtSql>
#include <QDebug>
#include <QString>
#include "MyDataBase.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyDataBase mydb;
    mydb.Run();

    return a.exec();
}
