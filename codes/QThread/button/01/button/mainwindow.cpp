#include "mainwindow.h"
#include <QPushButton>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    this->resize(514, 375);

    this->setWindowTitle("Qt PushButton Show Text on Label");

    this->startButton = new QPushButton(this);
    this->startButton->setText("Start");
    this->startButton->setObjectName("myPushButton");
    this->startButton->setGeometry(QRect(40, 260, 391, 23));

    this->numberLabel = new QLabel(QString::number(0),this);
    this->numberLabel->setGeometry(QRect(170, 130, 131, 31));
    this->numberLabel->setAlignment(Qt::AlignCenter);

    QObject::connect(this->startButton, &QPushButton::clicked, this, [this](){
        int num = 0;
        while( true )
        {
            num ++;
            if ( num == 1000000 ){
                break;
            }
            this->numberLabel->setText(QString::number(num));
        }
    });

}

MainWindow::~MainWindow()
{
    delete this->startButton;
    delete this->numberLabel;
}

