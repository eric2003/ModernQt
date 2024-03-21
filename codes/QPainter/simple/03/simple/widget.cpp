#include "widget.h"
#include "./ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setPalette(Qt::white);
    this->resize(300,300);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    //SimpleDraw1();
    //SimpleDraw2();
    //SimpleDraw3();
    //SimpleDraw4();
    //SimpleDraw5();
    //SimpleDraw6();
    SimpleDraw7();
}

void Widget::SimpleDraw1()
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    int w = width();
    int h = height();
    int side = qMin(w,h);
    QRect rect((w-side)/2,(h-side)/2,side,side);
    painter.drawRect(rect);
    painter.setViewport(rect);
    painter.setWindow(-100,-100,200,200);
    painter.drawEllipse(0,0,50,50);

}

void Widget::SimpleDraw2()
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    int w = width();
    int h = height();
    int side = qMin(w,h);
    QRect rect((w-side)/2,(h-side)/2,side,side);
    painter.drawRect(rect);
    painter.setViewport(rect);
    painter.setWindow(-100,-100,200,200);
    //painter.drawEllipse(50,0,50,50);
    painter.drawEllipse(QPoint(50,0),50,50);
}

void Widget::SimpleDraw3()
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    int w = width();
    int h = height();
    int side = qMin(w,h);
    QRect rect((w-side)/2,(h-side)/2,side,side);
    painter.drawRect(rect);
    painter.setViewport(rect);
    painter.setWindow(-100,-100,200,200);
    //for ( int i = 0; i < 36; ++ i )
    for ( int i = 0; i < 2; ++ i )
    {
        painter.drawEllipse(QPoint(50,0),50,50);
        painter.rotate(10);
    }

}

void Widget::SimpleDraw4()
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    int w = width();
    int h = height();
    int side = qMin(w,h);
    QRect rect((w-side)/2,(h-side)/2,side,side);
    painter.drawRect(rect);
    painter.setViewport(rect);
    painter.setWindow(-100,-100,200,200);
    for ( int i = 0; i < 36; ++ i )
    {
        painter.drawEllipse(QPoint(50,0),50,50);
        painter.rotate(10);
    }

}

void Widget::SimpleDraw5()
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    int w = width();
    int h = height();
    int side = qMin(w,h);
    QRect rect((w-side)/2,(h-side)/2,side,side);
    painter.drawRect(rect);
    painter.setViewport(rect);
    painter.setWindow(-100,-100,200,200);

    QLinearGradient lgrad(0,0,100,0);
    painter.setBrush(lgrad);
    for ( int i = 0; i < 36; ++ i )
    {
        painter.drawEllipse(QPoint(50,0),50,50);
        painter.rotate(10);
    }

}

void Widget::SimpleDraw6()
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    int w = width();
    int h = height();
    int side = qMin(w,h);
    QRect rect((w-side)/2,(h-side)/2,side,side);
    painter.drawRect(rect);
    painter.setViewport(rect);
    painter.setWindow(-100,-100,200,200);

    QLinearGradient lgrad(0,0,100,0);
    lgrad.setColorAt(0,Qt::yellow);
    lgrad.setColorAt(1,Qt::green);
    lgrad.setSpread(QGradient::PadSpread);
    painter.setBrush(lgrad);
    for ( int i = 0; i < 36; ++ i )
    {
        painter.drawEllipse(QPoint(50,0),50,50);
        painter.rotate(10);
    }
}

void Widget::SimpleDraw7()
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    int w = width();
    int h = height();
    int side = qMin(w,h);
    QRect rect((w-side)/2,(h-side)/2,side,side);
    painter.drawRect(rect);
    painter.setViewport(rect);
    painter.setWindow(-100,-100,200,200);

    QLinearGradient lgrad(0,0,100,0);
    lgrad.setColorAt(0,Qt::yellow);
    lgrad.setColorAt(1,Qt::green);
    lgrad.setSpread(QGradient::PadSpread);
    painter.setBrush(lgrad);
    //painter.setCompositionMode(QPainter::RasterOp_NotSourceXorDestination);
    painter.setCompositionMode(QPainter::RasterOp_SourceXorDestination);
    for ( int i = 0; i < 36; ++ i )
    {
        painter.drawEllipse(QPoint(50,0),50,50);
        painter.rotate(10);
    }
}
