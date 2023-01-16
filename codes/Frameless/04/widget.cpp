#include "widget.h"
#include "./ui_widget.h"
#include <QMouseEvent>
QPoint winPos;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowFlag( Qt::FramelessWindowHint );
    this->setAttribute( Qt::WA_TranslucentBackground, true );
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_2_clicked()
{
    qApp->quit();
}

void Widget::mousePressEvent( QMouseEvent * event )
{
    QPoint mousePos = event->globalPosition().toPoint();
    QPoint topleft = this->geometry().topLeft();
    winPos = mousePos - topleft;
}

void Widget::mouseReleaseEvent( QMouseEvent * event )
{
    winPos = QPoint();
}

void Widget::mouseMoveEvent( QMouseEvent * event )
{
    QPoint mousePos = event->globalPosition().toPoint();
    QPoint endPos = mousePos - winPos;
    this->move( endPos );
}


