#include "button.h"
#include <QBrush>
#include <QGraphicsTextItem>


Button::Button(QString name)
{
    // draw the rect
    this->setRect(0,0,200,50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    this->setBrush(brush);

    // draw the text
    this->text = new QGraphicsTextItem(name);
    int xPos = this->rect().width()/2 - this->text->boundingRect().width()/2;
    int yPos = this->rect().height()/2 - this->text->boundingRect().height()/2;
    this->text->setPos(xPos,yPos);

    // allow responding to hover events
    this->setAcceptHoverEvents(true);

}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{

}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{

}
