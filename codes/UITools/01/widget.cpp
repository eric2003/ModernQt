#include "widget.h"
#include <QUiLoader>
#include <QFile>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QUiLoader loader;
    QFile file( ":/forms/mytest.ui" );
    file.open( QFile::ReadOnly );
    QWidget * formWidget = loader.load( &file, this );
    //formWidget->show();
    file.close();
}

Widget::~Widget()
{
}

