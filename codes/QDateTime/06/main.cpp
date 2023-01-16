#include <QApplication>
#include <QDate>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDate cd = QDate::currentDate();
    qDebug() << "Today is " << cd.toString("yyyy-MM-dd");
    qDebug() << "Today is " << cd.toString( "yy/M/dd" );
    qDebug() << "Today is " << cd.toString( "d.M.yyyy" );
    qDebug() << "Today is " << cd.toString("d-MMMM-yyyy");
    return a.exec();
}
