#include "enemy.h"
#include <QTimer>

Enemy::Enemy(QList<QPointF> pointsToFollow) {
    // set graphics
    this->setPixmap( QPixmap(":/images/enemy.png") );

    // set points
    //this->points << QPointF(200,200) << QPointF(400,200); // move down-right the right
    this->points << pointsToFollow;
    this->point_index = 0;
    this->dest = this->points[0];
    this->rotateToPoint(this->dest);

    // connect timer to move_forward
    QTimer * timer = new QTimer(this);
    QObject::connect(timer, &QTimer::timeout,this,&Enemy::move_forward);
    timer->start(150);
}

void Enemy::rotateToPoint(QPointF p)
{
    QLineF myline(this->pos(), p);
    this->setRotation(-1 * myline.angle() );

}

void Enemy::move_forward()
{
    // if close to the dest, rotate to next dest
    QLineF myline(this->pos(),dest);
    if ( myline.length() < 5 ){
        this->point_index ++;
        if( this->point_index >= this->points.size() )
        {
            return;
        }
        this->dest = this->points[ this->point_index ];
        this->rotateToPoint(this->dest);
    }
    // move emeny forward at current angle
    int STEP_SIZE = 5;
    double theta_degree = this->rotation(); //degree
    double theta = qDegreesToRadians(theta_degree);

    double dx = STEP_SIZE * cos(theta);
    double dy = STEP_SIZE * sin(theta);

    this->setPos(this->x()+dx,this->y()+dy);
}
