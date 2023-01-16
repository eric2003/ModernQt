#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileSystemModel>
#include <QListView>
#include <QTreeView>


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