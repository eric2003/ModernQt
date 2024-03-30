#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsRectItem>
#include <QObject>

class Player :  public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Player();
    void keyPressEvent(QKeyEvent *event) override;
public slots:
    void spawn();
};

#endif // MYRECT_H
