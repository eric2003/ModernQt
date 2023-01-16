#include <QApplication>
#include <QDate>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDate cd = QDate::currentDate();
    qDebug() << "Today is " << cd.toString();
    qDebug() << "Today is " << cd.toString(Qt::TextDate);
    qDebug() << "Today is " << cd.toString(Qt::ISODate);
    qDebug() << "Today is " << cd.toString(Qt::RFC2822Date);
    return a.exec();
}
