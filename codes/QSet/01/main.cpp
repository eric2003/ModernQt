#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextStream out( stdout );
    QSet<QString> cols1 = { "yellow", "red", "blue" };
    QSet<QString> cols2 = { "blue", "pink", "orange" };

    out << "There are " << cols1.size() << " values in the set" << Qt::endl;
    cols1.insert( "brown" );
    out << "There are " << cols1.size() << " values in the set" << Qt::endl;
    cols1.unite( cols2 );
    out << "There are " << cols1.size() << " values in the set" << Qt::endl;
    for ( const QString &val : cols1 )
    {
        out << val <<  Qt::endl;
    }
    QList<QString> lcols( cols1.begin(), cols1.end() );
    std::sort( lcols.begin(), lcols.end() );
    out << "***************************" << Qt::endl;
    out << "Sorted: " << Qt::endl;
    for ( const QString &val : lcols )
    {
        out << val <<  Qt::endl;
    }
    return a.exec();
}
