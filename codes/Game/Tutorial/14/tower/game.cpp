#include "game.h"
#include "tower.h"
#include "enemy.h"
#include "buildtowericon.h"
#include <QMouseEvent>

Game::Game() {
    // create a scene
    this->scene = new QGraphicsScene(this);

    this->scene->setSceneRect(0,0,800,600);

    // set the scene
    this->setScene(this->scene);

    // create a tower
    Tower * t = new Tower();
    t->setPos(250,250);

    // add the tower to scene
    this->scene->addItem(t);

    // set cursor
    this->cursor = nullptr;
    this->build = nullptr;
    this->setMouseTracking(true);

    this->setFixedSize(800,600);

    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // create enemy
    Enemy *enemy = new Enemy();
    this->scene->addItem(enemy);

    //test code
    //this->setCursor(":/images/bullet.png");
    BuildTowerIcon *ic = new BuildTowerIcon();
    this->scene->addItem(ic);
}

void Game::setCursor(QString filename)
{
    if ( this->cursor ) {
        this->scene->removeItem( this->cursor );
        delete this->cursor;
    }
    this->cursor = new QGraphicsPixmapItem();
    this->cursor->setPixmap(QPixmap(filename));
    this->scene->addItem(this->cursor);

}

void Game::mouseMoveEvent(QMouseEvent *event)
{
    if ( this->cursor ) {
        this->cursor->setPos(event->pos());
    }
}

void Game::mousePressEvent(QMouseEvent *event)
{
    if ( this->build ) {
        this->scene->addItem(this->build);
        this->build->setPos(event->pos());
        this->cursor = nullptr;
        this->build = nullptr;
    }
    else {
        QGraphicsView::mousePressEvent(event);
    }
}
