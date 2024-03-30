#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Bullet : public QObject, public QGraphicsPixmapItem
{
public:
    Bullet();
public slots:
    void move();
    double getMaxRange();
    double getDistanceTravelled();
    void setMaxRange(double rng);
    void setDistanceTravelled(double dist);
private:
    double maxRange;
    double distanceTravelled;

};

#endif // BULLET_H
