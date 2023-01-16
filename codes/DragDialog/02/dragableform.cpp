#include "dragableform.h"
#include "ui_dragableform.h"
#include <QMouseEvent>
#include <QMimeData>
#include <QDrag>

DragableForm::DragableForm(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::DragableForm)
{
    ui->setupUi(this);
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

}

void DragableForm::dropEvent(QDropEvent *event)
{

}

