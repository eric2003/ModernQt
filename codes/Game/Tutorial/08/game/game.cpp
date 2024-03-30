#include "game.h"
#include "player.h"
#include "score.h"
#include "health.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QMediaPlayer>
#include <QAudioOutput>

Game::Game() {
    //create a scene
    this->scene = new QGraphicsScene();
    this->scene->setSceneRect(0,0,800,600);
    // make the scene 800x600 instead of infinity by infinity (default)
    QPixmap bgPixmap = QPixmap(":/images/bg.jpg");
    QPixmap scaledImage = bgPixmap.scaled(this->scene->width(),this->scene->height(), Qt::KeepAspectRatioByExpanding);
    QBrush brush = QBrush(scaledImage);
    this->scene->setBackgroundBrush(brush);


    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    this->setScene(this->scene);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setFixedSize(800,600);

    // create the player
    this->player = new Player();
    this->player->setPos(400,500); // TODO generalize to always be in the middle bottom of screen
    // make the player focusable and set it to be the current focus
    this->player->setFlag(QGraphicsItem::ItemIsFocusable);
    this->player->setFocus();
    // add the player to the scene
    this->scene->addItem(this->player);

    // create the score/health
    this->score = new Score();
    this->scene->addItem(this->score);

    this->health = new Health();
    this->health->setPos(health->x(),health->y()+25);
    this->scene->addItem(this->health);

    // spawn enemies
    QTimer *timer = new QTimer();
    QObject::connect(timer,&QTimer::timeout,player,&Player::spawn);
    timer->start(2000);

    //play background music
    QMediaPlayer * music = new QMediaPlayer();
    QAudioOutput * audioOutput = new QAudioOutput;
    music->setAudioOutput(audioOutput);

    music->setSource(QUrl("qrc:/sounds/sound/bgsound.mp3"));
    audioOutput->setVolume(50);
    music->play();
}
