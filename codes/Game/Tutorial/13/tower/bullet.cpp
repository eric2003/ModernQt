#include "bullet.h"
#include <QPixmap>
#include <QTimer>

Bullet::Bullet() {
    // set graphics
    this->setPixmap(QPixmap(":images/bullet.png"));

    // connect a tiner to move()
    QTimer * move_timer = new QTimer(this);
    QObject::connect(move_timer, &QTimer::timeout,this,&Bullet::move);
    move_timer->start(500);

}

void Bullet::move()
{
    int STEP_SIZE = 30;
    qreal theta = qDegreesToRadians( this->rotation() ); //rotation degrees
    double dy = STEP_SIZE * sin(theta);
    double dx = STEP_SIZE * cos(theta);
    this->setPos(this->x()+dx, this->y()+dy);

}
