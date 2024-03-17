#include "mainwindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createActions();
    createMenus();
}

MainWindow::~MainWindow() {
    delete this->fileMenu;
}

void MainWindow::open()
{
    QMessageBox::warning(this, tr("My Application"),
                               tr("The document has been modified.\n"
                                  "Do you want to save your changes?"),
                               QMessageBox::Save | QMessageBox::Discard
                                   | QMessageBox::Cancel,
                               QMessageBox::Save);
}

void MainWindow::createActions()
{
    // Create the action tied to the menu
    openAct = new QAction(tr("&Open..."), this);

    // Define the associated shortcut key
    openAct->setShortcuts(QKeySequence::Open);

    // Tie the action to MainWindow::open()
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));
}

void MainWindow::createMenus()
{
    this->fileMenu =new QMenu(tr("&File"), this);
    this->fileMenu->addAction(openAct);
    // Add menu items to the menubar
    menuBar()->addMenu( this->fileMenu );
}
