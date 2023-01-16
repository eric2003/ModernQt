#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString str = QString::fromLocal8Bit( "哈哈1" );
    qDebug() << "str = " << str;
    qDebug() << QString::fromLocal8Bit("哈哈");
    QList<QString> authors = { "张三","李四","王五" };

    for ( int i = 0; i < authors.size(); ++ i )
    {
        qDebug() << authors.at( i );
    }

    return a.exec();
}

