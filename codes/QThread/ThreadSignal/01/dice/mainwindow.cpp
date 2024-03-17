#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&threadA,SIGNAL(started()),this,SLOT(onthreadA_started()));
    connect(&threadA,SIGNAL(finished()),this,SLOT(onthreadA_finished()));

    connect(&threadA,SIGNAL(newValue(int,int)),this,SLOT(onthreadA_newValue(int,int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{ //窗口关闭事件，必须结束线程
    if (threadA.isRunning())
    {
        threadA.stopThread();
        threadA.wait();
    }
    event->accept();
}

void MainWindow::onthreadA_started()
{//线程的started()信号的响应槽函数
    ui->LabA->setText("Thread状态：thread started");
}

void MainWindow::onthreadA_finished()
{//线程的 finished()信号的响应槽函数
    ui->LabA->setText("Thread状态：thread finished");
}

void MainWindow::onthreadA_newValue(int seq,int diceValue)
{//QDiceThread的newValue()信号的响应槽函数，显示骰子次数和点数
    QString  str=QString::asprintf("第 %d 次掷骰子，点数为：%d",seq,diceValue);
    ui->plainTextEdit->appendPlainText(str);

    QPixmap pic; //图片显示
    QString filename=QString::asprintf(":/dice/images/d%d.jpg",diceValue);
    pic.load(filename);
    ui->LabPic->setPixmap(pic);
}

void MainWindow::on_btnClear_clicked()
{ //清空文本 按钮
    ui->plainTextEdit->clear();
}

void MainWindow::on_btnDiceEnd_clicked()
{//暂停 掷骰子按钮
    threadA.dicePause();
    ui->btnDiceBegin->setEnabled(true);
    ui->btnDiceEnd->setEnabled(false);
}

void MainWindow::on_btnDiceBegin_clicked()
{//开始 掷骰子按钮
    threadA.diceBegin();
    ui->btnDiceBegin->setEnabled(false);
    ui->btnDiceEnd->setEnabled(true);
}

void MainWindow::on_btnStopThread_clicked()
{//结束线程 按钮
    threadA.stopThread();//结束线程的run()函数执行
    threadA.wait();//

    ui->btnStartThread->setEnabled(true);
    ui->btnStopThread->setEnabled(false);

    ui->btnDiceBegin->setEnabled(false);
    ui->btnDiceEnd->setEnabled(false);
}

void MainWindow::on_btnStartThread_clicked()
{//启动线程 按钮
    threadA.start();

    ui->btnStartThread->setEnabled(false);
    ui->btnStopThread->setEnabled(true);

    ui->btnDiceBegin->setEnabled(true);
    ui->btnDiceEnd->setEnabled(false);
}

