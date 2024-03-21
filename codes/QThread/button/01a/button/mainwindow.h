#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QPushButton;
class QLabel;
class MyThread;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QPushButton *startButton;
    QLabel * numberLabel;
    MyThread * mThread;
};
#endif // MAINWINDOW_H
