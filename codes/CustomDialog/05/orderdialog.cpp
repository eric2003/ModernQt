#include "orderdialog.h"
#include "ui_orderdialog.h"

OrderDialog::OrderDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OrderDialog)
{
    ui->setupUi(this);
    this->setupOrderItems();
}

OrderDialog::~OrderDialog()
{
    delete ui;
}

QString OrderDialog::senderName() const
{
    return ui->lineEditName->text();

}

QString OrderDialog::senderAddress() const
{
    return ui->textEditAddress->toPlainText();
}

bool OrderDialog::sendOffers()
{
    return ui->checkBox->isChecked();

}

QList<OrderDialog::OrderItemType> OrderDialog::orderItems() const
{
    QList<OrderItemType> items;
    for( int row = 0; row < ui->tableWidget->rowCount(); ++ row )
    {
        OrderItemType item;
        item.first = ui->tableWidget->item(row,0)->text();
        item.second = ui->tableWidget->item(row,1)->text().toInt();
        items.append( item );
    }
    return items;
}

void OrderDialog::setupOrderItems()
{
    QStringList headers{"名称","数量"};
    QStringList items;
    items << "小汽车" << "射水枪" << "参考书" << "咖啡杯";
    ui->tableWidget->setRowCount(items.count());
    ui->tableWidget->setColumnCount( 2 );
    ui->tableWidget->setHorizontalHeaderLabels( headers );
    for( int row = 0; row < items.count(); ++ row )
    {
        QTableWidgetItem *name = new QTableWidgetItem(items[row]);
        QTableWidgetItem *number = new QTableWidgetItem("1");
        name->setTextAlignment( Qt::AlignCenter );
        number->setTextAlignment( Qt::AlignCenter );
        ui->tableWidget->setItem( row, 0, name );
        ui->tableWidget->setItem( row, 1, number );
    }


}
