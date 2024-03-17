#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(this->ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    this->currentFile.clear();
    this->ui->textEdit->setText(QString());
}


void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,"Open the file");
    QFile file(fileName);
    this->currentFile = fileName;
    if(!file.open(QFile::ReadOnly|QFile::Text)){
        QMessageBox::warning(this,"Warning","Cannot open file : " + file.errorString());
        return;
    }
    this->setWindowTitle(fileName);
    QTextStream in(&file);
    QString text = in.readAll();
    this->ui->textEdit->setText(text);
    file.close();
}


void MainWindow::on_actionSave_as_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,"Save as");
    QFile file(fileName);
    this->currentFile = fileName;
    if(!file.open(QFile::WriteOnly|QFile::Text)){
        QMessageBox::warning(this,"Warning","Cannot save file : " + file.errorString());
        return;
    }
    this->setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = this->ui->textEdit->toPlainText();
    out << text;
    file.close();

}


void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}


void MainWindow::on_actionCopy_triggered()
{
    this->ui->textEdit->copy();
}


void MainWindow::on_actionPaste_triggered()
{
    this->ui->textEdit->paste();
}


void MainWindow::on_actionCut_triggered()
{
    this->ui->textEdit->cut();
}


void MainWindow::on_actionUndo_triggered()
{
    this->ui->textEdit->undo();
}


void MainWindow::on_actionRedo_triggered()
{
    this->ui->textEdit->redo();
}

