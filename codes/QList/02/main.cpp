#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString str = QString::fromLocal8Bit( "����1" );
    qDebug() << "str = " << str;
    qDebug() << QString::fromLocal8Bit("����");
    QList<QString> authors = { "����","����","����" };

    for ( int i = 0; i < authors.size(); ++ i )
    {
        qDebug() << authors.at( i );
    }

    return a.exec();
}

