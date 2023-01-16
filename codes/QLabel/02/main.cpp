#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a( argc, argv );
    Widget w;
    w.resize( 300, 190 );
    w.setWindowTitle( "Plus minus" );
    w.setWindowIcon( QIcon( "../images/myico.ico" ) );
    w.show();
    return a.exec();
}
