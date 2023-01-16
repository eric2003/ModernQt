#include "widget.h"
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>

Widget::Widget( QWidget * parent )
    : QWidget( parent )
{
    auto * plsBtn = new QPushButton( "+", this );
    auto * minBtn = new QPushButton( "-", this );
    this->lbl = new QLabel( "0", this );
    auto * grid = new QGridLayout( this );
    grid->addWidget( plsBtn, 0, 0, 1, 1 );
    grid->addWidget( minBtn, 0, 1, 1, 1 );
    grid->addWidget( lbl, 1, 1, 1, 1 );
    this->setLayout( grid );

    this->connect( plsBtn, &QPushButton::clicked, this, &Widget::OnPlus );
    this->connect( minBtn, &QPushButton::clicked, this, &Widget::OnMinus );

}

Widget::~Widget()
{
    ;
}

void Widget::OnPlus()
{
    int val = this->lbl->text().toInt();
    this->lbl->setText( QString::number( ++val ) );
}

void Widget::OnMinus()
{
    int val = this->lbl->text().toInt();
    this->lbl->setText( QString::number( --val ) );
}