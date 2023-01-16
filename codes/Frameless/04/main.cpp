#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a( argc, argv );
    Widget w;
    w.setWindowTitle( "TEST" );
    w.setWindowIcon( QIcon( "../images/myico.ico" ) );
    w.show();
    return a.exec();
}
