#include "game.h"
#include "tower.h"
#include "enemy.h"
#include "buildbrowntowericon.h"
#include "buildredtowericon.h"
#include "buildgreentowericon.h"
#include <QMouseEvent>
#include <QTimer>

Game::Game() {
    // create a scene
    this->scene = new QGraphicsScene(this);

    this->scene->setSceneRect(0,0,800,600);

    // set the scene
    this->setScene(this->scene);

    // set cursor
    this->cursor = nullptr;
    this->build = nullptr;
    this->setMouseTracking(true);

    // alter window
    this->setFixedSize(800,600);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // create enemy
    this->spawnTimer = new QTimer(this);
    this->enemiesSpawned = 0;
    this->maxNumberOfEnemies = 0;
    this->pointsToFollow << QPointF(800,0) << QPointF(450,450) << QPointF(0,600);

    this->createEnemies(5);

    // create road
    this->createRoad();

    //test code
    BuildBrownTowerIcon *bi = new BuildBrownTowerIcon();
    BuildGreenTowerIcon *gi = new BuildGreenTowerIcon();
    BuildRedTowerIcon *ri = new BuildRedTowerIcon();
    this->scene->addItem(bi);
    this->scene->addItem(gi);
    this->scene->addItem(ri);

    gi->setPos(this->x(),this->y()+100);
    ri->setPos(this->x(),this->y()+200);
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

void Game::createEnemies(int numberOfEnemies)
{
    this->enemiesSpawned = 0;
    this->maxNumberOfEnemies = numberOfEnemies;
    QObject::connect(this->spawnTimer,&QTimer::timeout,this,&Game::spawnEnemy);
    this->spawnTimer->start(2000);
}

void Game::createRoad()
{
    size_t N = this->pointsToFollow.size();
    for ( size_t i = 0; i < N-1; ++ i ){
        // create a line connecting the two points
        QLineF line(this->pointsToFollow[i],this->pointsToFollow[i+1]);
        QGraphicsLineItem * lineItem = new QGraphicsLineItem(line);
        this->scene->addItem(lineItem);

        QPen pen;
        pen.setWidth(15);
        pen.setColor(Qt::darkGray);

        lineItem->setPen(pen);
    }

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

void Game::spawnEnemy()
{
    // spawn an enemy
    Enemy * enemy = new Enemy(this->pointsToFollow);
    enemy->setPos(this->pointsToFollow[0]);
    this->scene->addItem(enemy);
    this->enemiesSpawned += 1;


    if ( enemiesSpawned >= maxNumberOfEnemies ) {
        this->spawnTimer->disconnect();
    }

}
