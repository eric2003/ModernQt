#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class QLabel;
class QGraphicsScene;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    void InitGraphics();

private slots:
    void on_mouseMovePoint(QPoint point);
    void on_mouseClicked(QPoint point);

private:
    Ui::MainWindow *ui;
private:
    QLabel *labViewCord;
    QLabel *labSceneCord;
    QLabel *labItemCord;
    QGraphicsScene *scene;
};
#endif // MAINWINDOW_H
