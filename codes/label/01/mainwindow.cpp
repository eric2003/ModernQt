#include "mainwindow.h"
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QLabel * label = new QLabel( "haha", this );
}

MainWindow::~MainWindow()
{
}
