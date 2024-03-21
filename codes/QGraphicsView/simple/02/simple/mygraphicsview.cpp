#include "mygraphicsview.h"
#include <QMouseEvent>
#include <QLabel>

MyGraphicsView::MyGraphicsView(QWidget *parent)
    : QGraphicsView{parent}
{
}

void MyGraphicsView::keyPressEvent(QKeyEvent *event)
{
    emit keyPress(event);
    QGraphicsView::keyPressEvent(event);
}

void MyGraphicsView::keyReleaseEvent(QKeyEvent *event)
{
    QGraphicsView::keyReleaseEvent(event);
}

void MyGraphicsView::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton){
        QPoint point = event->pos();
        emit mouseDoubleClicked(point);
    }
    QGraphicsView::mouseDoubleClickEvent(event);

}

void MyGraphicsView::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton){
        QPoint point = event->pos();
        emit mouseClicked(point);
    }
    QGraphicsView::mousePressEvent(event);
}

// void MyGraphicsView::mouseMoveEvent(QMouseEvent *event)
// {
//     QPoint point = event->pos();
//     emit mouseMovePoint(point);
//     QGraphicsView::mouseMoveEvent(event);
// }

void MyGraphicsView::mouseReleaseEvent(QMouseEvent *event)
{

}
