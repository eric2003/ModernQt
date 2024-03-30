#include "buildbrowntowericon.h"
#include "game.h"
#include "browntower.h"

extern Game *game;

BuildBrownTowerIcon::BuildBrownTowerIcon() {
    this->setPixmap(QPixmap(":/images/brownicon.png"));
}

void BuildBrownTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if ( !game->build ) {
        game->build = new BrownTower();
        game->setCursor(QString(":/images/brownicon.png"));
    }

}
