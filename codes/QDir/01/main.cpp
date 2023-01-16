#include <QDir>
#include <QDebug>

int main(int argc, char *argv[])
{
    QDir dir;
    dir.setFilter( QDir::Files | QDir::Hidden | QDir::NoSymLinks );
    dir.setSorting( QDir::Size | QDir::Reversed );
    QFileInfoList list = dir.entryInfoList();

    qDebug() << " Bytes Filename";
    for ( auto & fileInfo : list ) {
        qDebug() << QString( "%1 %2" ).arg( fileInfo.size(), 10 ).arg(fileInfo.fileName());
    }
    return 0;
}
