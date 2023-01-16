#include <QApplication>
#include <QCollator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString str{"coin, book,cup,pencil,clock,bookmark"};
    qDebug() << "str = " << str;
    QStringList items = str.split(",");
    //qDebug() << "items = " << items;
    QStringListIterator it( items );
    while ( it.hasNext() )
    {
        qDebug() << it.next().trimmed();
    }


    return a.exec();
}
