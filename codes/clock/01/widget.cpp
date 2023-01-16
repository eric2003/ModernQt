#include "widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->resize( 200, 200 );
}

Widget::~Widget()
{
}

void Widget::paintEvent( QPaintEvent * event )
{
    static const QPoint hourHand[ 3 ] = { QPoint( 7,8 ),QPoint( -7,8 ), QPoint( 0,-40 ) };
    static const QPoint minuteHand[ 3 ] = { QPoint( 7,8 ),QPoint( -7,8 ), QPoint( 0,-70 ) };
    QColor hourColor( 127, 0, 127 );
    QColor minuteColor( 0, 127, 127, 191 );

    QPainter painter( this );
    painter.setRenderHint( QPainter::Antialiasing );
    painter.translate( width() / 2, height() / 2 );
    painter.drawPolygon( hourHand, 3 );
    ;
}
