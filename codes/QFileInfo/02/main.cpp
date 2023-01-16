#include <QDir>
#include <QFileInfo>
#include <QDirIterator>

int main(int argc, char *argv[])
{
    QDir dir{ QDir::current() };
    dir.setFilter( QDir::Files | QDir::AllDirs );
    dir.setSorting( QDir::Size | QDir::Reversed );
    qDebug() << QString( "Filename" ).leftJustified( 10 ).append( "bytes" );
    QDirIterator it( dir );
    while ( it.hasNext() )
    {
        QFileInfo fileInfo = it.nextFileInfo();
        QString str = fileInfo.fileName().leftJustified( 10 );
        str.append( QString( "%1" ).arg( fileInfo.size() ) );
        qDebug() << str;
    }
    return 0;
}
