#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <QWidget>
#include <QGraphicsView>

class MyGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit MyGraphicsView(QWidget *parent = nullptr);
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
signals:
    void mouseMovePoint(QPoint point);
    void mouseClicked(QPoint point);
};

#endif // MYGRAPHICSVIEW_H
