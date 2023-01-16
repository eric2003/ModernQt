#include "mainwindow.h"
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QPushButton * quitBtn = new QPushButton( "Quit", this );
    quitBtn->setGeometry( 50, 25, 100, 50 );
    connect( quitBtn, &QPushButton::clicked, qApp, QApplication::quit );
}

MainWindow::~MainWindow()
{
}

