#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>

class Player;
class Score;
class Health;

class Game : public QGraphicsView
{
public:
    Game();
public:
    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Health * health;
};

#endif // GAME_H
