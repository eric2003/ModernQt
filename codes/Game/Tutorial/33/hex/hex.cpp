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

    // create lines
    this->createLines();

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

int Hex::getAttackOf(int side)
{
    if ( side == 0 ) {
        return this->side0Attack;
    }
    else if ( side == 1 ) {
        return this->side1Attack;
    }
    else if ( side == 2 ) {
        return this->side2Attack;
    }
    else if ( side == 3 ) {
        return this->side3Attack;
    }
    else if ( side == 4 ) {
        return this->side4Attack;
    }
    else if ( side == 5 ) {
        return this->side5Attack;
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

void Hex::setAttackOf(int side, int attack)
{
    // set the attack of the specified side ( and update it's text )
    switch ( side ) {
    case 0:
        this->side0Attack = attack;
        this->attackTexts[0]->setPlainText(QString::number(attack));
        break;
    case 1:
        this->side1Attack = attack;
        this->attackTexts[1]->setPlainText(QString::number(attack));
        break;
    case 2:
        this->side2Attack = attack;
        this->attackTexts[2]->setPlainText(QString::number(attack));
        break;
    case 3:
        this->side3Attack = attack;
        this->attackTexts[3]->setPlainText(QString::number(attack));
        break;
    case 4:
        this->side4Attack = attack;
        this->attackTexts[4]->setPlainText(QString::number(attack));
        break;
    case 5:
        this->side5Attack = attack;
        this->attackTexts[5]->setPlainText(QString::number(attack));
        break;
    default:
        break;
    }

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

void Hex::createLines()
{
    QPointF hexCenter(this->x()+60,this->y()+40);
    QPointF finalPt(hexCenter.x(),hexCenter.y()-65);
    QLineF myline(hexCenter,finalPt);
    const int nSides = 6;
    for( std::size_t i = 0; i < nSides; ++ i ){
        QLineF lineCopy(myline);
        lineCopy.setAngle(90+60*i);
        QGraphicsLineItem * lineItem = new QGraphicsLineItem(lineCopy, this);
        this->lines.append(lineItem);
        lineItem->setVisible(false);
    }

}

void Hex::findNeighbors()
{
    for ( std::size_t i = 0; i < this->lines.size(); ++ i ){
        // if the line collides with an item of type Hex,add it to neighbors
        QList<QGraphicsItem *> cItems = this->lines[i]->collidingItems();
        for ( std::size_t j = 0; j < cItems.size(); ++ j ){
            Hex *item = dynamic_cast<Hex *>( cItems[j] );
            if ( cItems[j] != this && item ) {
                this->neighbors.append(item);
            }
        }
    }
}

void Hex::switchOwner()
{
    // if the owner is player1, make it player two and vice versa
    if ( this->getOwner() == QString("PLAYER1") ){
        this->setOwner(QString("PLAYER2"));
    }
    else if( this->getOwner() == QString("PLAYER2") ){
         this->setOwner(QString("PLAYER1"));
    }
}

void Hex::captureNeighbors()
{
    // traverses through neighbors, captures weaker neighbors
    for ( std::size_t i = 0; i < this->neighbors.size(); ++ i ){
        bool isEnemy = false;
        bool isNotNeutral = false;

        if ( this->getOwner() != this->neighbors[i]->getOwner() ) {
            isEnemy = true;
        }

        if ( this->neighbors[i]->getOwner() != QString("NOONE")){
            isNotNeutral = true;
        }

        // it is an enemy and not neutral
        if ( isEnemy && isNotNeutral) {
            // find attack of touching side
            int thisAttack = 0;
            int neighborsAttack = 0;
            if ( i == 0 ) {
                thisAttack = this->getAttackOf(i);
                neighborsAttack = this->neighbors[i]->getAttackOf(3);
            }
            else if ( i == 1 ) {
                thisAttack = this->getAttackOf(i);
                neighborsAttack = this->neighbors[i]->getAttackOf(4);
            }
            else if ( i == 2 ) {
                thisAttack = this->getAttackOf(i);
                neighborsAttack = this->neighbors[i]->getAttackOf(5);
            }
            else if ( i == 3 ) {
                thisAttack = this->getAttackOf(i);
                neighborsAttack = this->neighbors[i]->getAttackOf(0);
            }
            else if ( i == 4 ) {
                thisAttack = this->getAttackOf(i);
                neighborsAttack = this->neighbors[i]->getAttackOf(1);
            }
            else if ( i == 5 ) {
                thisAttack = this->getAttackOf(i);
                neighborsAttack = this->neighbors[i]->getAttackOf(2);
            }

            // if this has greater attack, switch neighbors owner
            if ( thisAttack > neighborsAttack ){
                this->neighbors[i]->switchOwner();
            }
        }
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
