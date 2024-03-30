#include "game.h"
#include "tower.h"

Game::Game() {
    // create a scene
    this->scene = new QGraphicsScene(this);

    // set the scene
    this->setScene(scene);

    // create a tower
    Tower * t = new Tower();

    // add the tower to scene
    scene->addItem(t);

    this->setFixedSize(800,600);
}
