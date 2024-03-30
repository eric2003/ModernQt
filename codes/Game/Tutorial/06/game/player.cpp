#include <QKeyEvent>
#include <QGraphicsScene>
#include "player.h"
#include "bullet.h"
#include "enemy.h"

Player::Player() {}

void Player::keyPressEvent(QKeyEvent *event)
{
    //qDebug() << "Myrect knows that you pressed a key";
    switch ( event->key() ) {
    case Qt::Key_Left:
    {
        if ( this->pos().x() > 0 )
        {
            this->setPos(this->x()-10,this->y());
        }
        break;
    }
    case Qt::Key_Right:
    {
        if ( this->pos().x() + this->rect().width() < 800 )
        {
            this->setPos(this->x()+10,this->y());
        }

        break;
    }
    // case Qt::Key_Up:
    // {
    //     this->setPos(this->x(),this->y()-10);
    //     break;
    // }
    // case Qt::Key_Down:
    // {
    //     this->setPos(this->x(),this->y()+10);
    //     break;
    // }
    case Qt::Key_Space:
    {
        //create a bullet
        Bullet * bullet = new Bullet();
        //qDebug() << "bullet created";
        bullet->setPos(this->x(),this->y());
        this->scene()->addItem(bullet);
        break;
    }
    default:
        break;
    }

}

void Player::spawn()
{
    //create an enemy
    Enemy *enemy = new Enemy();
    this->scene()->addItem(enemy);

}
