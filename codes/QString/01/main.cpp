#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString str{"a"};
    str.append( " b" );
    str.prepend( "pre " );
    qDebug() << str;
    qDebug() << "str.count() = " << str.count();
    qDebug() << "str.toUpper() = " << str.toUpper();
    qDebug() << "str.toLower() = " << str.toLower();

    return a.exec();
}

