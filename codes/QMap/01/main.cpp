#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextStream out( stdout );
    QMap<QString, int> items = { {"coin",5}, {"books",3} };
    items.insert( "bottles", 7 );

    QList<int> values( items.cbegin(), items.cend() );
    QList<QString> keys( items.keyBegin(), items.keyEnd());

    out << "Values: " << Qt::endl;

    for ( int val:values )
    {
        out << val <<  Qt::endl;
    }

    out << "Keys: " << Qt::endl;

    for ( const QString &key:keys )
    {
        out << key <<  Qt::endl;
    }

    QMapIterator<QString, int> it( items );
    out << "Pairs: " << Qt::endl;
    while ( it.hasNext() )
    {
        it.next();
        out << it.key() << ":" << it.value() << Qt::endl;
    }

    return a.exec();
}
