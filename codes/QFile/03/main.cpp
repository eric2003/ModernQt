#include <QFile>
#include <QDebug>

int main(int argc, char *argv[])
{
    QTextStream out{ stdout };
    out.setEncoding( QStringConverter::System );
    QString filename = "names.txt";
    QFile f( filename );
    if ( !f.open( QIODevice::WriteOnly ) )
    {
        qWarning( "Cantnot open file" );
        return 1;
    }
    else
    {
        QTextStream out( &f );
        out << "张三" << Qt::endl;
        out << "李四" << Qt::endl;
        out << "王五" << Qt::endl;
    }

    return 0;
}
