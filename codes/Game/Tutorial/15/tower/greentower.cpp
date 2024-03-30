#include "greentower.h"
#include "bullet.h"
#include "game.h"
#include <QTimer>

extern Game * game;

GreenTower::GreenTower() {
    // connect a timer to attack_target
    QTimer * timer = new QTimer();
    QObject::connect(timer,&QTimer::timeout,this,&Tower::acquireTarget);
    timer->start(1000);
}

void GreenTower::fire()
{
    // create the bullets
    Bullet * bullet1 = new Bullet();
    Bullet * bullet2 = new Bullet();
    Bullet * bullet3 = new Bullet();

    // set the graphics
    bullet1->setPixmap(QPixmap(":/images/bullet2.png"));
    bullet2->setPixmap(QPixmap(":/images/bullet2.png"));
    bullet3->setPixmap(QPixmap(":/images/bullet2.png"));

    bullet1->setPos(this->x()+44,this->y()+44);
    bullet2->setPos(this->x()+44,this->y()+44);
    bullet3->setPos(this->x()+44,this->y()+44);

    QLineF myline(QPointF(this->x()+44,this->y()+44),this->attack_dest);
    double angle = -1 * myline.angle();

    bullet1->setRotation(angle);
    bullet2->setRotation(angle+10);
    bullet3->setRotation(angle-10);

    game->scene->addItem(bullet1);
    game->scene->addItem(bullet2);
    game->scene->addItem(bullet3);
}


