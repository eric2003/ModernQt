#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "qdicethread.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QDiceThread   threadA;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void    closeEvent(QCloseEvent *event);
private slots:
    void    onthreadA_started();
    void    onthreadA_finished();
    void    onthreadA_newValue(int seq, int diceValue);

    void on_btnClear_clicked();

    void on_btnDiceEnd_clicked();

    void on_btnDiceBegin_clicked();

    void on_btnStopThread_clicked();

    void on_btnStartThread_clicked();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
