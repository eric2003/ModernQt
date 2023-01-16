#include <QApplication>
#include <QDate>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDate cd = QDate::currentDate();
    QTime ct = QTime::currentTime();
    qDebug() << "Current date is " << cd.toString();
    qDebug() << "Current time is " << ct.toString();

    return a.exec();
}
