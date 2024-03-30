#ifndef BUILDREDTOWERICON_H
#define BUILDREDTOWERICON_H

#include <QGraphicsPixmapItem>

class BuildRedTowerIcon : public QGraphicsPixmapItem
{
public:
    BuildRedTowerIcon();
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // BUILDREDTOWERICON_H
