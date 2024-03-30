#include "game.h"
#include "hexboard.h"
#include "button.h"
#include <QGraphicsTextItem>
#include <QCoreApplication>

Game::Game() {
    // set up the screen
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setFixedSize(1024,768);

    // set up the scene
    this->scene = new QGraphicsScene();
    this->scene->setSceneRect(0,0,1024,768);
    this->setScene(this->scene);
}

void Game::displayMainMenu()
{
    // create the title text
    QGraphicsTextItem * titleText = new QGraphicsTextItem(QString("Hex Warz"));
    QFont titleFont("comic sans",50);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    this->scene->addItem(titleText);

    // create the play button
    Button * playButton = new Button(QString("Play"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 275;
    playButton->setPos(bxPos, byPos);
    this->scene->addItem(playButton);

    // create the quit button
    Button * quitButton = new Button(QString("Quit"));
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 350;
    quitButton->setPos(qxPos, qyPos);
    this->scene->addItem(quitButton);

    QObject::connect(playButton, &Button::clicked,this,&Game::start);
    QObject::connect(quitButton, &Button::clicked,this,&QCoreApplication::quit);

}

QString Game::getWhosTurn()
{
    return this->whosTurn;
}

void Game::setWhosTurn(QString player)
{
    // change the QString
    this->whosTurn = player;

    // change the QGraphicsTextItem
    whosTurnTextItem->setPlainText(QString("Whos turn: ") + player);
}

void Game::start()
{
    // clear the screen
    this->scene->clear();

    this->hexBoard = new HexBoard();
    this->hexBoard->placeHexes(100,100,5,5);
    this->drawGUI();
}

void Game::drawPanel(int x, int y, int width, int height, QColor color, double opacity)
{
    // draw a panel at the specified location with the specified properties
    QGraphicsRectItem * panel = new QGraphicsRectItem(x,y,width,height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    panel->setBrush(brush);
    panel->setOpacity(opacity);
    this->scene->addItem(panel);

}

void Game::drawGUI()
{
    // draw the left panel
    this->drawPanel(0,0,150,768,Qt::darkCyan,1);

    // draw the right panel
    this->drawPanel(874,0,150,768,Qt::darkCyan,1);

    // place player 1 text
    QGraphicsTextItem *p1 = new QGraphicsTextItem("Player 1's Cards: ");
    p1->setPos(25,0);
    this->scene->addItem(p1);

    // place player 2 text
    QGraphicsTextItem *p2 = new QGraphicsTextItem("Player 2's Cards: ");
    p2->setPos(874+25,0);
    this->scene->addItem(p2);

    // place whosTurnTextItem
    this->whosTurnTextItem = new QGraphicsTextItem();
    this->setWhosTurn(QString("PLAYER1"));
    this->whosTurnTextItem->setPos(490,0);
    this->scene->addItem(this->whosTurnTextItem);
}
