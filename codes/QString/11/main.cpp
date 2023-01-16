#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString str1{ "Name:" };
    QString str2{ "Occupation:" };
    QString str3{ "Residence:" };
    QString str4{ "Marital status:" };
    int width = str4.size();

    qDebug() << str1.rightJustified(width,' ') << "Robert";
    qDebug() << str2.rightJustified(width,' ') << "programmer";
    qDebug() << str3.rightJustified(width,' ') << "New York";
    qDebug() << str3.rightJustified(width,' ') << "single";

    return a.exec();
}

