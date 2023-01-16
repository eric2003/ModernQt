#include <QApplication>
#include <QDate>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDateTime dt;
    dt.setSecsSinceEpoch( 0 );
    qDebug() << dt.toString();
    dt.setSecsSinceEpoch( time(0) );
    qDebug() << dt.toString();

    QDateTime cd = QDateTime::currentDateTime();
    qDebug() << cd.toString();
    qDebug() << time(0);
    qDebug() << cd.toSecsSinceEpoch();

    return a.exec();
}
