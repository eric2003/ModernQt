#pragma once
#include <QtSql>
#include <QString>

class MyDataBase
{
public:
    MyDataBase();
    ~MyDataBase();
    QString connName;
    QString dbName;
    QSqlDatabase db;
public:
    bool CreateConnDataBase( const QString & connName );
    bool CreateNewDataBase( const QString & dataBaseName );
    void Run();
public:
    void InsertPrjName( const QString & tableName, const int & prjId, const QString & prjName );
    void DeletePjrRecord( const QString & tableName, const QString & prjName );
    void ModifyPjrRecord( const QString & tableName, const int & prjId, const QString & prjName );
    void QueryPjrRecordByName( const QString & tableName, const QString & prjName );
    void QueryTable( const QString & tableName );
};