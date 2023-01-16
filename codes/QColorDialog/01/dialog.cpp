﻿#include "dialog.h"
#include "./ui_dialog.h"
#include <QInputDialog>
#include <QDir>
#include <QColorDialog>
#include <QLabel>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setMinimumWidth( 420 );
    ui->toolBox->setItemText( 0, "输入对话框" );
    ui->toolBox->setItemText( 1, "颜色对话框" );
    ui->toolBox->setItemText( 2, "字体对话框" );
    ui->toolBox->setItemText( 3, "文件对话框" );
    ui->toolBox->setItemText( 4, "消息对话框" );
    ui->toolBox->setCurrentIndex( 0 );
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_btnInputInt_clicked()
{
    bool ok = false;
    int val = 15, min_value = 0, max_value = 100, stp = 1;
    int i = QInputDialog::getInt( this, "QInputDialog::getInt", "百分比", val, min_value, max_value, stp, &ok );
    if ( ok )
    {
        ui->inputIntEdit->setText( QString::number( i ) + "%" );
    }
}

void Dialog::on_btnInputDouble_clicked()
{
    bool ok = false;
    qreal val = 37.5, min_value = 0.0, max_value = 100.0, stp = 0.1;
    int decimals = 1;
    double d = QInputDialog::getDouble( this, "QInputDialog::getDouble", "金额", 
        val, min_value, max_value, decimals, &ok, Qt::WindowFlags(), stp );
    if ( ok )
    {
        ui->inputDoubleEdit->setText( "￥" + QString::number(d) );
    }
}

void Dialog::on_btnInputItem_clicked()
{
    QStringList items;
    items << "春" << "夏" << "秋" << "冬";
    bool ok = false;
    int current = 0;
    bool editable = false;
    QString item = QInputDialog::getItem( this, "QInputDialog::getItem", "季节",
        items, current, editable, &ok );
    if ( ok && !item.isEmpty() )
    {
        ui->inputItemEdit->setText( item );
    }
}

void Dialog::on_btnInputText_clicked()
{
    bool ok = false;
    QString text = QInputDialog::getText( this, "QInputDialog::getText", "用户名:",
        QLineEdit::Normal, QDir::home().dirName(), &ok );
    if ( ok && !text.isEmpty() )
    {
        ui->inputTextEdit->setText( text );
    }
}

void Dialog::on_btnInputMultiLine_clicked()
{
    bool ok = false;
    QString text = QInputDialog::getMultiLineText( this, "QInputDialog::getMultiLineText", "地址:",
        "John Doe\nFreedom Street", &ok );
    if ( ok && !text.isEmpty() )
    {
        ui->inputMultiLineEdit->setText( text );
    }
}

void Dialog::on_btnColor_clicked()
{
    QColorDialog::ColorDialogOptions options;
    if ( ui->checkBoxNotNative->isChecked() )
    {
        options |= QColorDialog::DontUseNativeDialog;
    }

    if ( ui->checkBoxNoButton->isChecked() )
    {
        options |= QColorDialog::NoButtons;
    }

    if ( ui->checkBoxShowAlpha->isChecked() )
    {
        options |= QColorDialog::ShowAlphaChannel;
    }

    const QColor color = QColorDialog::getColor( Qt::green, this, "选择颜色", options );
    if ( color.isValid() )
    {
        ui->labelColor->setText( color.name() );
        ui->labelColor->setPalette( QPalette(color) );
        ui->labelColor->setAutoFillBackground( true );
    }

}
