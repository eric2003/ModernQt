#include "buildredtowericon.h"
#include "game.h"
#include "redtower.h"

extern Game *game;

BuildRedTowerIcon::BuildRedTowerIcon() {
    this->setPixmap(QPixmap(":/images/redicon.png"));
}

void BuildRedTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if ( !game->build ) {
        game->build = new RedTower();
        game->setCursor(QString(":/images/redicon.png"));
    }

}
