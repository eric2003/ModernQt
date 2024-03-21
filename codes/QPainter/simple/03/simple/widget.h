#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void paintEvent(QPaintEvent *event);
private:
    void SimpleDraw1();
    void SimpleDraw2();
    void SimpleDraw3();
    void SimpleDraw4();
    void SimpleDraw5();
    void SimpleDraw6();
    void SimpleDraw7();
private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
