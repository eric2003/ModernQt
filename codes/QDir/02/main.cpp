#include <QDir>
#include <QDebug>

int main(int argc, char *argv[])
{
    QDir dir;
    if ( dir.mkdir( "mydir" ) )
    {
        qDebug() << "mydir sucessfully created";
    }

    dir.mkdir( "mydir2" );
    if ( dir.exists( "mydir2" ) )
    {
        dir.rename( "mydir2", "newdir" );
    }
    dir.mkpath( "temp/newdir" );
    return 0;
}
