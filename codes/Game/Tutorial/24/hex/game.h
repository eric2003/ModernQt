#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>

class HexBoard;

class Game : public QGraphicsView
{
public:
    //constructors
    Game();

public:
    // public methods
    void displayMainMenu();
public slots:
    void start();
public:

    //public attributes
    QGraphicsScene * scene;

    HexBoard *hexBoard;
    QString whosTurn;

};

#endif // GAME_H
