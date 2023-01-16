#include "widget.h"
#include <QExposeEvent>
#include <QBackingStore>
#include <QPainter>
#include <QResizeEvent>

Widget::Widget(QWindow *parent)
    : QWindow(parent), m_backingStore( new QBackingStore(this) )
{
}

Widget::~Widget()
{
}

void Widget::exposeEvent( QExposeEvent * )
{
    if ( ! this->isExposed() )
    {
        return;
    }

    QRect rect( 0, 0, width(), height() );
    this->m_backingStore->beginPaint( rect );
    QPaintDevice * device = this->m_backingStore->paintDevice();
    QPainter painter( device );
    painter.fillRect( 0, 0, width(), height(), QGradient::NightFade );
    painter.drawText( QRect( 0, 0, width(), height() ), Qt::AlignCenter, "QWindow" );
    painter.end();
    this->m_backingStore->endPaint();
    this->m_backingStore->flush( rect );
}

void Widget::resizeEvent( QResizeEvent * resizeEvent )
{
    this->m_backingStore->resize( resizeEvent->size() );

}
