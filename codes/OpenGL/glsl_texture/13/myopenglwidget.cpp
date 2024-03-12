#include "myopenglwidget.h"
#include <QOpenGLShader>
#include <QKeyEvent>

//float vertices[] = {
//    0.9f, 0.9f, 0.0f, 1.0f, 0.0f, 0.0f, 0.55f,0.55f, //top right
//    0.9f, -0.9f, 0.0f, 0.0f, 1.0f, 0.0f, 0.55f,0.45f, //bottom right
//    -0.9f, -0.9f, 0.0f, 0.0f, 0.0f, 1.0f, 0.45f,0.45f, //bottom left
//    -0.9f, 0.9f, 0.0f, 1.0f, 1.0f, 0.0f, 0.45,0.55f //top left
//};

//float vertices[] = {
//    0.9f, 0.9f, 0.0f, 1.0f, 0.0f, 0.0f, 2.0f,2.0f, //top right
//    0.9f, -0.9f, 0.0f, 0.0f, 1.0f, 0.0f, 2.0f,-1.0f, //bottom right
//    -0.9f, -0.9f, 0.0f, 0.0f, 0.0f, 1.0f, -1.0f,-1.0f, //bottom left
//    -0.9f, 0.9f, 0.0f, 1.0f, 1.0f, 0.0f, -1.0f,2.0f //top left
//};

float vertices[] = {
    0.9f, 0.9f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,1.0f, //top right
    0.9f, -0.9f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,0.0f, //bottom right
    -0.9f, -0.9f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,0.0f, //bottom left
    -0.9f, 0.9f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f,1.0f //top left
};


unsigned int indices[] = {
    0, 1, 3,
    1, 2, 3
};

float ratio = 0.5;

unsigned int VBO, VAO, EBO;
QOpenGLShaderProgram shaderProgram;

MyOpenGLWidget::MyOpenGLWidget(QWidget *parent)
    : QOpenGLWidget{parent}
{
    this->setFocusPolicy( Qt::StrongFocus );
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
    this->glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof( float ), (void * )0 );
    this->glEnableVertexAttribArray( 0 );
    this->glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof( float ), (void * )( 3 * sizeof( float ) ) );
    this->glEnableVertexAttribArray( 1 );
    this->glVertexAttribPointer( 2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof( float ), (void * )( 6 * sizeof( float ) ) );
    this->glEnableVertexAttribArray( 2 );

    this->glGenBuffers( 1, &EBO );
    this->glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, EBO );
    this->glBufferData( GL_ELEMENT_ARRAY_BUFFER, sizeof( indices ), indices, GL_STATIC_DRAW );

    shaderProgram.addShaderFromSourceFile( QOpenGLShader::Vertex, ":/myshaders/shapes.vert" );
    shaderProgram.addShaderFromSourceFile( QOpenGLShader::Fragment, ":/myshaders/shapes.frag" );

    bool success = shaderProgram.link();
    if ( ! success )
    {
        qDebug() << "ERR:" << shaderProgram.log();
    }

    this->glEnable( GL_BLEND );
    this->glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

    this->textureWall = new QOpenGLTexture( QImage(":/imagespre/images/wall.jpg").mirrored() );
    this->textureSmile = new QOpenGLTexture( QImage(":/imagespre/images/awesomeface.png").mirrored() );
    this->textureSmall = new QOpenGLTexture( QImage(":/imagespre/images/texture_small.png").mirrored() );
    this->textureSmall->generateMipMaps();
    shaderProgram.bind();
    shaderProgram.setUniformValue( "ratio", ratio );
    shaderProgram.setUniformValue( "textureWall", 0 );
    shaderProgram.setUniformValue( "textureSmile", 1 );
    shaderProgram.setUniformValue( "textureSmall", 2 );

    this->textureSmile->bind(2);
    //this->textureSmall->bind(2);
    //this->glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER );
    //this->glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER );
    this->glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT );
    this->glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
    this->glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST );
    //this->glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
    this->glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );

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

    float borderColor [] = { 1.0f, 1.0f, 0.0f, 1.0f };
    switch ( shape ) {
    case Rect:
        this->textureWall->bind(0);
        this->textureSmile->bind(1);
        this->textureSmall->bind(2);
//        this->glTexParameterfv( GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
//        this->glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER );
//        this->glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER );
        this->glDrawElements( GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0 );
        break;
    default:
        break;
    }


}

void MyOpenGLWidget::keyPressEvent(QKeyEvent *event)
{
    switch ( event->key() ) {
    case Qt::Key_Up:
        ratio += 0.1;
        break;
    case Qt::Key_Down:
        ratio -= 0.1;
        break;
    default:
        break;
    }

    if ( ratio > 1 ) ratio = 1;
    if ( ratio < 0 ) ratio = 0;
    shaderProgram.bind();
    shaderProgram.setUniformValue( "ratio", ratio );
    this->update();

}
