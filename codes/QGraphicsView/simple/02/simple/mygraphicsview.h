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
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    //void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
signals:
    void keyPress(QKeyEvent *event);
    void mouseDoubleClicked(QPoint point);
    void mouseClicked(QPoint point);
};

#endif // MYGRAPHICSVIEW_H
