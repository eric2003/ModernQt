#include "mainwindow.h"
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget * widget = new QWidget( this );
    this->setCentralWidget( widget );
    QLabel * label = new QLabel( "haha", widget );
}

MainWindow::~MainWindow()
{
}
