#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy();
    ~Enemy();
public slots:
    void move();
private:
    QTimer * timer;
};

#endif // ENEMY_H
