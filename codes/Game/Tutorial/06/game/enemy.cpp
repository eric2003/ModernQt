#include "enemy.h"
#include "game.h"
#include "health.h"
#include <QTimer>
#include <QGraphicsScene>

extern Game *game;

Enemy::Enemy() {
    //set random position
    int random_number = rand() % 700;
    this->setPos(random_number,0);
    //drew the rect
    this->setRect(0,0,100,100);
    //connect
    this->timer = new QTimer(this);
    QObject::connect(this->timer, &QTimer::timeout, this, &Enemy::move);

    this->timer->start(50);
}

Enemy::~Enemy()
{
    delete this->timer;
}

void Enemy::move()
{
    //move enemy down
    this->setPos(this->x(),this->y()+5);
    if ( this->pos().y() > 600 ) {
        //decrease the health
        game->health->decrease();
        this->scene()->removeItem(this);
        delete this;
        //qDebug() << "enemy deleted";
    }

}
