#include "myopenglwidget.h"

float firstTriangle[] = {
    -0.9f, -0.5f, 0.0f,
    -0.0f, -0.5f, 0.0f,
    -0.45f, 0.5f, 0.0f
};

float secondTriangle[] = {
    0.0f, -0.5f, 0.0f,
    0.9f, -0.5f, 0.0f,
    0.45f, 0.5f, 0.0f
};
unsigned int VBOs[2], VAOs[2];
unsigned int shaderProgram1, shaderProgram2;

const char * vertexShaderSource = "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n" "void main()\n"
        "{\n"
        " gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "}\n\0";
const char * fragmentShaderSource = "#version 330 core\n"
        "out vec4 FragColor;\n"
        "void main()\n"
        "{\n"
        " FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
        "}\n\0";
const char * fragmentShaderSource2 = "#version 330 core\n"
        "out vec4 FragColor;\n"
        "void main()\n"
        "{\n"
        " FragColor = vec4(1.0f, 1.0f, 0.0f, 1.0f);\n"
        "}\n\0";

MyOpenGLWidget::MyOpenGLWidget(QWidget *parent)
    : QOpenGLWidget{parent}
{

}

void MyOpenGLWidget::initializeGL()
{
    this->initializeOpenGLFunctions();


    this->glGenVertexArrays( 2, VAOs );
    this->glGenBuffers( 2, VBOs );

    this->glBindVertexArray( VAOs[ 0 ]);
    this->glBindBuffer( GL_ARRAY_BUFFER, VBOs[ 0 ] );

    this->glBufferData( GL_ARRAY_BUFFER, sizeof(firstTriangle), firstTriangle, GL_STATIC_DRAW );
    this->glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof( float ), (void * )0 );
    this->glEnableVertexAttribArray( 0 );
    this->glBindBuffer( GL_ARRAY_BUFFER, 0 );

    this->glBindVertexArray( 0 );

    this->glBindVertexArray( VAOs[ 1 ]);
    this->glBindBuffer( GL_ARRAY_BUFFER, VBOs[ 1 ] );
    this->glBufferData( GL_ARRAY_BUFFER, sizeof(secondTriangle), secondTriangle, GL_STATIC_DRAW );
    this->glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof( float ), (void * )0 );
    this->glEnableVertexAttribArray( 0 );
    this->glBindBuffer( GL_ARRAY_BUFFER, 0 );

    unsigned int vertexShader = this->glCreateShader( GL_VERTEX_SHADER );
    this->glShaderSource( vertexShader, 1, & vertexShaderSource, NULL );
    this->glCompileShader( vertexShader );

    unsigned int fragmentShader = this->glCreateShader( GL_FRAGMENT_SHADER );
    this->glShaderSource( fragmentShader, 1, & fragmentShaderSource, NULL );
    this->glCompileShader( fragmentShader );

    unsigned int fragmentShader2 = this->glCreateShader( GL_FRAGMENT_SHADER );
    this->glShaderSource( fragmentShader2, 1, & fragmentShaderSource2, NULL );
    this->glCompileShader( fragmentShader2 );

    shaderProgram1 = this->glCreateProgram();
    this->glAttachShader( shaderProgram1, vertexShader );
    this->glAttachShader( shaderProgram1, fragmentShader );
    this->glLinkProgram( shaderProgram1 );

    shaderProgram2 = this->glCreateProgram();
    this->glAttachShader( shaderProgram2, vertexShader );
    this->glAttachShader( shaderProgram2, fragmentShader2 );
    this->glLinkProgram( shaderProgram2 );

    this->glDeleteShader( vertexShader );
    this->glDeleteShader( fragmentShader );
    this->glDeleteShader( fragmentShader2 );


}

void MyOpenGLWidget::resizeGL(int w, int h)
{
    //this->glViewport( 0, 0, w, h );

}

void MyOpenGLWidget::paintGL()
{
    this->glClearColor( 0.2f, 0.3f, 0.3f, 1.0f );
    this->glClear( GL_COLOR_BUFFER_BIT );
    this->glUseProgram( shaderProgram1 );
    this->glBindVertexArray( VAOs[ 0 ]);
    this->glDrawArrays( GL_TRIANGLES, 0, 3 );
    this->glUseProgram( shaderProgram2 );
    this->glBindVertexArray( VAOs[ 1 ]);
    this->glDrawArrays( GL_TRIANGLES, 0, 3 );

}
