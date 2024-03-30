#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsRectItem>

class MyRect : public QGraphicsRectItem
{
public:
    MyRect();
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // MYRECT_H
