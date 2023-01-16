#include <QFile>
#include <QDebug>

int main(int argc, char *argv[])
{
    QFile f( "words.txt" );
    if ( !f.open( QIODevice::ReadOnly ) )
    {
        qWarning( "Cantnot open file for reading" );
        return 1;
    }
    QTextStream in( &f );
    while ( !in.atEnd() )
    {
        QString line = in.readLine();
        qDebug() << line;
    }

    return 0;
}
