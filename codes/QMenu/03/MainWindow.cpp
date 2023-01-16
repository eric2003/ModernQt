#include "MainWindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
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
    this->status = new QAction( "View statusbar", this );
    this->status->setCheckable( true );
    this->status->setChecked( true );

    this->statusBar();
    this->status->setStatusTip( "status bar" );
    file->addAction( newa );
    file->addAction( open );
    file->addSeparator();
    file->addAction( quit );
    file->addAction( this->status );
    qApp->setAttribute( Qt::AA_DontShowIconsInMenus, false );
    this->connect( quit, &QAction::triggered, qApp, &QApplication::quit );
    this->connect( this->status, &QAction::triggered, this, &MainWindow::toggleStatusbar );

}

MainWindow::~MainWindow()
{
}

void MainWindow::toggleStatusbar()
{
    if ( this->status->isChecked() )
    {
        this->statusBar()->show();
    }
    else
    {
        this->statusBar()->hide();
    }
}
