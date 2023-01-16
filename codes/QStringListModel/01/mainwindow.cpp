#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QStringListModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->setFixedSize( 300, 200 );
    ui->setupUi(this);
    this->model = new QStringListModel();
    QStringList cities = { "北京", "上海", "广州", "深圳" };
    this->model->setStringList( cities );
    ui->listView->setModel( this->model );
    ui->listView->setEditTriggers( QAbstractItemView::NoEditTriggers );
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnModify_clicked()
{
    QModelIndex index = ui->listView->currentIndex();
    ui->listView->edit( index );
}

void MainWindow::on_btnClear_clicked()
{
    this->model->removeRows( 0, model->rowCount() );
}

void MainWindow::on_btnAdd_clicked()
{
    this->model->insertRow( this->model->rowCount() );
    
    QModelIndex index = model->index( model->rowCount() - 1 );
    this->model->setData( index, "new item", Qt::DisplayRole );
    ui->listView->edit( index );

}

void MainWindow::on_btnDelete_clicked()
{
    QModelIndex index = ui->listView->currentIndex();
    model->removeRow( index.row() );

}


