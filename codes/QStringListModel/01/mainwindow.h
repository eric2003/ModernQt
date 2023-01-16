#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QStringListModel;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_btnClear_clicked();
    void on_btnModify_clicked();
    void on_btnAdd_clicked();
    void on_btnDelete_clicked();
private:
    QStringListModel * model;
private:
    Ui::MainWindow *ui;
};