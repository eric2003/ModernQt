#include <QApplication>
#include <QDate>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDate cd = QDate::currentDate();
    int wd = cd.dayOfWeek();
    QLocale locale( QLocale( "zh_CN" ) );
    qDebug() << "今天是" << locale.dayName( wd );
    qDebug() << "今天是" << locale.dayName( wd, QLocale::ShortFormat );
    QLocale usa( QLocale( "en_US" ) );
    qDebug() << "Today is " << usa.dayName( wd );
    qDebug() << "Today is " << usa.dayName( wd, QLocale::ShortFormat );
    return a.exec();
}
