#include "dragableform.h"
#include "ui_dragableform.h"
#include <QMouseEvent>
#include <QMimeData>

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


}

void DragableForm::dragEnterEvent(QDragEnterEvent *event)
{

}

void DragableForm::dropEvent(QDropEvent *event)
{

}

