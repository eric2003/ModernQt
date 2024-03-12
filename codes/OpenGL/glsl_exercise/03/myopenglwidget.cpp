#include "myopenglwidget.h"
#include <QOpenGLShader>

float vertices[] = {
    0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
    0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
    -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
    -0.5f, 0.5f, 0.0f, 0.5f, 0.5f, 0.5f
};


unsigned int indices[] = {
    1, 2, 3,
    0, 1, 3
};

unsigned int VBO, VAO, EBO;
QOpenGLShaderProgram shaderProgram;

MyOpenGLWidget::MyOpenGLWidget(QWidget *parent)
    : QOpenGLWidget{parent}
{

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

    this->glGenVertexArrays( 1, &VAO );
    this->glGenBuffers( 1, &VBO );

    this->glBindVertexArray( VAO );
    this->glBindBuffer( GL_ARRAY_BUFFER, VBO );

    this->glBufferData( GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW );
    this->glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof( float ), (void * )0 );
    this->glEnableVertexAttribArray( 0 );
    this->glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof( float ), (void * )( 3 * sizeof( float ) ) );
    this->glEnableVertexAttribArray( 1 );

    shaderProgram.addShaderFromSourceFile( QOpenGLShader::Vertex, ":/myshaders/shapes.vert" );
    shaderProgram.addShaderFromSourceFile( QOpenGLShader::Fragment, ":/myshaders/shapes.frag" );

    bool success = shaderProgram.link();
    if ( ! success )
    {
        qDebug() << "ERR:" << shaderProgram.log();
    }

    shaderProgram.bind();
    shaderProgram.setUniformValue( "xOffset", 0.4f );

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
        //this->glDrawElements( GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0 );
        this->glDrawElements( GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0 );
        break;
    default:
        break;
    }


}
