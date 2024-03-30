#include <QApplication>
#include <QGraphicsScene>
//#include <QGraphicsRectItem>
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
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();
    //make rect focusable

    QGraphicsView *view = new QGraphicsView(scene);
    view->show();
    return a.exec();
}
