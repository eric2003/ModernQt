#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPainter>
#include <QPainterPath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    //SimpleDraw1();
    //SimpleDraw2();
    //SimpleDraw3();
    SimpleDraw4();
}

void MainWindow::SimpleDraw1()
{
    QPainter painter(this);
    int w = this->width();
    int h = this->height();

    QPen pen;
    pen.setStyle(Qt::SolidLine);
    painter.setPen(pen);

    QBrush brush;
    brush.setColor(Qt::blue);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);

    QRect rect(w/4,h/4,w/2,h/2);

    qreal r = 100;
    qreal dcit = 2 * M_PI / 5;
    QPoint points[5];
    for ( int i = 0; i < 5; ++ i )
    {
        qreal cit = i * dcit;
        qreal x = r * std::cos(cit);
        qreal y = - r * std::sin(cit);
        points[i] = QPoint(x, y);
        //qDebug() << " i = " <<i << " x = " << x << " y = " << y;

    }
    //qDebug() << "r="<<r;

    QPainterPath starPath;
    starPath.moveTo(points[3]);
    starPath.lineTo(points[1]);
    starPath.lineTo(points[4]);
    starPath.lineTo(points[2]);
    starPath.lineTo(points[0]);
    starPath.closeSubpath();

    painter.translate(100,120);
    painter.drawPath(starPath);

}

void MainWindow::SimpleDraw2()
{
    QPainter painter(this);

    QPen pen;
    pen.setStyle(Qt::SolidLine);
    painter.setPen(pen);

    QBrush brush;
    brush.setColor(Qt::blue);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);

    qreal r = 100;
    const int NPoints = 5;
    qreal dcit = 2 * M_PI / NPoints;
    QPoint points[NPoints];
    for ( int i = 0; i < NPoints; ++ i )
    {
        qreal cit = i * dcit;
        qreal x = r * std::cos(cit);
        qreal y = - r * std::sin(cit);
        points[i] = QPoint(x, y);
    }

    painter.translate(100,120);
    painter.drawPolygon(points,NPoints);
}

void MainWindow::SimpleDraw3()
{
    QPainter painter(this);

    QPen pen;
    pen.setStyle(Qt::SolidLine);
    painter.setPen(pen);
    painter.setRenderHint(QPainter::Antialiasing);

    QBrush brush;
    brush.setColor(Qt::blue);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);

    qreal r = 100;
    const int NPoints = 5;
    qreal dcit = 2 * M_PI / NPoints;
    QPoint points[NPoints];
    for ( int i = 0; i < NPoints; ++ i )
    {
        qreal cit = i * dcit;
        qreal x = r * std::cos(cit);
        qreal y = - r * std::sin(cit);
        points[i] = QPoint(x, y);
    }

    painter.translate(100,120);
    painter.drawPolygon(points,NPoints);
}

void MainWindow::SimpleDraw4()
{
    QPainter painter(this);

    QPen pen;
    pen.setStyle(Qt::SolidLine);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(pen);

    QBrush brush;
    brush.setColor(Qt::yellow);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);

    qreal r = 100;
    const int NPoints = 5;
    qreal dcit = 2 * M_PI / NPoints;
    QPoint points[NPoints];
    for ( int i = 0; i < NPoints; ++ i )
    {
        qreal cit = i * dcit;
        qreal x = r * std::cos(cit);
        qreal y = - r * std::sin(cit);
        points[i] = QPoint(x, y);
    }

    QPainterPath starPath;
    starPath.moveTo(points[3]);
    starPath.lineTo(points[1]);
    starPath.lineTo(points[4]);
    starPath.lineTo(points[2]);
    starPath.lineTo(points[0]);
    starPath.closeSubpath();

    QFont font;
    font.setPointSize(12);
    for ( int i = 0; i < NPoints; ++ i )
    {
        starPath.addText(points[i],font,QString::number(i));
    }

    painter.setFont(font);
    painter.save();

    painter.translate(100,120);
    painter.drawPath(starPath);
    painter.drawText(0,0,"S1");

    painter.restore();
    painter.translate(300,120);
    painter.rotate(90);
    painter.drawPath(starPath);
    painter.drawText(0,0,"S2");

    painter.resetTransform();
    painter.translate(500,120);
    painter.rotate(-90);
    painter.drawPath(starPath);
    painter.drawText(0,0,"S3");

}
