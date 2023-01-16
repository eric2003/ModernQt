#include <QApplication>
#include <QDate>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDate dt1{ 2020, 4, 5 };
    QDate dt2{ 2019, 4, 5 };
    if ( dt1 < dt2 )
    {
        qDebug() << dt1.toString() << "comes before " << dt2.toString();
    }
    else
    {
        qDebug() << dt1.toString() << "comes after " << dt2.toString();
    }

    return a.exec();
}
