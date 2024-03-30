#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMediaPlayer>
#include <QAudioOutput>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->music = new QMediaPlayer();
    this->music->setSource(QUrl("qrc:/test1.wav"));
    //this->music->setSource(QUrl("qrc:/test2.mp3"));
    //this->music->setSource(QUrl("qrc:/test3.wav"));
    QAudioOutput * audioOutput = new QAudioOutput;
    audioOutput->setVolume(50);
    this->music->setAudioOutput(audioOutput);
    //music->play();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_playButton_clicked()
{
    qDebug() << "this->music->playbackState()=" <<  this->music->playbackState();
    qDebug() << "this->music->mediaStatus()=" <<  this->music->mediaStatus();
    this->music->play();
    qDebug() << "play";

}


void MainWindow::on_stopButton_clicked()
{
    qDebug() << "stop music";
    this->music->stop();
}


void MainWindow::on_pauseButton_clicked()
{
    qDebug() << "pause music";
    this->music->pause();
}

