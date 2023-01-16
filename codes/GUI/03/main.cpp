#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a( argc, argv );
    Widget w;
    w.resize( 250, 150 );
    w.setWindowTitle( "一个简单的例子" );
    w.setToolTip( "这是一个QWidget" );
    w.setWindowIcon( QIcon( "../images/myico.ico" ) );
    w.show();
    return a.exec();
}
