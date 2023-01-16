#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString str{ "<\"hello the world!\">" };
    qDebug() << " str = " << str;
    qDebug() << "str.toHtmlEscaped() = " << str.toHtmlEscaped();

    return a.exec();
}

