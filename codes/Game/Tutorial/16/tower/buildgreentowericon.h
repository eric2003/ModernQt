#ifndef BUILDGREENTOWERICON_H
#define BUILDGREENTOWERICON_H

#include <QGraphicsPixmapItem>

class BuildGreenTowerIcon : public QGraphicsPixmapItem
{
public:
    BuildGreenTowerIcon();
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // BUILDGREENTOWERICON_H
