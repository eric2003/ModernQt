#include <QApplication>
#include <QDate>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QList<QDate> dates{ QDate(2020,5,11), QDate(2020,8,1), QDate(2020,2,30) };
    for ( int i = 0; i < dates.size(); ++ i )
    {
        if ( dates.at(i).isValid() )
        {
            qDebug() << "Date " << i + 1 << " is a valid date";
        }
        else
        {
            qDebug() << "Date " << i + 1 << " is not a valid date";
        }
    }
    return a.exec();
}
