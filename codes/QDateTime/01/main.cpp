#include <QApplication>
#include <QDate>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDate dt1{ 2020,4,12 };
    qDebug() << "The date is " << dt1.toString();
    QDate dt2;
    dt2.setDate( 2020, 3, 2 );
    qDebug() << "The date is " << dt2.toString();

    QTime tm1{ 17,30,12,55 };
    qDebug() << "The time is " << tm1.toString();

    QTime tm2;
    tm2.setHMS( 13, 52, 45, 155 );
    qDebug() << "The time is " << tm2.toString();

    return a.exec();
}
