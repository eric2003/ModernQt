#pragma once
#include <QWidget>

class QLabel;
class Widget : public QWidget
{
    Q_OBJECT
public:
    Widget( QWidget * parent = nullptr );
    ~Widget();
public slots:
    void OnPlus();
    void OnMinus();
private:
    QLabel * lbl;

};