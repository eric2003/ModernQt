#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>

class Game : public QGraphicsView
{
public:
    //member functions
    Game();

protected:
    void mousePressEvent(QMouseEvent *event) override;

public:
    //member attributes
    QGraphicsScene *scene;
};

#endif // GAME_H
