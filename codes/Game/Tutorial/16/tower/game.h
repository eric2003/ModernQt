#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
class Tower;

class Game : public QGraphicsView
{
public:
    //member functions
    Game();
public:
    void setCursor(QString filename);
    void createEnemies(int numberOfEnemies);
    void createRoad();
protected:
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
public:
    //member attributes
    QGraphicsScene *scene;
    QGraphicsPixmapItem *cursor;
    Tower *build;
    QTimer *spawnTimer;
    int enemiesSpawned;
    int maxNumberOfEnemies;
    QList<QPointF> pointsToFollow;
public slots:
    void spawnEnemy();
};

#endif // GAME_H
