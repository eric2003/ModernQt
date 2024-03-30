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

protected:
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

public:
    //member attributes
    QGraphicsScene *scene;
    QGraphicsPixmapItem *cursor;
    Tower *build;
};

#endif // GAME_H
