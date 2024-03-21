#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QLabel>
#include <QGraphicsRectItem>
#include <QTime>
#include <QInputDialog>
#include <QColorDialog>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->gView);

    //this->scene = new QGraphicsScene(this);
    this->scene = new QGraphicsScene(QRect(-300,-100,600,200));
    this->ui->gView->setScene(this->scene);
    this->ui->gView->setCursor(Qt::CrossCursor);
    this->ui->gView->setMouseTracking(true);
    this->ui->gView->setDragMode(QGraphicsView::RubberBandDrag);

    this->labItemInfo = new QLabel("ItemInfo:");
    this->labItemInfo->setMinimumWidth(150);
    this->ui->statusbar->addWidget( this->labItemInfo );

    QObject::connect(ui->gView, &MyGraphicsView::keyPress, this, &MainWindow::on_keyPress);
    QObject::connect(ui->gView, &MyGraphicsView::mouseClicked, this, &MainWindow::on_mouseClicked);
    QObject::connect(ui->gView, &MyGraphicsView::mouseDoubleClicked, this, &MainWindow::on_mouseDoubleClicked);

    srand(QTime::currentTime().msec());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_keyPress(QKeyEvent *event)
{
    QList<QGraphicsItem *> itemList = this->scene->selectedItems();
    int cnt = itemList.count();
    if ( cnt == 0 ){
        return;
    }
    switch (event->key()) {
    case Qt::Key_Delete:
    {
        for ( int i = 0; i < cnt; ++ i ) {
            QGraphicsItem * item = itemList[i];
            this->scene->removeItem(item);
        }

        break;
    }
    case Qt::Key_Left:
    {
        for ( int i = 0; i < cnt; ++ i ) {
            QGraphicsItem * item = itemList[i];
            item->setX(item->x()-1);
        }

        break;
    }
    case Qt::Key_Right:
    {
        for ( int i = 0; i < cnt; ++ i ) {
            QGraphicsItem * item = itemList[i];
            item->setX(item->x()+1);
        }

        break;
    }
    case Qt::Key_Up:
    {
        for ( int i = 0; i < cnt; ++ i ) {
            QGraphicsItem * item = itemList[i];
            item->setY(item->y()-1);
        }

        break;
    }
    case Qt::Key_Down:
    {
        for ( int i = 0; i < cnt; ++ i ) {
            QGraphicsItem * item = itemList[i];
            item->setY(item->y()+1);
        }
        break;
    }
    default:
        break;
    }

}

void MainWindow::on_mouseDoubleClicked(QPoint point)
{
    QPointF pointScene = this->ui->gView->mapToScene(point);
    QGraphicsItem * item = 0;
    item = this->scene->itemAt(pointScene,this->ui->gView->transform());
    if ( !item ) return;

    switch (item->type()) {
    case QGraphicsRectItem::Type:
    {
        QGraphicsRectItem * theItem;
        theItem = qgraphicsitem_cast<QGraphicsRectItem *>(item);
        QColor color = theItem->brush().color();
        color = QColorDialog::getColor(color,nullptr,"Choose color:");
        theItem->setBrush(QBrush(color));
        break;
    }
    case QGraphicsEllipseItem::Type:
    {
        QGraphicsEllipseItem * theItem;
        theItem = qgraphicsitem_cast<QGraphicsEllipseItem *>(item);
        QColor color = theItem->brush().color();
        color = QColorDialog::getColor(color,nullptr,"Choose color:");
        theItem->setBrush(QBrush(color));
        break;
    }
    case QGraphicsPolygonItem::Type:
    {
        QGraphicsPolygonItem * theItem;
        theItem = qgraphicsitem_cast<QGraphicsPolygonItem *>(item);
        QColor color = theItem->brush().color();
        color = QColorDialog::getColor(color,nullptr,"Choose color:");
        theItem->setBrush(QBrush(color));
        break;
    }
    case QGraphicsLineItem::Type:
    {
        QGraphicsLineItem * theItem;
        theItem = qgraphicsitem_cast<QGraphicsLineItem *>(item);
        QColor color = theItem->pen().color();
        color = QColorDialog::getColor(color,nullptr,"Choose color:");
        theItem->setPen(QPen(color));
        break;
    }
    case QGraphicsTextItem::Type:
    {
        QGraphicsTextItem * theItem;
        theItem = qgraphicsitem_cast<QGraphicsTextItem *>(item);
        QColor color = theItem->defaultTextColor();
        color = QColorDialog::getColor(color,nullptr,"Choose color:");
        theItem->setDefaultTextColor(color);
        break;
    }
    default:
         break;
    }

}

void MainWindow::on_mouseClicked(QPoint point)
{
    QPointF pointScene = this->ui->gView->mapToScene(point);
    QGraphicsItem * item = 0;
    item = this->scene->itemAt(pointScene,this->ui->gView->transform());
    if ( item ) {
        this->labItemInfo->setText("ItemInfo:"+item->data(ItemId).toString()+","+item->data(ItemDescription).toString());
    }

}

