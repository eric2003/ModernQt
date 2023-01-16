#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QStandardItemModel;
class QDataWidgetMapper;
class QModelIndex;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_tableView_clicked(const QModelIndex &index);
private:
    void updateButtons( int row );
    void setupModel();
private:
    QStandardItemModel * model;
    QDataWidgetMapper * mapper;
private:
    Ui::MainWindow *ui;
};