#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPainter>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setPalette(Qt::white);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    //SimpleDraw1();
    //SimpleDraw2();
    SimpleDraw3();
}

void MainWindow::SimpleDraw1()
{
    QPainter painter(this);
    int w = this->width();
    int h = this->height();

    QRect rect(w/4,h/4,w/2,h/2);
    painter.drawRect(rect);

}

void MainWindow::SimpleDraw2()
{
    QPainter painter(this);
    int w = this->width();
    int h = this->height();

    QPen pen;
    pen.setWidth(10);
    painter.setPen(pen);

    QRect rect(w/4,h/4,w/2,h/2);
    painter.drawRect(rect);
}


void MainWindow::SimpleDraw3()
{
    QPainter painter(this);
    int w = this->width();
    int h = this->height();

    QPen pen;
    pen.setWidth(5);
    painter.setPen(pen);

    QBrush brush;
    brush.setColor(Qt::blue);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);

    QRect rect(w/4,h/4,w/2,h/2);
    painter.drawRect(rect);
}
