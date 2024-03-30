#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>

Bullet::Bullet() {
    //drew the rect
    this->setRect(0,0,10,50);
    //connect
    this->timer = new QTimer();
    QObject::connect(this->timer, &QTimer::timeout,this,&Bullet::move);

    this->timer->start(50);
}

Bullet::~Bullet()
{
    delete this->timer;
}

void Bullet::move()
{
    //move bullet up
    this->setPos(this->x(),this->y()-10);
    if( this->pos().y() < 0 ) {
        this->scene()->removeItem(this);
        delete this;
        qDebug() << "bullet deleted";
    }

}
