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
private:
    Ui::Dialog *ui;
};