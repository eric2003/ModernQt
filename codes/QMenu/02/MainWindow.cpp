#include "MainWindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QApplication>

//https://iconscout.com/free-icons
//https://www.iconfinder.com/

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QPixmap newpix( "../images/new.png" );
    QPixmap openpix( "../images/open.png" );
    QPixmap quitpix( "../images/close.png" );
    auto * newa = new QAction( newpix, "&New", this );
    auto * open = new QAction( openpix, "&Open", this );
    auto * quit = new QAction( quitpix, "&Quit", this );
    quit->setShortcut( tr( "CTRL+Q" ) );
    QMenu * file = menuBar()->addMenu( "&File" );
    file->addAction( newa );
    file->addAction( open );
    file->addSeparator();
    file->addAction( quit );
    qApp->setAttribute( Qt::AA_DontShowIconsInMenus, false );
    this->connect( quit, &QAction::triggered, qApp, &QApplication::quit );

}

MainWindow::~MainWindow()
{
}
