#include "widget.h"
#include <QApplication>
#include <QFile>
int main(int argc, char *argv[])
{
    QApplication a( argc, argv );
    Widget w;
    w.resize( 250, 150 );
    w.setWindowTitle( "一个简单的例子" );
    w.setToolTip( "这是一个QWidget" );
    w.setWindowIcon( QIcon( "../images/myico.ico" ) );


    QFile stylefile( "../myStyle.css" );
    stylefile.open( QIODevice::ReadOnly );
    QString stylesheet = QString::fromLatin1( stylefile.readAll() );
    a.setStyleSheet( stylesheet );

    w.show();

    return a.exec();
}
