#include "myopenglwidget.h"

//float vertices[] = {
//    -0.5f, -0.5f, 0.0f,
//    0.5f, -0.5f, 0.0f,
//    0.0f, 0.5f, 0.0f
//};

float vertices[] = {
    0.5f, 0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    -0.5f, 0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    -0.5f, -0.5f, 0.0f,
    -0.5f, 0.5f, 0.0f
};


unsigned int VBO, VAO;
unsigned int shaderProgram;

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

MyOpenGLWidget::MyOpenGLWidget(QWidget *parent)
    : QOpenGLWidget{parent}
{

}

void MyOpenGLWidget::initializeGL()
{
    this->initializeOpenGLFunctions();

    this->glGenVertexArrays( 1, &VAO );
    this->glGenBuffers( 1, &VBO );

    this->glBindVertexArray( VAO );
    this->glBindBuffer( GL_ARRAY_BUFFER, VBO );

    this->glBufferData( GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW );
    this->glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof( float ), (void * )0 );
    this->glEnableVertexAttribArray( 0 );
    this->glBindBuffer( GL_ARRAY_BUFFER, 0 );
    this->glBindVertexArray( 0 );

    unsigned int vertexShader = this->glCreateShader( GL_VERTEX_SHADER );
    this->glShaderSource( vertexShader, 1, & vertexShaderSource, NULL );
    this->glCompileShader( vertexShader );

    unsigned int fragmentShader = this->glCreateShader( GL_FRAGMENT_SHADER );
    this->glShaderSource( fragmentShader, 1, & fragmentShaderSource, NULL );
    this->glCompileShader( fragmentShader );

    shaderProgram = this->glCreateProgram();
    this->glAttachShader( shaderProgram, vertexShader );
    this->glAttachShader( shaderProgram, fragmentShader );
    this->glLinkProgram( shaderProgram );

    this->glDeleteShader( vertexShader );
    this->glDeleteShader( fragmentShader );


}

void MyOpenGLWidget::resizeGL(int w, int h)
{
    //this->glViewport( 0, 0, w, h );

}

void MyOpenGLWidget::paintGL()
{
    this->glClearColor( 0.2f, 0.3f, 0.3f, 1.0f );
    this->glClear( GL_COLOR_BUFFER_BIT );
    this->glUseProgram( shaderProgram );
    this->glBindVertexArray( VAO );
    this->glDrawArrays( GL_TRIANGLES, 0, 6 );



}
