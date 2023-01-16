#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString s1{ "12" };
    QString s2{ "15" };
    qDebug() << "s1.toInt() + s2.toInt() = " << s1.toInt() + s2.toInt();
    QString s3, s4;
    int n1 = 30;
    int n2 = 40;
    qDebug() << "s3.setNum(n1) + s4.setNum(n2) = " << s3.setNum(n1) + s4.setNum(n2);
    return a.exec();
}

