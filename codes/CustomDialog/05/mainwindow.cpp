#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTextEdit>
#include <QTabWidget>
#include <QTextCursor>
#include <QDialog>
#include <QTextCharFormat>
#include <QTextTableFormat>
#include <QTextTable>
#include <QDate>
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
        this->createLetter( dlg.senderName(), dlg.senderAddress(),
                            dlg.orderItems(), dlg.sendOffers() );
    }
}

void MainWindow::createLetter(const QString &name, const QString &address,
                  QList<OrderDialog::OrderItemType> orderItems,
                  bool sendOffers )
{
    QTextEdit *editor = new QTextEdit( this );
    int tabIndex = ui->tabWidget->addTab( editor, name );
    ui->tabWidget->setCurrentIndex( tabIndex );

    QTextCursor cursor( editor->textCursor() );
    cursor.movePosition( QTextCursor::Start );

    QTextCharFormat textFormat;
    QTextCharFormat boldFormat;
    boldFormat.setFontWeight(QFont::Bold);

    cursor.insertText( name, textFormat );
    const QStringList lines = address.split('\n');
    for ( const QString &line : lines )
    {
        cursor.insertBlock();
        cursor.insertText(line);
    }
    cursor.insertBlock();
    cursor.insertBlock();
    QDate date = QDate::currentDate();
    cursor.insertText(tr("Date: %1").arg(date.toString("d MMMM yyyy")), textFormat);
    cursor.insertBlock();
    cursor.insertText(tr("I would like to place an order for the following "
                          "items:"),textFormat);
    cursor.insertBlock();

    QTextTableFormat orderTableFormat;
    orderTableFormat.setAlignment(Qt::AlignHCenter);
    QTextTable *orderTable = cursor.insertTable(1,2,orderTableFormat);
    cursor = orderTable->cellAt(0,0).firstCursorPosition();
    cursor.insertText(tr("产品"),textFormat);
    cursor = orderTable->cellAt(0,1).firstCursorPosition();
    cursor.insertText(tr("数量"),textFormat);
    for(int i = 0; i< orderItems.count(); ++ i)
    {
        OrderDialog::OrderItemType item = orderItems[i];
        int row = orderTable->rows();
        orderTable->insertRows( row, 1);

        cursor = orderTable->cellAt(row,0).firstCursorPosition();
        cursor.insertText(item.first,textFormat);
        cursor = orderTable->cellAt(row,1).firstCursorPosition();
        cursor.insertText(QString("%1").arg(item.second),textFormat);
    }
    cursor.movePosition( QTextCursor::End );
    QTextTable *offersTable = cursor.insertTable(2,2);
    cursor = offersTable->cellAt(0,1).firstCursorPosition();
    cursor.insertText(tr("我愿意接收产品活动信息"),textFormat);
    cursor = offersTable->cellAt(1,1).firstCursorPosition();
    cursor.insertText(tr("我不愿意接收产品活动信息"),textFormat);
    if ( sendOffers )
    {
        cursor = offersTable->cellAt(0,0).firstCursorPosition();
    }
    else
    {
        cursor = offersTable->cellAt(1,0).firstCursorPosition();
    }
    cursor.insertText("X",boldFormat);
}


