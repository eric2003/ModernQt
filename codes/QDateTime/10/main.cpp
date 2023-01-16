#include <QApplication>
#include <QDate>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDate dt{ 2022, 5, 11 };
    QDate nd = dt.addDays( 55 );
    QDate xmas{ 2022, 12, 24 };

    qDebug() << "55 days from " << dt.toString() << " is " << nd.toString();
    qDebug() << "There are " << QDate::currentDate().daysTo( xmas ) << " days till Christmas";
    return a.exec();
}
