#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTextEdit>
#include <QTabWidget>
#include <QTextCursor>
#include <QDialog>
#include "orderdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget->setTabsClosable( true );
    this->connect(ui->tabWidget, &QTabWidget::tabCloseRequested, this,
                  [=](int index){ ui->tabWidget->removeTab(index); }
                  );

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    OrderDialog dlg( this );
    if ( dlg.exec() == QDialog::Accepted )
    {
        QTextEdit *editor = new QTextEdit( this );
        int tabIndex = ui->tabWidget->addTab( editor, dlg.senderName() );
        ui->tabWidget->setCurrentIndex( tabIndex );

        QTextCursor cursor( editor->textCursor() );
        cursor.movePosition( QTextCursor::Start );
        cursor.insertText( "eric\nchengdu");

        cursor.movePosition( QTextCursor::End );
    }

}

