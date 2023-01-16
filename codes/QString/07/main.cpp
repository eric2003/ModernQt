#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    const int STR_EQUAL = 0;
    QString str1{ "Rain" };
    QString str2{ "rain" };
    QString str3{ "rain\n" };
    if ( QString::compare( str1, str2 ) == STR_EQUAL )
    {
        qDebug() << " str1 == str2 ";
    }
    else
    {
        qDebug() << " str1 != str2 ";
    }
    qDebug() << " Case insensitive results: ";

    if ( QString::compare( str1, str2, Qt::CaseInsensitive ) == STR_EQUAL )
    {
        qDebug() << " str1 == str2 ";
    }
    else
    {
        qDebug() << " str1 != str2 ";
    }

    if ( QString::compare( str2, str3 ) == STR_EQUAL )
    {
        qDebug() << " str2 == str3 ";
    }
    else
    {
        qDebug() << " str2 != str3 ";
    }
    str3.chop( 1 );
    qDebug() << " delete return char";
    if ( QString::compare( str2, str3 ) == STR_EQUAL )
    {
        qDebug() << " str2 == str3 ";
    }
    else
    {
        qDebug() << " str2 != str3 ";
    }

    return a.exec();
}

