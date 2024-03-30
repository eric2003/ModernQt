#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>

class HexBoard;
class Hex;

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
    // private methods
    void drawPanel(int x, int y, int width, int height, QColor color, double opacity);
    void drawGUI();
    void createNewCard(QString player);
    void createInitialCards();
    void drawCards();
private:
    // private attributes
    QString whosTurn;
    QGraphicsTextItem * whosTurnTextItem;
    QList<Hex *> player1Cards;
    QList<Hex *> player2Cards;
public:
    //public attributes
    QGraphicsScene * scene;
    HexBoard *hexBoard;
    Hex * cardToPlace;
};

#endif // GAME_H
