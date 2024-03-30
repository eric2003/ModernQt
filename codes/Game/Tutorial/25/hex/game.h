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
    QString getWhosTurn();
    void setWhosTurn(QString player);
public slots:
    void start();
private:
    void drawPanel(int x, int y, int width, int height, QColor color, double opacity);
    void drawGUI();
public:
    //public attributes
    QGraphicsScene * scene;

    HexBoard *hexBoard;
    QString whosTurn;
    QGraphicsTextItem * whosTurnTextItem;

};

#endif // GAME_H
