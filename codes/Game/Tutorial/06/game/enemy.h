#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsRectItem>
#include <QObject>

class Enemy : public QObject, public QGraphicsRectItem
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
