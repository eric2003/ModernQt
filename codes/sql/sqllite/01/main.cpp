#include <QCoreApplication>
#include <QtSql>
#include <QDebug>
#include <QString>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

	QStringList drivers = QSqlDatabase::drivers();
	qDebug() << "haha";
	foreach ( QString driver, drivers )
	{
		qDebug() << driver;
	}


    return a.exec();
}
