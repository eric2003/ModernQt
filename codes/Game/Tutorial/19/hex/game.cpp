#include "game.h"

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

void Game::start()
{

}

