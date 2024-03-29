#include "renderarea.h"
#include "ui_renderarea.h"
#include <QPainterPath>
#include <QPainter>

RenderArea::RenderArea(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RenderArea)
{
    this->shape = Polygon;
    this->antialiased = false;
    this->transformed = false;
    this->pixmap.load("../images/boat.png");
    ui->setupUi(this);
    this->setBackgroundRole( QPalette::Base );
    this->setAutoFillBackground( true );
}

RenderArea::~RenderArea()
{
    delete ui;
}


void RenderArea::setShape( RenderArea::Shape shape )
{
    this->shape = shape;
    this->update();
}

void RenderArea::setPen( const QPen &pen )
{
    this->pen = pen;
    this->update();
}

void RenderArea::setBrush( const QBrush &brush )
{
    this->brush = brush;
    this->update();
}

void RenderArea::setAntialiased( bool antialiased )
{
    this->antialiased = antialiased;
    this->update();
}

void RenderArea::setTransformed( bool transformed )
{
    this->transformed = transformed;
    this->update();
}


void RenderArea::paintEvent( QPaintEvent *event )
{
    static const QPoint points[4] = {
        QPoint(10, 80),
        QPoint(20, 10),
        QPoint(80, 30),
        QPoint(90, 70)
    };

    QRect rect( 10, 20, 80, 60 );
    QPainterPath path;
    path.moveTo( 20, 80 );
    path.lineTo( 20, 30 );
    path.cubicTo( 80, 0, 50, 50, 80, 80 );

    int startAngle = 20 * 16;
    int arcLength = 120 * 16;

    QPainter painter( this );
    painter.setPen( pen );
    //painter.setBackground( brush );
    painter.setBrush( this->brush );
    if ( this->antialiased )
    {
        painter.setRenderHint( QPainter::Antialiasing, true );
    }

    for ( int x = 0; x < width(); x += 100 )
    {
        for ( int y = 0; y < height(); y += 100 )
        {
            painter.save();
            painter.translate( x, y );
            if ( this->transformed )
            {
                painter.translate( 50, 50 );
                painter.rotate( 60.0 );
                painter.scale( 0.6, 0.9 );
                painter.translate( -50, -50 );
            }
            switch ( shape )
            {
            case Line:
                painter.drawLine( rect.bottomLeft(), rect.topRight() );
                break;
            case Points:
                painter.drawPoints( points, 4 );
                break;
            case Polyline:
                painter.drawPolyline( points, 4 );
                break;
            case Polygon:
                painter.drawPolygon( points, 4 );
                break;
            case Rect:
                painter.drawRect( rect );
                break;
            case RoundedRect:
                painter.drawRoundedRect( rect, 25, 25, Qt::RelativeSize );
                break;
            case Ellipse:
                painter.drawEllipse( rect );
                break;
            case Arc:
                painter.drawArc( rect,  startAngle, arcLength );
                break;
            case Chord:
                painter.drawChord( rect,  startAngle, arcLength );
                break;
            case Pie:
                painter.drawPie( rect,  startAngle, arcLength );
                break;
            case Path:
                painter.drawPath( path );
                break;
            case Text:
                painter.drawText( rect, Qt::AlignCenter, "Qt by \nThe Qt Company" );
                break;
            case Pixmap:
                painter.drawPixmap( 10, 10, this->pixmap );
                break;
            }

            painter.restore();
        }
    }

}
