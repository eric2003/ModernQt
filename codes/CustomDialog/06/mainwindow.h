#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "orderdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionNew_triggered();
    void on_actionPrint_triggered();

private:
    void createLetter(const QString &name, const QString &address,
                      QList<OrderDialog::OrderItemType> orderItems,
                      bool sendOffers );
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
