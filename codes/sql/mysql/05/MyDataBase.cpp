#include "MyDataBase.h"
#include <QCoreApplication>
#include <QtSql>
#include <QDebug>
#include <QString>

MyDataBase::MyDataBase()
{
    this->connName = "first";
}

MyDataBase::~MyDataBase()
{
    ;
}

bool MyDataBase::CreateConnDataBase( const QString &connName )
{
    qDebug() << QSqlDatabase::drivers();
    this->db = QSqlDatabase::addDatabase( "QMYSQL", connName );
    this->db.setHostName("127.0.0.1"); // Host name
    this->db.setUserName("root");     // User name
    this->db.setPassword("123456");   // Password
    this->db.setPort(3306);           // Port to connect

    if ( ! this->db.open() )
    {
        qDebug() << "Error: " << this->db.lastError().text();
        return false;
    }
    else
    {
        qDebug() << connName << " Database Opened!";
        return false;
    }
}

bool MyDataBase::CreateNewDataBase( const QString & dataBaseName )
{
    if ( ! this->db.isValid() )
    {
        this->CreateConnDataBase( this->connName );
    }
    QString cs;
    cs.append( "create database if not exists " );
    cs.append( dataBaseName );

    this->db.exec( cs );
    this->db.setDatabaseName( dataBaseName );
    return true;
}

void MyDataBase::Run()
{
    this->CreateNewDataBase( "cfd_db" );

    if ( ! this->db.open() )
    {
        qDebug() << "Error: " << db.lastError().text();
        return;
    }

    QSqlQuery query( this->db );
    QString tableName;
    tableName = "cfdprj";
    QString queryString;
    queryString.append( "create table " );
    queryString.append( tableName );
    queryString.append( " (id int primary key, prjname varchar(255) )" );

    bool flag = false;

    flag = query.exec( queryString );

    qDebug() << "---- insert operation start----";
    this->InsertPrjName( tableName, 1, "naca0012");
    this->InsertPrjName( tableName, 2, "cavity");
    this->QueryTable( tableName );
    qDebug() << "---- insert operation end----- " << "\n ";

}

void MyDataBase::InsertPrjName( const QString & tableName, const int &prjId, const QString &prjName )
{
    QSqlQuery query(db);
    QString queryString;
    queryString.append( "INSERT INTO " );
    queryString.append( tableName );
    queryString.append( "(id, prjname ) VALUES (:id, :prjname)" );

    query.prepare( queryString );
    query.bindValue( ":id", prjId );
    query.bindValue( ":prjname", prjName );
    query.exec();
}

void MyDataBase::QueryTable( const QString & tableName )
{
    QString sql;
    sql.append( "SELECT id, prjname FROM " );
    sql.append( tableName );

    QSqlQuery query( db );
    query.exec( sql );
    while ( query.next() )
    {
        qDebug() << QString("Id: %1, Prjname: %2")
            .arg( query.value("id").toInt() )
            .arg( query.value("prjname").toString() );
    }
}
