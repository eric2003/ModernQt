﻿#include "dialog.h"
#include "./ui_dialog.h"
#include <QInputDialog>
#include <QDir>
#include <QColorDialog>
#include <QFontDialog>
#include <QFileDialog>
#include <QLabel>
#include <QMessageBox>
#include <QErrorMessage>

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
    this->errMsg = new QErrorMessage( this );
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

void Dialog::on_btnFont_clicked()
{
    QFontDialog::FontDialogOptions options;
    if ( ui->cbMonospacedFonts->isChecked() )
    {
        options |= QFontDialog::MonospacedFonts;
    }

    if ( ui->cbScalableFonts->isChecked() )
    {
        options |= QFontDialog::ScalableFonts;
    }

    if ( ui->cbNotScalableFonts->isChecked() )
    {
        options |= QFontDialog::NonScalableFonts;
    }

    if ( ui->cbNoButtons->isChecked() )
    {
        options |= QFontDialog::NoButtons;
    }

    if ( ui->cbDontUseNativeDialog->isChecked() )
    {
        options |= QFontDialog::DontUseNativeDialog;
    }

    if ( ui->cbProportionalFonts->isChecked() )
    {
        options |= QFontDialog::ProportionalFonts;
    }

    const QString & description = ui->labelFont->text();
    QFont defaultFont;
    if ( !description.isEmpty() ) defaultFont.fromString( description );
    bool ok;
    QFont font = QFontDialog::getFont( &ok, defaultFont, this, "选择字体", options);
    if ( ok )
    {
        ui->labelFont->setText( font.key() );
        ui->labelFont->setFont( font );
    }

}

void Dialog::on_btnDialogDir_clicked()
{
    QFileDialog::Options options;
    options |= QFileDialog::ShowDirsOnly;
    QString directory = QFileDialog::getExistingDirectory( this, "QFileDialog::getExistingDirectory()",
        ui->labelDialogDir->text(), options );
    if ( !directory.isEmpty() )
    {
        ui->labelDialogDir->setText( directory );
    }
}

void Dialog::on_btnDialogFileName_clicked()
{
    const QFileDialog::Options options;
    QString selectedFilter;
    QString fileName = QFileDialog::getOpenFileName( this, "QFileDialog::getOpenFileName()",
        ui->labelDialogFileName->text(),
        "All Filesd (*);;Text Files (*.txt)",
        &selectedFilter, options);
    qDebug() << selectedFilter;
    if ( !fileName.isEmpty() )
    {
        ui->labelDialogFileName->setText( fileName );
    }
}

void Dialog::on_btnDialogFileNames_clicked()
{
    const QFileDialog::Options options;
    QString selectedFilter;
    QStringList files = QFileDialog::getOpenFileNames( this, "QFileDialog::getOpenFileNames()",
        ui->labelDialogFileName->text(),
        tr("All Filesd (*);;Text Files (*.txt)"),
        &selectedFilter, options);
    qDebug() << selectedFilter;
    if ( files.count() )
    {
        ui->labelDialogFileNames->setText( QString( "[%1]" ).arg( files.join( ", " ) ) );
    }
}

void Dialog::on_btnDialogSaveFile_clicked()
{
    const QFileDialog::Options options;
    QString selectedFilter;
    QString fileName = QFileDialog::getSaveFileName( this, tr( "QFileDialog::getSaveFileName()" ),
        ui->labelSaveFileName->text(),
        tr("All Filesd (*);;Text Files (*.txt)"),
        &selectedFilter, options );
    qDebug() << selectedFilter;
    if ( ! fileName.isEmpty() )
    {
        ui->labelSaveFileName->setText( fileName );
    }
}

void Dialog::on_btnMsgBoxCritical_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::critical( this, tr( "QMessageBox::critical()" ), "MESSAGE",
        QMessageBox::Abort | QMessageBox::Retry | QMessageBox::Ignore );
    if ( reply == QMessageBox::Abort )
    {
        ui->labelMsgBoxCritical->setText( tr( "Abort" ) );
    }
    else if ( reply == QMessageBox::Retry )
    {
        ui->labelMsgBoxCritical->setText( tr( "Retry" ) );
    }
    else
    {
        ui->labelMsgBoxCritical->setText( tr( "Ignore" ) );
    }
}

void Dialog::on_btnMsgBoxInfo_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::information( this, tr( "QMessageBox::information()" ), "INFO" );
    if ( reply == QMessageBox::Ok )
    {
        ui->labelMsgBoxInfo->setText( tr( "OK" ) );
    }
}

void Dialog::on_btnMsgBoxQuestion_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question( this, tr( "QMessageBox::question()" ), "Question",
        QMessageBox::Yes | QMessageBox::No |QMessageBox::Cancel );
    if ( reply == QMessageBox::Yes )
    {
        ui->labelMsgBoxQuestion->setText( tr( "Yes" ) );
    }
    else if ( reply == QMessageBox::No )
    {
        ui->labelMsgBoxQuestion->setText( tr( "No" ) );
    }
    else
    {
        ui->labelMsgBoxQuestion->setText( tr( "Cancel" ) );
    }
}

void Dialog::on_btnMsgBoxWarning_clicked()
{
    QMessageBox msgBox( QMessageBox::Warning, tr( "QMessageBox::warning()" ), "Warning", { }, this );
    msgBox.setDetailedText( "MESSAGE_DETAILS" );
    msgBox.addButton( tr( "Save &Again" ), QMessageBox::AcceptRole );
    msgBox.addButton( tr( "&Continue" ), QMessageBox::RejectRole );
    if ( msgBox.exec() == QMessageBox::AcceptRole )
    {
        ui->labelMsgBoxWarning->setText( tr( "Save Again" ) );
    }
    else
    {
        ui->labelMsgBoxWarning->setText( tr( "Continue" ) );
    }
}

void Dialog::on_btnMsgBoxShowMsg_clicked()
{
    errMsg->showMessage( tr( "MESSAGE" ) );
    ui->labelMsgBoxShowMsg->setText( tr( "MESSAGE" ) );
}