#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    int digits = 0;
    int letters = 0;
    int spaces = 0;
    int puncts = 0;
    QString str{ "7 white, 3 red roses." };
    for ( QChar s : str )
    {
        if ( s.isDigit() )
        {
            digits ++ ;
        }
        else if ( s.isLetter() )
        {
            letters ++;
        }
        else if ( s.isSpace() )
        {
            spaces ++;
        }
        else if ( s.isPunct() )
        {
            puncts ++;
        }
    }
    qDebug() << QString( "There are %1 characters" ).arg( str.count() );
    qDebug() << QString( "There are %1 letters" ).arg( letters );
    qDebug() << QString( "There are %1 digits" ).arg( digits );
    qDebug() << QString( "There are %1 spaces" ).arg( spaces );
    qDebug() << QString( "There are %1 punctuations characters" ).arg( puncts );
    return a.exec();
}

