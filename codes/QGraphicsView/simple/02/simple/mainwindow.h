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
private slots:
    void on_keyPress(QKeyEvent *event);
    void on_mouseDoubleClicked(QPoint point);
    void on_mouseClicked(QPoint point);
    void on_actItem_Rect_triggered();

    void on_actItem_Ellipse_triggered();

    void on_actItem_Circle_triggered();

    void on_actItem_Line_triggered();

    void on_actItem_Polygon_triggered();

    void on_actItem_Triangle_triggered();

    void on_actItem_Text_triggered();

    void on_actZoomIn_triggered();

    void on_actZoomOut_triggered();

    void on_actRestore_triggered();

    void on_actRotateLeft_triggered();

    void on_actRotateRight_triggered();

    void on_actEdit_Front_triggered();

    void on_actEdit_Back_triggered();

    void on_actGroup_triggered();

    void on_actGroupBreak_triggered();

    void on_actEdit_Delete_triggered();

private:
    Ui::MainWindow *ui;
private:
    QLabel *labItemInfo;
    QLabel *labViewCord;
    QLabel *labSceneCord;
    QLabel *labItemCord;
    QGraphicsScene *scene;
private:
    static const int ItemId = 1;
    static const int ItemDescription = 2;
    int seqNum = 0;
};
#endif // MAINWINDOW_H
