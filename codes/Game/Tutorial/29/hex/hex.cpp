#include "hex.h"
#include "game.h"
#include <QBrush>

extern Game *game;

Hex::Hex() {
    // draw the polygon
    // points needed to draw hexagon:
    // (1,0),(2,0),(3,1),(2,2),(1,2),(0,1)
    QVector<QPointF> hexPoints;
    hexPoints << QPointF(1,0) << QPointF(2,0) << QPointF(3,1)
              << QPointF(2,2) << QPointF(1,2) << QPointF(0,1);

    // scale the points
    int SCALE_BY = 40;
    for ( size_t i = 0; i < hexPoints.size(); ++ i )
    {
        hexPoints[i] *= SCALE_BY;
    }

    // create a polygon with the scaled points
    QPolygonF hexagon(hexPoints);

    // draw the polygon
    this->setPolygon(hexagon);
}

QString Hex::getOwner()
{
    return this->owner;
}

bool Hex::getIsPlaced()
{
    return this->isPlaced;
}

void Hex::setOwner(QString player)
{
    // set the owner
    this->owner = player;

    // change the color
    if ( player == QString("NOONE") ) {
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(Qt::lightGray);
        this->setBrush(brush);
    }

    if ( player == QString("PLAYER1") ) {
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(Qt::blue);
        this->setBrush(brush);
    }

    if ( player == QString("PLAYER2") ) {
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(Qt::red);
        this->setBrush(brush);
    }
}

void Hex::setIsPlaced(bool b)
{
    this->isPlaced = b;
}

void Hex::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    // if this hex is NOT placed ( so it is a card ) then pick it up
    if ( !this->getIsPlaced() ) {
        game->pickUpCard(this);
    }
    else {
        // if this hex IS placed, then replace it
        game->placeCard(this);
    }
}