void MainWindow::on_actItem_Rect_triggered()
{
    QGraphicsRectItem * item = new QGraphicsRectItem(-50,-30,100,60);
    item->setBrush(QBrush(Qt::yellow));
    item->setFlags(QGraphicsItem::ItemIsFocusable |
                   QGraphicsItem::ItemIsSelectable |
                   QGraphicsItem::ItemIsMovable );
    item->setPos(-100+rand()%200,-60+rand()%120);
    item->setData(ItemId,++seqNum);
    item->setData(ItemDescription,"Rectangle");
    this->scene->addItem(item);
    this->scene->clearSelection();
    item->setSelected(true);
}


void MainWindow::on_actItem_Ellipse_triggered()
{
    QGraphicsEllipseItem * item = new QGraphicsEllipseItem(-50,-30,100,60);
    item->setBrush(QBrush(Qt::gray));
    item->setFlags(QGraphicsItem::ItemIsFocusable |
                   QGraphicsItem::ItemIsSelectable |
                   QGraphicsItem::ItemIsMovable );
    item->setPos(-100+rand()%200,-60+rand()%120);
    item->setData(ItemId,++seqNum);
    item->setData(ItemDescription,"Ellipse");
    this->scene->addItem(item);
    this->scene->clearSelection();
    item->setSelected(true);
}


void MainWindow::on_actItem_Circle_triggered()
{
    QGraphicsEllipseItem * item = new QGraphicsEllipseItem(-50,-50,100,100);
    item->setBrush(QBrush(Qt::blue));
    item->setFlags(QGraphicsItem::ItemIsFocusable |
                   QGraphicsItem::ItemIsSelectable |
                   QGraphicsItem::ItemIsMovable );
    item->setPos(-100+rand()%200,-60+rand()%120);
    item->setData(ItemId,++seqNum);
    item->setData(ItemDescription,"Circle");
    this->scene->addItem(item);
    this->scene->clearSelection();
    item->setSelected(true);
}


void MainWindow::on_actItem_Line_triggered()
{
    QGraphicsLineItem * item = new QGraphicsLineItem(-100,0,100,0);
    item->setFlags(QGraphicsItem::ItemIsFocusable |
                   QGraphicsItem::ItemIsSelectable |
                   QGraphicsItem::ItemIsMovable );
    QPen pen(Qt::black);
    pen.setWidth(3);
    item->setPen(pen);
    item->setPos(-100+rand()%200,-60+rand()%120);
    item->setData(ItemId,++seqNum);
    item->setData(ItemDescription,"Line");
    this->scene->addItem(item);
    this->scene->clearSelection();
    item->setSelected(true);
}


void MainWindow::on_actItem_Polygon_triggered()
{
    QGraphicsPolygonItem * item = new QGraphicsPolygonItem;
    QPolygonF points;
    points.append(QPointF(-40,-40));
    points.append(QPointF( 40,-40));
    points.append(QPointF( 60, 40));
    points.append(QPointF(-60, 40));

    item->setPolygon(points);
    item->setFlags(QGraphicsItem::ItemIsFocusable |
                   QGraphicsItem::ItemIsSelectable |
                   QGraphicsItem::ItemIsMovable );
    item->setBrush(QBrush(Qt::blue));
    item->setPos(-100+rand()%200,-60+rand()%120);
    item->setData(ItemId,++seqNum);
    item->setData(ItemDescription,"Polygon");
    this->scene->addItem(item);
    this->scene->clearSelection();
    item->setSelected(true);
}


void MainWindow::on_actItem_Triangle_triggered()
{
    QGraphicsPolygonItem * item = new QGraphicsPolygonItem;
    QPolygonF points;
    points.append(QPointF(0,-40));
    points.append(QPointF( 60, 40));
    points.append(QPointF(-60, 40));

    item->setPolygon(points);
    item->setFlags(QGraphicsItem::ItemIsFocusable |
                   QGraphicsItem::ItemIsSelectable |
                   QGraphicsItem::ItemIsMovable );
    item->setBrush(QBrush(Qt::red));
    item->setPos(-100+rand()%200,-60+rand()%120);
    item->setData(ItemId,++seqNum);
    item->setData(ItemDescription,"Triangle");
    this->scene->addItem(item);
    this->scene->clearSelection();
    item->setSelected(true);
}


void MainWindow::on_actItem_Text_triggered()
{
    QString str = QInputDialog::getText(this,"Input Dialog", "Please input text:");
    QGraphicsTextItem * item = new QGraphicsTextItem(str);
    item->setFlags(QGraphicsItem::ItemIsFocusable |
                   QGraphicsItem::ItemIsSelectable |
                   QGraphicsItem::ItemIsMovable );
    QFont font;
    font.setPointSize(20);
    item->setDefaultTextColor(Qt::green);
    item->setFont(font);
    item->setPos(-100+rand()%200,-60+rand()%120);
    item->setData(ItemId,++seqNum);
    item->setData(ItemDescription,"Text");
    this->scene->addItem(item);
    this->scene->clearSelection();
    item->setSelected(true);
}


