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

    // initialize
    this->isPlaced = false;

    // initialize side attacks to 0
    this->side0Attack = 0;
    this->side1Attack = 0;
    this->side2Attack = 0;
    this->side3Attack = 0;
    this->side4Attack = 0;
    this->side5Attack = 0;

    // create QGraphicsTextItems to represent visually each side's attack
    QGraphicsTextItem * text0 = new QGraphicsTextItem(QString::number(0),this);
    QGraphicsTextItem * text1 = new QGraphicsTextItem(QString::number(0),this);
    QGraphicsTextItem * text2 = new QGraphicsTextItem(QString::number(0),this);
    QGraphicsTextItem * text3 = new QGraphicsTextItem(QString::number(0),this);
    QGraphicsTextItem * text4 = new QGraphicsTextItem(QString::number(0),this);
    QGraphicsTextItem * text5 = new QGraphicsTextItem(QString::number(0),this);

    this->attackTexts.append(text0);
    this->attackTexts.append(text1);
    this->attackTexts.append(text2);
    this->attackTexts.append(text3);
    this->attackTexts.append(text4);
    this->attackTexts.append(text5);

    text0->setPos(50,0);
    text1->setPos(20,15);
    text2->setPos(20,40);
    text3->setPos(50,55);
    text4->setPos(80,40);
    text5->setPos(80,15);

    // make all attack texts invisible
    for( size_t i = 0; i < this->attackTexts.size(); ++ i ){
        this->attackTexts[i]->setVisible(false);
    }
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

void Hex::displaySideAttacks()
{
    // traverse through all the side_attack texts and make them visible
    for( size_t i = 0; i < this->attackTexts.size(); ++ i ){
        this->attackTexts[i]->setVisible(true);
    }
}

void Hex::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    // if this hex is NOT placed ( so it is a card ) then pick it up
    if ( !this->getIsPlaced()  ) {
        game->pickUpCard(this);
    }
    else {
        // if this hex IS placed, then replace it
        game->placeCard(this);
    }
}
