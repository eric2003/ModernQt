#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextStream out( stdout );
    out.setEncoding( QStringConverter::System );
    QString str{ "I have a dream!" };
    for ( QChar qc: str )
    {
        out << qc << " ";
    }
    out << Qt::endl;

    for ( QChar *it = str.begin(); it != str.end(); ++ it )
    {
        out << *it << " ";
    }
    out << Qt::endl;

    for (int i = 0; i < str.size(); ++ i )
    {
        out << str.at(i) << " ";
    }
    out << Qt::endl;

    return a.exec();
}

