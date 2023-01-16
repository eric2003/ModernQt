#include "mainwindow.h"
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget * widget = new QWidget( this );
    this->setCentralWidget( widget );
    this->label = new QLabel( QTime::currentTime().toString(), widget );
    this->clickBtn = new QPushButton( "click", widget );
    this->cb = new QCheckBox( "Connect", widget );
    this->cb->setCheckState( Qt::Checked );
    QHBoxLayout * hbox = new QHBoxLayout( widget );
    hbox->addWidget( this->clickBtn );
    hbox->addWidget( this->label );
    this->startTimer( 1000 );
    this->connect( this->clickBtn, &QPushButton::clicked, this, &MainWindow::onClick );
    this->connect( this->cb, &QCheckBox::stateChanged, this, &MainWindow::onCheck );
}

MainWindow::~MainWindow()
{
}

void MainWindow::timerEvent( QTimerEvent * event )
{
    this->label->setText( QTime::currentTime().toString() );
}

void MainWindow::onClick()
{
    this->statusBar()->showMessage( " button is clicked !" );
}

void MainWindow::onCheck( int state )
{
    this->statusBar()->showMessage( "" );
    if ( state == Qt::Checked )
    {
        this->connect( this->clickBtn, &QPushButton::clicked, this, &MainWindow::onClick );
   }
    else
    {
        this->disconnect( this->clickBtn, &QPushButton::clicked, this, &MainWindow::onClick );
    }
}