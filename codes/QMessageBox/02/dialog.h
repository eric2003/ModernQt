#pragma once
#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
private slots:
    void on_btnInputInt_clicked();
    void on_btnInputDouble_clicked();
    void on_btnInputItem_clicked();
    void on_btnInputText_clicked();
    void on_btnInputMultiLine_clicked();
    void on_btnColor_clicked();
    void on_btnFont_clicked();
    void on_btnDialogDir_clicked();
    void on_btnDialogFileName_clicked();
    void on_btnDialogFileNames_clicked();
    void on_btnDialogSaveFile_clicked();
    void on_btnMsgBoxCritical_clicked();
    void on_btnMsgBoxInfo_clicked();
private:
    Ui::Dialog *ui;
};