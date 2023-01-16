#include <QApplication>
#include <QDate>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDateTime cdt = QDateTime::currentDateTime();
    qDebug() << "The current datetime is " << cdt.toString();
    qDebug() << "The current date is " << cdt.date().toString();
    qDebug() << "The current time is " << cdt.time().toString();
    return a.exec();
}
