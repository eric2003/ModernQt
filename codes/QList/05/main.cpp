#include <QApplication>
#include <QCollator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString str{"coin, book,cup,pencil,clock,bookmark"};
    qDebug() << "str = " << str;
    QStringList items = str.split(",");
    //QStringListIterator it( items );
    //while ( it.hasNext() )
    //{
    //    qDebug() << it.next().trimmed();
    //}
    QStringList::Iterator it = items.begin();
    while ( it != items.end() )
    {
        qDebug() << ( *it ++ ).trimmed();
    }


    return a.exec();
}
