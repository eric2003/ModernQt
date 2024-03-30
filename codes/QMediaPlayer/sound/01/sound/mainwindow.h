#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class QMediaPlayer;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_playButton_clicked();

    void on_stopButton_clicked();

    void on_pauseButton_clicked();

private:
    Ui::MainWindow *ui;
    QMediaPlayer * music;
};
#endif // MAINWINDOW_H
