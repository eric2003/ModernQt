#include "widget.h"
#include <QPainter>
#include <QTime>

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
    static const QPoint hourHand[ 3 ] = { QPoint( 7, 8 ), QPoint( -7, 8 ), QPoint( 0, -40 ) };
    static const QPoint minuteHand[ 3 ] = { QPoint( 7, 8 ), QPoint( -7, 8 ), QPoint( 0, -70 ) };
    static const QPoint secHand[ 3 ] = { QPoint( 2, 8 ), QPoint( -2, 8 ), QPoint( 0, -80 ) };
    QColor hourColor( 127, 0, 127 );
    QColor minuteColor( 0, 127, 127, 191 );
    QColor secColor( 127, 127, 0, 100 );

    QTime time = QTime::currentTime();
    QPainter painter( this );
    painter.setRenderHint( QPainter::Antialiasing );
    painter.translate( width() / 2, height() / 2 );
    painter.setPen( Qt::NoPen );

    painter.save();
    painter.setBrush( hourColor );
    painter.rotate( 30 * ( time.hour() + time.minute() / 60.0 ) );
    painter.drawPolygon( hourHand, 3 );
    painter.restore();

    painter.save();
    painter.setBrush( minuteColor );
    painter.rotate( 6 * ( time.minute() + time.second() / 60.0 ) );
    painter.drawPolygon( minuteHand, 3 );
    painter.restore();

    painter.save();
    painter.setBrush( secColor );
    painter.rotate( 6 * time.second() );
    painter.drawPolygon( secHand, 3 );
    painter.restore();

    for ( int i = 0; i < 60; ++ i )
    {
        if ( i % 5 == 0 )
        {
            painter.setPen( hourColor );
            painter.drawLine( 90, 0, 98, 0 );
        }
        else
        {
            painter.setPen( minuteColor );
            painter.drawLine( 92, 0, 96, 0 );
        }
        painter.rotate( 6.0 );
    }
}
