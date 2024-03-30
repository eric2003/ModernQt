#include "game.h"
#include "hex.h"
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

    // initialize
    this->cardToPlace = nullptr;
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
    this->hexBoard->placeHexes(200,30,7,7);
    this->drawGUI();
    this->createInitialCards();
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

void Game::createNewCard(QString player)
{
    // create the card
    Hex * card = new Hex();
    card->setOwner(player);

    // add the card to the proper list
    if ( player == QString("PLAYER1") ) {
        this->player1Cards.append(card);
    }
    else {
        this->player2Cards.append(card);
    }

    // draw the cards
    this->drawCards();
}

void Game::createInitialCards()
{
    int N = 5;
    // create player 1's cards
    for ( size_t i = 0; i < N; ++ i ) {
        this->createNewCard(QString("PLAYER1"));
    }

    // create player 2's cards
    for ( size_t i = 0; i < N; ++ i ) {
        this->createNewCard(QString("PLAYER2"));
    }

    this->drawCards();
}

void Game::drawCards()
{
    // traverse through list of cards and draw them

    // remove all of player1's cards from the scene
    for ( size_t i = 0; i < this->player1Cards.size(); ++ i ){
        this->scene->removeItem( this->player1Cards[i] );
    }

    // remove all of player2's cards from the scene
    for ( size_t i = 0; i < this->player2Cards.size(); ++ i ){
        this->scene->removeItem( this->player2Cards[i] );
    }

    // draw player1's cards
    for ( size_t i = 0; i < this->player1Cards.size(); ++ i ){
        Hex * card = this->player1Cards[i];
        card->setPos(13,25+85*i);
        this->scene->addItem( card );
    }

    // draw player2's cards
    for ( size_t i = 0; i < this->player2Cards.size(); ++ i ){
        Hex * card = this->player2Cards[i];
        card->setPos(874+13,25+85*i);
        this->scene->addItem( card );
    }

}
