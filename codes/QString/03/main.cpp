#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString str = {"Abcde"};
    qDebug() << "str[0] = " << str[0];
    qDebug() << "str[4] = " << str[4];
    qDebug() << "str.at(0) = " << str.at(0);
    qDebug() << "str[5] = " << str[5];

    return a.exec();
}

