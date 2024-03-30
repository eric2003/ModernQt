#ifndef TOWER_H
#define TOWER_H

#include <QGraphicsPixmapItem>

class Tower: public QGraphicsPixmapItem{
public:
    Tower();

private:
    QGraphicsPolygonItem * attack_area;
};

#endif // TOWER_H
