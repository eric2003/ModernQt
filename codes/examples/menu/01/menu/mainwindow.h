#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    // The events that can be triggered
private slots:
    void open();
private:
    void createActions();
    void createMenus();
private:
    QMenu *fileMenu;
    QAction *openAct;
};
#endif // MAINWINDOW_H
