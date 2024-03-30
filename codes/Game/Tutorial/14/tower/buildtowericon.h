#ifndef BUILDTOWERICON_H
#define BUILDTOWERICON_H

#include <QGraphicsPixmapItem>

class BuildTowerIcon : public QGraphicsPixmapItem
{
public:
    BuildTowerIcon();
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // BUILDTOWERICON_H
