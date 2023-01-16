#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString str{ "Lovely" };
    str.append( " season" );
    qDebug() << "str = " << str;
    str.remove( 10, 3 );
    qDebug() << "str = " << str;
    str.replace( 7, 3, "gril" );
    qDebug() << "str = " << str;
    str.clear();

    if ( str.isEmpty() )
    {
        qDebug() << "The string is empty";
    }

    return a.exec();
}

