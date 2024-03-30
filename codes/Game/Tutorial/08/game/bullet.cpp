#include <QTimer>
#include <QGraphicsScene>
#include "bullet.h"
#include "enemy.h"
#include "game.h"
#include "score.h"

extern Game * game; // there is an external global object called game

Bullet::Bullet() {
    //drew the rect
    //this->setRect(0,0,10,50);
    this->setPixmap(QPixmap(":/images/bullet.png"));
    //connect
    this->timer = new QTimer(this);
    QObject::connect(this->timer, &QTimer::timeout,this,&Bullet::move);

    this->timer->start(50);
}

Bullet::~Bullet()
{
    delete this->timer;
}

void Bullet::move()
{
    // if bullet collides with enemy, destroy both
    QList<QGraphicsItem*> colliding_items = this->collidingItems();
    for ( int i = 0; i < colliding_items.size(); ++ i ){
        if( typeid(*(colliding_items[i])) == typeid(Enemy) )
        {
            // increase the score
            game->score->increase();

            //remove both
            this->scene()->removeItem(colliding_items[i]);
            this->scene()->removeItem(this);
            //delete them both
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    // if there was no collision with an Enemy, move the bullet forward
    this->setPos(this->x(),this->y()-10);
    // if the bullet is off the screen, destroy it
    if( this->pos().y() < 0 ) {
        this->scene()->removeItem(this);
        delete this;
        qDebug() << "bullet deleted";
    }
}
