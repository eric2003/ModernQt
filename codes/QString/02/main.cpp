#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString str1 = "Abc def";
    QString str2("Abc def 1" );
    QString str3{"Abc def 2"};
    std::string s1{"s1"};
    QString str4 = s1.c_str();
    std::string s2{"s2 abc"};
    QString str5 = QString::fromLatin1( s2.data(), s2.size() );
    char s3[] = "char s3";
    QString str6( s3 );
    qDebug() << "str1 = " << str1;
    qDebug() << "str2 = " << str2;
    qDebug() << "str3 = " << str3;
    qDebug() << "str4 = " << str4;
    qDebug() << "str5 = " << str5;
    qDebug() << "str6 = " << str6;

    return a.exec();
}

