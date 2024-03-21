#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void paintEvent(QPaintEvent *event);
private:
    void SimpleDraw1();
    void SimpleDraw2();
    void SimpleDraw3();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
