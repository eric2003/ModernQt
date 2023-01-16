#include <QFileInfo>
#include <QDateTime>

int main(int argc, char *argv[])
{
    if ( argc != 2 )
    {
        qWarning( "请给出文件名称！！" );
        return 1;
    }
    QString filename = argv[ 1 ];
    QFileInfo fileinfo{ filename };
    QDateTime last_read = fileinfo.lastRead();
    QDateTime last_mod = fileinfo.lastModified();
    qDebug() << " Last read:" << last_read.toString();
    qDebug() << " Last Modified:" << last_mod.toString();
    return 0;
}
