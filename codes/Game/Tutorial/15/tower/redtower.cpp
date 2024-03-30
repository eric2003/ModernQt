#include "redtower.h"
#include "bullet.h"
#include "game.h"
#include <QTimer>

extern Game * game;

RedTower::RedTower() {
    // connect a timer to attack_target
    QTimer * timer = new QTimer();
    QObject::connect(timer,&QTimer::timeout,this,&Tower::acquireTarget);
    timer->start(1000);
}

void RedTower::fire()
{
    Bullet * bullet = new Bullet();
    bullet->setPixmap(QPixmap(":/images/bullet1.png"));
    bullet->setPos(this->x()+44,this->y()+44);

    QLineF myline(QPointF(this->x()+44,this->y()+44),this->attack_dest);
    double angle = -1 * myline.angle();

    bullet->setRotation(angle);
    game->scene->addItem(bullet);
}


