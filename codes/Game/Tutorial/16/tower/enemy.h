#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>

class Enemy : public QObject, public QGraphicsPixmapItem
{
public:
    Enemy(QList<QPointF> pointsToFollow);
public:
    void rotateToPoint(QPointF p);
public slots:
    void move_forward();
private:
    QList<QPointF> points;
    QPointF dest;
    int point_index;
};

#endif // ENEMY_H
