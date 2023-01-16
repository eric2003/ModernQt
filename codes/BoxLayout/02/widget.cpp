#include "widget.h"
#include <QPushButton>
#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    auto * vbox = new QVBoxLayout( this );
    auto * settings = new QPushButton( "设置", this );
    auto * accounts = new QPushButton( "账户", this );
    auto * loans = new QPushButton( "存款", this );
    auto * cash = new QPushButton( "取款", this );

    settings->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );
    accounts->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );
    loans->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );
    cash->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );

    vbox->addWidget( settings );
    vbox->addWidget( accounts );
    vbox->addWidget( loans );
    vbox->addWidget( cash );

    this->setLayout( vbox );
}

Widget::~Widget()
{
}
