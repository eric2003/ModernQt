#include "dragableform.h"
#include "ui_dragableform.h"
#include <QMouseEvent>
#include <QMimeData>
#include <QDrag>
#include <QPainter>

DragableForm::DragableForm(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::DragableForm)
{
    ui->setupUi(this);
    this->setAcceptDrops(true);
}

DragableForm::~DragableForm()
{
    delete ui;
}

void DragableForm::mousePressEvent(QMouseEvent *event)
{
    QWidget * widget = this->childAt( event->position().toPoint());
    QLabel * child = dynamic_cast<QLabel *>( widget );
    if ( !child )
    {
        return;
    }
    QPixmap pixmap = child->pixmap();
    QByteArray itemData;
    QDataStream dataStream( &itemData, QIODevice::WriteOnly );
    dataStream << pixmap << QPoint( event->position().toPoint() - child->pos() );

    QMimeData * mimeData = new QMimeData();
    mimeData->setData("application/x-dnditedata", itemData);

    QDrag * drag = new QDrag( this );
    drag->setMimeData( mimeData );
    drag->setPixmap( pixmap );
    drag->setHotSpot( event->position().toPoint() - child->pos() );

    QPixmap tmpPixmap = pixmap;
    QPainter painter;
    painter.begin( & tmpPixmap );
    painter.fillRect( pixmap.rect(), QColor(127,127,127,127) );
    painter.end();

    child->setPixmap( tmpPixmap );

    if ( drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction ) == Qt::MoveAction )
    {
        child->close();
    }
    else
    {
        child->setPixmap( pixmap );
    }


}

void DragableForm::dragEnterEvent(QDragEnterEvent *event)
{
    if ( event->mimeData()->hasFormat( "application/x-dnditedata" ) )
    {
        if ( event->source() == this )
        {
            event->setDropAction( Qt::MoveAction );
            event->accept();
        }
        else
        {
            event->acceptProposedAction();
        }
    }
    else
    {
        event->ignore();
    }
}

void DragableForm::dropEvent(QDropEvent *event)
{
    if ( event->mimeData()->hasFormat( "application/x-dnditedata" ) )
    {
        QByteArray itemData = event->mimeData()->data( "application/x-dnditedata" );
        QDataStream dataStream( &itemData, QIODevice::ReadOnly );

        QPixmap pixmap;
        QPoint offset;
        dataStream >> pixmap >> offset;

        QLabel *newIcon = new QLabel( this );
        newIcon->setPixmap( pixmap );
        newIcon->move( event->position().toPoint() - offset );
        newIcon->show();

        if ( event->source() == this )
        {
            event->setDropAction( Qt::MoveAction );
            event->accept();
        }
        else
        {
            event->acceptProposedAction();
        }

    }
    else
    {
        event->ignore();
    }
}

