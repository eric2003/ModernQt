#include <QApplication>
#include <QDate>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QList<int> years( {2012,2013,2014,2015,2016,2020,2024} );
    for ( int year : years )
    {
        if ( QDate::isLeapYear( year ) )
        {
            qDebug() << year << " is a leap year";
        }
        else
        {
            qDebug() << year << " is not a leap year";
        }
    }
    return a.exec();
}
