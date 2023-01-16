#include "mainwindow.h"
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setMouseTracking( true );
    QPushButton * quitBtn = new QPushButton( "Quit", this );
    quitBtn->setGeometry( 50, 25, 100, 50 );
    connect( quitBtn, &QPushButton::clicked, qApp, QApplication::quit );
}

MainWindow::~MainWindow()
{
}

void MainWindow::keyPressEvent( QKeyEvent * event )
{
    if ( event->key() == Qt::Key_Escape )
    {
        qApp->quit();
    };
}

void MainWindow::mouseMoveEvent( QMouseEvent * event )
{
    int x = event->pos().x();
    int y = event->pos().y();
    QString text = "coor : " + QString::number( x ) + "," + QString::number( y );
    this->statusBar()->showMessage( text );
}