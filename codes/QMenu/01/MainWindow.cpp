#include "MainWindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    auto * quit = new QAction( "&Quit", this );
    QMenu * file = menuBar()->addMenu( "&File" );
    file->addAction( quit );
    this->connect( quit, &QAction::triggered, qApp, QApplication::quit );

}

MainWindow::~MainWindow()
{
}
