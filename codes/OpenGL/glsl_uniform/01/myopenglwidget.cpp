#include "myopenglwidget.h"
#include <QOpenGLShader>
#include <QTime>

float vertices[] = {
    0.5f, 0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    -0.5f, -0.5f, 0.0f,
    -0.5f, 0.5f, 0.0f
};


unsigned int indices[] = {
    0, 1, 3,
    1, 2, 3
};

unsigned int VBO, VAO, EBO;
QOpenGLShaderProgram shaderProgram;

MyOpenGLWidget::MyOpenGLWidget(QWidget *parent)
    : QOpenGLWidget{parent}
{
    this->timer.start( 100 );
    this->connect(&timer, &QTimer::timeout, this, &MyOpenGLWidget::on_timeout );

}

MyOpenGLWidget::~MyOpenGLWidget()
{
    this->makeCurrent();
    this->glDeleteBuffers( 1, & VBO );
    this->glDeleteBuffers( 1, & EBO );
    this->glDeleteVertexArrays( 1, & VAO );
    this->doneCurrent();

}

void MyOpenGLWidget::drawShape(Shape shape)
{
    this->shape = shape;
    this->update();
}

void MyOpenGLWidget::setWireframe(bool wireframe)
{
    this->makeCurrent();
    if ( wireframe )
    {
        this->glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
    }
    else
    {
        this->glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
    }
    this->update();
    this->doneCurrent();
}

void MyOpenGLWidget::initializeGL()
{
    this->initializeOpenGLFunctions();

    shaderProgram.addShaderFromSourceFile( QOpenGLShader::Vertex, ":/myshaders/shapes.vert" );
    shaderProgram.addShaderFromSourceFile( QOpenGLShader::Fragment, ":/myshaders/shapes.frag" );

    bool success = shaderProgram.link();
    if ( ! success )
    {
        qDebug() << "ERR:" << shaderProgram.log();
    }

    this->glGenVertexArrays( 1, &VAO );
    this->glGenBuffers( 1, &VBO );

    this->glBindVertexArray( VAO );
    this->glBindBuffer( GL_ARRAY_BUFFER, VBO );

    this->glBufferData( GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW );
    shaderProgram.bind();
    //GLint posLocation = shaderProgram.attributeLocation( "aPos" );
    GLint posLocation = 2;
    shaderProgram.bindAttributeLocation( "aPos", posLocation );

    this->glVertexAttribPointer( posLocation, 3, GL_FLOAT, GL_FALSE, 3 * sizeof( float ), (void * )0 );
    this->glEnableVertexAttribArray( posLocation );



    this->glGenBuffers( 1, &EBO );
    this->glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, EBO );
    this->glBufferData( GL_ELEMENT_ARRAY_BUFFER, sizeof( indices ), indices, GL_STATIC_DRAW );


}

void MyOpenGLWidget::resizeGL(int w, int h)
{
    //this->glViewport( 0, 0, w, h );

}

void MyOpenGLWidget::paintGL()
{
    this->glClearColor( 0.2f, 0.3f, 0.3f, 1.0f );
    this->glClear( GL_COLOR_BUFFER_BIT );
    shaderProgram.bind();
    this->glBindVertexArray( VAO );
    switch ( shape ) {
    case Rect:
        this->glDrawElements( GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0 );
        break;
    default:
        break;
    }


}

void MyOpenGLWidget::on_timeout()
{
    if ( this->shape == Shape::None ) return;
    this->makeCurrent();
    int timeValue = QTime::currentTime().second();
    float greenValue = ( sin( timeValue ) / 2.0f ) + 0.5f;
    shaderProgram.setUniformValue("ourColor", 0.0f, greenValue, 0.0f, 1.0f );
    this->doneCurrent();
    this->update();
}
