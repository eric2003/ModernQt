#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QLabel>
#include <QGraphicsRectItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->labViewCord = new QLabel("View coor:");
    this->labViewCord->setMinimumWidth(150);
    ui->statusbar->addWidget(this->labViewCord);
    this->labSceneCord = new QLabel("Scene coor:");
    this->labSceneCord->setMinimumWidth(150);
    ui->statusbar->addWidget(this->labSceneCord);
    this->labItemCord = new QLabel("Item coor:");
    this->labItemCord->setMinimumWidth(150);
    ui->statusbar->addWidget(this->labItemCord);

    ui->graphicsView->setCursor(Qt::CrossCursor);
    ui->graphicsView->setMouseTracking(true);
    QObject::connect(ui->graphicsView, &MyGraphicsView::mouseMovePoint, this, &MainWindow::on_mouseMovePoint);
    QObject::connect(ui->graphicsView, &MyGraphicsView::mouseClicked, this, &MainWindow::on_mouseClicked);
    this->InitGraphics();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InitGraphics()
{
    QRectF rect(-200,-100,400,200);
    this->scene = new QGraphicsScene(rect);
    this->ui->graphicsView->setScene(this->scene);
    QGraphicsRectItem * item = new QGraphicsRectItem(rect);
    item->setFlags(QGraphicsItem::ItemIsFocusable |
                   QGraphicsItem::ItemIsSelectable );
    QPen pen;
    pen.setWidth(2);
    item->setPen(pen);
    this->scene->addItem(item);

    QGraphicsEllipseItem * item2 = new QGraphicsEllipseItem(-100,-50,200,100);
    item2->setBrush(QBrush(Qt::blue));
    item2->setFlags(QGraphicsItem::ItemIsFocusable |
                   QGraphicsItem::ItemIsSelectable |
                   QGraphicsItem::ItemIsMovable );
    this->scene->addItem(item2);

    QGraphicsEllipseItem * item3 = new QGraphicsEllipseItem(-50,-50,100,100);
    item3->setBrush(QBrush(Qt::red));
    item3->setPos(rect.right(),rect.bottom());
    item3->setFlags(QGraphicsItem::ItemIsFocusable |
                    QGraphicsItem::ItemIsSelectable |
                    QGraphicsItem::ItemIsMovable );
    this->scene->addItem(item3);

}

void MainWindow::on_mouseMovePoint(QPoint point)
{
    this->labViewCord->setText(QString::asprintf("View coor:%d,%d",point.x(),point.y()));
    QPointF pointScene = this->ui->graphicsView->mapToScene(point);
    this->labSceneCord->setText(QString::asprintf("Scene coor:%0.f,%0.f",pointScene.x(),pointScene.y()));

}

void MainWindow::on_mouseClicked(QPoint point)
{
    QPointF pointScene = this->ui->graphicsView->mapToScene(point);
    QGraphicsItem *item=0;
    item = this->scene->itemAt(pointScene, ui->graphicsView->transform());
    if ( item ){
        QPointF pointItem = item->mapFromScene(pointScene);
        this->labItemCord->setText(QString::asprintf("Item coor:%0.f,%0.f",pointItem.x(),pointItem.y()));
    }

}
