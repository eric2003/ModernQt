#ifndef TOWER_H
#define TOWER_H

#include <QGraphicsPixmapItem>

class Tower: public QObject, public QGraphicsPixmapItem{
public:
    Tower();
public slots:
    void attackTarget();
private:
    QGraphicsPolygonItem * attack_area;
    QPointF attack_dest;
};

#endif // TOWER_H
