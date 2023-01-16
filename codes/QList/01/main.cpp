#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QList<int> vals = { 1,2,3,4,5 };

    qDebug() << " size of vector is " << vals.size();
    qDebug() << " vals.first() = " << vals.first();
    qDebug() << " vals.last() = " << vals.last();
    vals.append( 6 );
    vals.prepend( -1 );
    qDebug() << " Elements = ";
    for ( int val : vals )
    {
        qDebug() << val;
    }

    return a.exec();
}

