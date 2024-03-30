#include "game.h"
#include "tower.h"
#include "bullet.h"
#include <QMouseEvent>

Game::Game() {
    // create a scene
    this->scene = new QGraphicsScene(this);

    this->scene->setSceneRect(0,0,800,600);

    // set the scene
    this->setScene(this->scene);

    // create a tower
    Tower * t = new Tower();

    // add the tower to scene
    this->scene->addItem(t);

    this->setFixedSize(800,600);

    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void Game::mousePressEvent(QMouseEvent *event)
{
    // create a bullet
    Bullet * bullet = new Bullet();
    bullet->setPos( event->pos() );
    this->scene->addItem( bullet );
    //qDebug() << " mouse pressed ";

}
