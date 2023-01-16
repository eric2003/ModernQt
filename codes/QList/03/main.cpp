#include <QApplication>
#include <QCollator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QList<QString> authors = { "张三","李四","王五" };

    for ( int i = 0; i < authors.size(); ++ i )
    {
        qDebug() << authors.at( i );
    }

    authors << "莫言" << "刘慈欣";
    qDebug() << "*****************************************";
    for ( int i = 0; i < authors.size(); ++ i )
    {
        qDebug() << authors.at( i );
    }
    qDebug() << "+++++++++++++++++++++++++++++++++++++++++";
    QLocale cn( QLocale::Chinese );
    QCollator collator( cn );
    std::sort( authors.begin(), authors.end(), collator );
    qDebug() << "按拼音排序：";
    for ( QString &author : authors )
    {
        qDebug() << author;
    }

    return a.exec();
}
