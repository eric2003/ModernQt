#include "dialog.h"
#include "./ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->toolBox->setItemText( 0, "输入对话框" );
    ui->toolBox->setItemText( 1, "颜色对话框" );
    ui->toolBox->setItemText( 2, "字体对话框" );
    ui->toolBox->setItemText( 3, "文件对话框" );
    ui->toolBox->setItemText( 4, "消息对话框" );
}

Dialog::~Dialog()
{
    delete ui;
}
