#include "myopenglwidget.h"
#include <QOpenGLShader>

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

//const char * vertexShaderSource = "#version 330 core\n"
//        "layout (location = 0) in vec3 aPos;\n" "void main()\n"
//        "{\n"
//        " gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
//        "}\n\0";
//const char * fragmentShaderSource = "#version 330 core\n"
//        "out vec4 FragColor;\n"
//        "void main()\n"
//        "{\n"
//        " FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
//        "}\n\0";

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
    GLint posLocation = shaderProgram.attributeLocation( "aPos" );

    //this->glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof( float ), (void * )0 );
    //this->glEnableVertexAttribArray( 0 );
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
