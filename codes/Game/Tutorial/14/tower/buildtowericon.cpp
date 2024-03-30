#include "buildtowericon.h"
#include "game.h"
#include "tower.h"

extern Game *game;

BuildTowerIcon::BuildTowerIcon() {
    this->setPixmap(QPixmap(":/images/towericon.png"));
}

void BuildTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if ( !game->build ) {
        game->build = new Tower();
        game->setCursor(QString(":/images/tower.png"));
    }

}
