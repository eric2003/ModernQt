#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "myrect.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //create a scene
    QGraphicsScene *scene = new QGraphicsScene();
    MyRect *rect = new MyRect();
    rect->setRect(0,0,100,100);
    //add the item to the scene
    scene->addItem(rect);

    //make rect focusable
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();

    //create a view to visualize the scene
    QGraphicsView *view = new QGraphicsView(scene);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //show the view
    view->show();
    return a.exec();
}
