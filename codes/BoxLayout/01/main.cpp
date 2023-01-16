#include <QApplication>
#include <QTextEdit>

class Widget : public QWidget
{
public:
    Widget( QWidget * parent = nullptr );
};

Widget::Widget( QWidget * parent ) : QWidget( parent )
{
    auto *ledit = new QTextEdit( this );
    ledit->setGeometry( 5, 5, 200, 150 );
}

int main(int argc, char *argv[])
{
    QApplication a( argc, argv );
    Widget w;
    w.setWindowTitle( "Absolute" );
    w.show();
    return a.exec();
}
