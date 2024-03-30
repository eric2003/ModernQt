#ifndef TOWER_H
#define TOWER_H

#include <QGraphicsPixmapItem>

class Tower: public QObject, public QGraphicsPixmapItem{
public:
    Tower();
public:
    double distanceTo(QGraphicsItem * item);
    void fire();
public slots:
    void attackTarget();
    void acquireTarget();
private:
    QGraphicsPolygonItem * attack_area;
    QPointF attack_dest;
    bool has_target;
};

#endif // TOWER_H
