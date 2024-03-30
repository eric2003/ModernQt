#include "tower.h"
#include "game.h"
#include "enemy.h"
#include "bullet.h"
#include <QPixmap>
#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include <QTimer>

//list of points:(1,0),(2,0),(3,1),(3,2),(2,3),(1,3),(0,2),(0,1)


extern Game * game;

Tower::Tower() {
    // set the graphics
    this->setPixmap(QPixmap(":/images/tower.jpg"));

    //qDebug() << "this->boundingRect().center() = " << this->boundingRect().center();

    // create points vector
    QVector<QPointF> points;

    points << QPoint(1,0) << QPoint(2,0)
           << QPoint(3,1) << QPoint(3,2)
           << QPoint(2,3) << QPoint(1,3)
           << QPoint(0,2) << QPoint(0,1);

    // scale points
    int SCALE_FACTOR = 120;
    size_t n = points.size();
    for( size_t i = 0; i < n; i ++ ){
        points[i] *= SCALE_FACTOR;
    }

    // create a polygon from thease points
    QPolygonF polygon(points);

    // create the QGraphicsPolygonItem
    this->attack_area = new QGraphicsPolygonItem( polygon, this );

    //move the polygon
    QPointF poly_center(1.5,1.5);
    poly_center *= SCALE_FACTOR;

    QLineF line(poly_center, this->boundingRect().center());
    this->attack_area->setPos(this->x()+line.dx(),this->y()+line.dy());

    // connect a timer to attack_target
    QTimer * timer = new QTimer();
    //QObject::connect(timer,&QTimer::timeout,this,&Tower::attackTarget);
    QObject::connect(timer,&QTimer::timeout,this,&Tower::acquireTarget);
    timer->start(1000);

    // set attack_dest
    attack_dest = QPointF(800,0);

}

double Tower::distanceTo(QGraphicsItem *item)
{
    QLineF myline(this->pos(),item->pos());
    return myline.length();

}

void Tower::fire()
{
    Bullet * bullet = new Bullet();
    bullet->setPos(this->x()+25,this->y()+25);

    QLineF myline(QPointF(this->x()+25,this->y()+25),this->attack_dest);
    double angle = -1 * myline.angle();

    bullet->setRotation(angle);
    game->scene->addItem(bullet);
}

void Tower::attackTarget()
{
    Bullet * bullet = new Bullet();
    bullet->setPos(this->x(),this->y());
    QLineF myline(QPointF(this->x(),this->y()), this->attack_dest);

    double angle = -1.0 * myline.angle();
    bullet->setRotation(angle);

    game->scene->addItem(bullet);

}

void Tower::acquireTarget()
{
    // get a list of all items colliding with attack_area
    QList<QGraphicsItem *> colliding_items = attack_area->collidingItems();

    if ( colliding_items.size() == 1 ){
        this->has_target = false;
        return;
    }

    double closest_dist = 300;
    QPointF closest_pt = QPoint(0,0);

    int n = colliding_items.size();

    for ( size_t i = 0; i < n; ++ i ){
        Enemy *enemy = dynamic_cast<Enemy *>(colliding_items[i]);
        if(enemy){
            double this_dist = this->distanceTo(enemy);
            if( this_dist < closest_dist) {

                closest_dist = this_dist;
                closest_pt = colliding_items[i]->pos();
                this->has_target = true;
            }
        }
    }
    this->attack_dest = closest_pt;
    this->fire();
}
