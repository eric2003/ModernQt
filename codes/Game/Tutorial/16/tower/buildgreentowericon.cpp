#include "buildgreentowericon.h"
#include "game.h"
#include "greentower.h"

extern Game *game;

BuildGreenTowerIcon::BuildGreenTowerIcon() {
    this->setPixmap(QPixmap(":/images/greenicon.png"));
}

void BuildGreenTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if ( !game->build ) {
        game->build = new GreenTower();
        game->setCursor(QString(":/images/greenicon.png"));
    }

}
