#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QStandardItemModel>
#include <QHeaderView>
#include <QTableView>
#include <QDataWidgetMapper>
#include <QAbstractButton>
#include <QPushButton>
#include "IntSpinDelegate.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->setFixedSize( 360, 200 );
    ui->setupUi(this);
    this->setupModel();
    ui->tableView->setModel( this->model );
    ui->tableView->horizontalHeader()->setSectionResizeMode( QHeaderView::ResizeToContents );
    QStringList headers = { "姓名", "电话", "年龄" };
    this->model->setHorizontalHeaderLabels( headers );
    this->mapper = new QDataWidgetMapper( this );
    this->mapper->setModel( this->model );
    this->mapper->addMapping( ui->nameEdit, 0 );
    this->mapper->addMapping( ui->phoneEdit, 1 );
    this->mapper->addMapping( ui->ageSpinBox, 2 );

    this->connect( ui->prevButton, &QAbstractButton::clicked, this->mapper, &QDataWidgetMapper::toPrevious );
    this->connect( ui->nextButton, &QAbstractButton::clicked, this->mapper, &QDataWidgetMapper::toNext );
    this->connect( this->mapper, &QDataWidgetMapper::currentIndexChanged, this, &MainWindow::updateButtons );
    this->connect( ui->tableView, &QTableView::clicked,
        this, [this]( const QModelIndex & index ) { this->mapper->setCurrentIndex( index.row() ); } );
    this->mapper->toFirst();
    IntSpinDelegate * intSpinDelegate = new IntSpinDelegate( this );
    ui->tableView->setItemDelegateForColumn( 2, intSpinDelegate );
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::setupModel()
{
    this->model = new QStandardItemModel( 5, 3, this );
    QStringList names;
    names << "张三" << "李四" << "王五" << "丁一" << "刘二";
    QStringList phones;
    phones << "18111111111" << "18111111112" << "18111111113"
        << "18111111114" << "18111111115";
    QStringList ages;
    ages << "20" << "31" << "32" << "19" << "26";

    for ( int row = 0; row < 5; ++ row )
    {
        QStandardItem * item = new QStandardItem( names[ row ] );
        this->model->setItem( row, 0, item );

        item = new QStandardItem( phones[ row ] );
        this->model->setItem( row, 1, item );

        item = new QStandardItem( ages[ row ] );
        this->model->setItem( row, 2, item );
    }
}


void MainWindow::updateButtons( int row )
{
    ui->prevButton->setEnabled( row > 0 );
    ui->nextButton->setEnabled( row < this->model->rowCount() - 1 );
    QModelIndex index = model->index( row, 0 );
    //ui->tableView->setCurrentIndex( index );
    ui->tableView->selectRow( index.row() );
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    //this->mapper->setCurrentIndex( index.row() );
}

