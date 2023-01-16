#include "widget.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    auto * vbox = new QVBoxLayout( this );
    auto * hbox = new QHBoxLayout( this );
    auto * okBtn = new QPushButton( "OK", this );
    auto * applyBtn = new QPushButton( "Apply", this );

    hbox->addWidget( okBtn, 1, Qt::AlignRight );
    hbox->addWidget( applyBtn, 1, Qt::AlignRight );
    vbox->addStretch( 1 );
    vbox->addLayout( hbox );

    this->setLayout( vbox );
}

Widget::~Widget()
{
}
