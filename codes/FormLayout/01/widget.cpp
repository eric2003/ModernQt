#include "widget.h"
#include <QLineEdit>
#include <QFormLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    auto * nameEdit = new QLineEdit( this );
    auto * addrEdit = new QLineEdit( this );
    auto * occpEdit = new QLineEdit( this );
    auto * formLayout = new QFormLayout( this );

    formLayout->setLabelAlignment( Qt::AlignRight | Qt::AlignVCenter );
    formLayout->addRow( "Name:", nameEdit );
    formLayout->addRow( "Email:", addrEdit );
    formLayout->addRow( "Age:", occpEdit );

    this->setLayout( formLayout );


}

Widget::~Widget()
{
}
