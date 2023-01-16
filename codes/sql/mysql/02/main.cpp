#include <QCoreApplication>
#include <QtSql>
#include <QDebug>
#include <QString>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << "haha";
    //QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL", "first");
    db.setHostName("127.0.0.1"); // Host name
    //db.setDatabaseName("mytmpdb"); // Database name
    db.setUserName("root");     // User name
    db.setPassword("123456");   // Password
    db.setPort(3306);           // Port to connect

    if( db.open() == true ) // Open connection
    {
        qDebug() << "Database Opened!";
    }
    else
    {
        qDebug() << "Error: " << db.lastError().text();
    }


    return a.exec();
}
