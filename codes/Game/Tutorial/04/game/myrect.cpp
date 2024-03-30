#include "myrect.h"
#include "bullet.h"
#include <QKeyEvent>
#include <QGraphicsScene>

MyRect::MyRect() {}

void MyRect::keyPressEvent(QKeyEvent *event)
{
    //qDebug() << "Myrect knows that you pressed a key";
    switch ( event->key() ) {
    case Qt::Key_Left:
    {
        this->setPos(this->x()-10,this->y());
        break;
    }
    case Qt::Key_Right:
    {
        this->setPos(this->x()+10,this->y());
        break;
    }
    // case Qt::Key_Up:
    // {
    //     this->setPos(this->x(),this->y()-10);
    //     break;
    // }
    // case Qt::Key_Down:
    // {
    //     this->setPos(this->x(),this->y()+10);
    //     break;
    // }
    case Qt::Key_Space:
    {
        //create a bullet
        Bullet * bullet = new Bullet();
        //qDebug() << "bullet created";
        bullet->setPos(this->x(),this->y());
        this->scene()->addItem(bullet);
        break;
    }
    default:
        break;
    }

}
