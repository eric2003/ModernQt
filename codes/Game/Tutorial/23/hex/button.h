#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsRectItem>

class Button : public QGraphicsRectItem
{
public:
    Button(QString name);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;
signals:
    void clicked();
private:
    QGraphicsTextItem * text;
};

#endif // BUTTON_H
