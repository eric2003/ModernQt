#include "myopenglwidget.h"

MyOpenGLWidget::MyOpenGLWidget(QWidget *parent)
    : QOpenGLWidget{parent}
{

}

void MyOpenGLWidget::initializeGL()
{
    this->initializeOpenGLFunctions();
}

void MyOpenGLWidget::resizeGL(int w, int h)
{
    //this->glViewport( 0, 0, w, h );

}

void MyOpenGLWidget::paintGL()
{
    //this->glClearColor( 0.2f, 0.3f, 0.3f, 1.0f );
    //this->glClearColor( 1.0f, 1.0f, 1.0f, 1.0f );
    this->glClearColor( 1.0f, 0.0f, 0.0f, 1.0f );
    this->glClear( GL_COLOR_BUFFER_BIT );

}
