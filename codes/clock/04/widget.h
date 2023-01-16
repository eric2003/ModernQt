#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
class QPaintEvent;


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
protected:
    void paintEvent( QPaintEvent * event ) override;
};
#endif // WIDGET_H
