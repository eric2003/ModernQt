#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget( ui->openGLWidget );
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionDrawRect_triggered()
{
    this->ui->openGLWidget->drawShape( MyOpenGLWidget::Rect );
}

