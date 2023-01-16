#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileSystemModel>
#include <QListView>
#include <QTreeView>
#include <QStatusBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->model = new QFileSystemModel( this );
    this->model->setRootPath( QDir::currentPath() );
    ui->treeView->setModel( this->model );
    ui->listView->setModel( this->model );
    this->connect( ui->treeView, &QTreeView::clicked, ui->listView, &QListView::setRootIndex );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_treeView_clicked( const QModelIndex &index )
{
    QString status = model->filePath( index );
    if ( !model->isDir(index) )
    {
        status += " size:";
        int size = model->size( index ) / 1024;
        if ( size < 1024 )
        {
            status += QString( "%1 KB" ).arg( size );
        }
        else
        {
            status += QString::asprintf( "%.2f MB", size / 1024.0 );
        }
    }
    statusBar()->showMessage( status );
}
