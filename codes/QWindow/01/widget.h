#ifndef WIDGET_H
#define WIDGET_H

#include <QWindow>

class Widget : public QWindow
{
    Q_OBJECT

public:
    Widget(QWindow *parent = nullptr);
    ~Widget();
};
#endif // WIDGET_H
