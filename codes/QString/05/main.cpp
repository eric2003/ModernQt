#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString str = {"The night train"};
    qDebug() << "str.right( 5 ) = " << str.right( 5 );
    qDebug() << "str.left( 9 ) = " << str.left( 9 );
    qDebug() << "str.mid( 4, 5 ) = " << str.mid( 4, 5 );

    return a.exec();
}

