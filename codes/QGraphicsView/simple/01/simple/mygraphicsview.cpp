#include "mygraphicsview.h"
#include <QMouseEvent>
#include <QLabel>

MyGraphicsView::MyGraphicsView(QWidget *parent)
    : QGraphicsView{parent}
{
}

void MyGraphicsView::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton){
        QPoint point = event->pos();
        emit mouseClicked(point);
    }
    QGraphicsView::mousePressEvent(event);
}

void MyGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    QPoint point = event->pos();
    emit mouseMovePoint(point);
    QGraphicsView::mouseMoveEvent(event);
}
