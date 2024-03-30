#ifndef BUILDBROWNTOWERICON_H
#define BUILDBROWNTOWERICON_H

#include <QGraphicsPixmapItem>

class BuildBrownTowerIcon : public QGraphicsPixmapItem
{
public:
    BuildBrownTowerIcon();
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // BUILDBROWNTOWERICON_H
