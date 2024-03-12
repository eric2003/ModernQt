#ifndef MYOPENGLWIDGET_H
#define MYOPENGLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions_4_5_Core>
#include <QTimer>

class MyOpenGLWidget : public QOpenGLWidget, QOpenGLFunctions_4_5_Core
{
    Q_OBJECT
public:
    enum Shape{ None, Rect, Circle, Triangle };
    explicit MyOpenGLWidget(QWidget *parent = nullptr);
    ~MyOpenGLWidget();

    void drawShape( Shape shape );
    void setWireframe( bool wireframe );

protected:
    virtual void initializeGL();
    virtual void resizeGL(int w, int h);
    virtual void paintGL();

signals:
public slots:
    void on_timeout();
private:
    Shape shape;
    QTimer timer;
};

#endif // MYOPENGLWIDGET_H
