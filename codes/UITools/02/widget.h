#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
class QSpinBox;
class QLabel;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:
    void on_spinBox1_valueChanged( int value );
    void on_spinBox2_valueChanged( int value );
private:
    QSpinBox * ui_spinBox1;
    QSpinBox * ui_spinBox2;
    QLabel * ui_labelSum;
};
#endif // WIDGET_H
