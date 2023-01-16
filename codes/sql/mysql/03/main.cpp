#include <QCoreApplication>
#include <QtSql>
#include <QDebug>
#include <QString>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << "haha";
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL", "first");
    db.setHostName("127.0.0.1"); // Host name
    db.setUserName("root");     // User name
    db.setPassword("123456");   // Password
    db.setPort(3306);           // Port to connect

    if( db.open() == true ) // Open connection
    {
        qDebug() << "first Database Opened!";
        db.exec("create database if not exists cfd_db");
        db.setDatabaseName("cfd_db");
        if ( db.open() == true )
        {
            qDebug() << "cfd_db Database Opened!";
        }
    }
    else
    {
        qDebug() << "Error: " << db.lastError().text();
    }


    return a.exec();
}
