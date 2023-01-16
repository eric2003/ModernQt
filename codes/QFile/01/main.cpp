#include <QFile>
#include <QDebug>

int main(int argc, char *argv[])
{
    if ( argc != 2 )
    {
        qWarning( "请给出文件名称！" );
        return 1;
    }
    QString filename = argv[1];
    QFile f( filename );
    if ( !f.exists() )
    {
        qWarning( "指定的文件不存在！" );
        return 1;
    }
    qDebug() << f.fileName();
    return 0;
}