void MainWindow::on_actZoomIn_triggered()
{
    int cnt = this->scene->selectedItems().count();
    if ( cnt == 0 ){
        this->ui->gView->scale(1.1,1.1);
    }

    for ( int i = 0; i < cnt; ++ i ) {
        QGraphicsItem * item = this->scene->selectedItems().at(i);
        item->setScale(0.1+item->scale());
    }

}


void MainWindow::on_actZoomOut_triggered()
{
    int cnt = this->scene->selectedItems().count();
    if ( cnt == 0 ){
        this->ui->gView->scale(0.9,0.9);
    }

    for ( int i = 0; i < cnt; ++ i ) {
        QGraphicsItem * item = this->scene->selectedItems().at(i);
        item->setScale(-0.1+item->scale());
    }
}


void MainWindow::on_actRestore_triggered()
{
    int cnt = this->scene->selectedItems().count();
    if ( cnt == 0 ){
        this->ui->gView->resetTransform();
    }

    for ( int i = 0; i < cnt; ++ i ) {
        QGraphicsItem * item = this->scene->selectedItems().at(i);
        item->setScale(1);
    }
}


void MainWindow::on_actRotateLeft_triggered()
{
    int cnt = this->scene->selectedItems().count();
    if ( cnt == 0 ){
        this->ui->gView->rotate(-45);
        return;
    }

    for ( int i = 0; i < cnt; ++ i ) {
        QGraphicsItem * item = this->scene->selectedItems().at(i);
        item->setRotation(item->rotation()-45);
    }
}


void MainWindow::on_actRotateRight_triggered()
{
    int cnt = this->scene->selectedItems().count();
    if ( cnt == 0 ){
        this->ui->gView->rotate(+45);
        return;
    }

    for ( int i = 0; i < cnt; ++ i ) {
        QGraphicsItem * item = this->scene->selectedItems().at(i);
        item->setRotation(item->rotation()+45);
    }
}


void MainWindow::on_actEdit_Front_triggered()
{
    int cnt = this->scene->selectedItems().count();
    if ( cnt == 0 ){
        return;
    }

    for ( int i = 0; i < cnt; ++ i ) {
        QGraphicsItem * item = this->scene->selectedItems().at(i);
        item->setZValue(item->zValue()+1);
    }
}


void MainWindow::on_actEdit_Back_triggered()
{
    int cnt = this->scene->selectedItems().count();
    if ( cnt == 0 ){
        return;
    }

    for ( int i = 0; i < cnt; ++ i ) {
        QGraphicsItem * item = this->scene->selectedItems().at(i);
        item->setZValue(item->zValue()-1);
    }
}


void MainWindow::on_actGroup_triggered()
{
    int cnt = this->scene->selectedItems().count();
    if ( cnt <= 1 ){
        return;
    }

    QGraphicsItemGroup *group = new QGraphicsItemGroup;
    this->scene->addItem(group);

    QList<QGraphicsItem * > itemList;

    for ( int i = 0; i < cnt; ++ i ) {
        //qDebug() << "group->addToGroup i=" << i << " cnt = " << cnt;
        QGraphicsItem * item = this->scene->selectedItems().at(i);
        itemList.append( item );
        //group->addToGroup(item);
    }
    //qDebug() << "haha";

    for ( QGraphicsItem * item : itemList) {
        item->setSelected(false);
        group->addToGroup(item);
    }

    group->setFlags(QGraphicsItem::ItemIsFocusable |
                    QGraphicsItem::ItemIsSelectable |
                    QGraphicsItem::ItemIsMovable );

    group->setSelected(true);

}


void MainWindow::on_actGroupBreak_triggered()
{
    int cnt = this->scene->selectedItems().count();
    if ( cnt == 0 ){
        return;
    }

    QList<QGraphicsItemGroup * > groupList;

    for ( int i = 0; i < cnt; ++ i ) {
        QGraphicsItem * item = this->scene->selectedItems().at(i);
        if( item->type()==QGraphicsItemGroup::Type){
            QGraphicsItemGroup * group = qgraphicsitem_cast<QGraphicsItemGroup *>(item);
            groupList.append(group);
        }
    }

    for ( QGraphicsItemGroup * group : groupList) {
        this->scene->destroyItemGroup(group);
    }

}


void MainWindow::on_actEdit_Delete_triggered()
{
    int cnt = this->scene->selectedItems().count();
    if ( cnt == 0 ){
        return;
    }

    QList<QGraphicsItem *> itemList = this->scene->selectedItems();

    for ( int i = 0; i < cnt; ++ i ) {
        QGraphicsItem * item = itemList[i];
        this->scene->removeItem(item);
    }
}

