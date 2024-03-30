#include <QKeyEvent>
#include <QGraphicsScene>
#include "player.h"
#include "bullet.h"
#include "enemy.h"
#include <QMediaPlayer>
#include <QAudioOutput>


Player::Player() {
    this->setPixmap(QPixmap(":/images/player.png"));

    this->bulletsound = new QMediaPlayer();
    this->bulletsound->setSource(QUrl("qrc:/sounds/sound/bullet.wav"));
    QAudioOutput * audioOutput = new QAudioOutput;
    audioOutput->setVolume(50);
    this->bulletsound->setAudioOutput(audioOutput);
    this->bulletsound->play();
}

void Player::keyPressEvent(QKeyEvent *event)
{
    //qDebug() << "Myrect knows that you pressed a key";
    switch ( event->key() ) {
    case Qt::Key_Left:
    {
        if ( this->pos().x() > 0 )
        {
            this->setPos(this->x()-10,this->y());
        }
        break;
    }
    case Qt::Key_Right:
    {
        if ( this->pos().x() + this->boundingRect().width() < 800 )
        {
            this->setPos(this->x()+10,this->y());
        }

        break;
    }
    case Qt::Key_Space:
    {
        //create a bullet
        Bullet * bullet = new Bullet();
        //qDebug() << "bullet created";
        // qDebug() << "bullet->boundingRect().width() = " << bullet->boundingRect().width();
        // qDebug() << "bullet->boundingRect().width() = " << this->boundingRect().width();
        qreal xshift = (this->boundingRect().width() - bullet->boundingRect().width() ) / 2;
        bullet->setPos(this->x()+xshift,this->y());
        this->scene()->addItem(bullet);

        // play bulletsound
        this->bulletsound->play();
        break;
    }
    default:
        break;
    }
}

void Player::spawn()
{
    //create an enemy
    Enemy *enemy = new Enemy();
    this->scene()->addItem(enemy);
}
