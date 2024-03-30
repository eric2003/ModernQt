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

void Game::start()
{
    // clear the screen
    this->scene->clear();

    this->hexBoard = new HexBoard();
    this->hexBoard->placeHexes(100,100,5,5);
}
