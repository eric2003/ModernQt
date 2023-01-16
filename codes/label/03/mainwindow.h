#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QPushButton;
class QLabel;
class QCheckBox;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    QPushButton * clickBtn;
    QLabel * label;
    QCheckBox * cb;
protected:
    void onClick();
    void onCheck( int state );
    void timerEvent( QTimerEvent * event ) override;
};
#endif // MAINWINDOW_H
