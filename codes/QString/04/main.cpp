#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString str1 = {"Abc%1de"};
    int n = 10;
    qDebug() << "str1.arg( n ) = " << str1.arg( n );
    QString str2 = {"Abc%1de"};
    double h = 1.23;
    qDebug() << "str2.arg( h ) = " << str2.arg( h );

    QString str3 = {"Abc%1de%2fg"};
    int n1 = 2;
    int n2 = 5;
    qDebug() << "str3.arg( n1 ).arg( n2 ) = " << str3.arg( n1 ).arg( n2 );

    return a.exec();
}

