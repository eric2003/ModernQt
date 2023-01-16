#include "widget.h"
#include <QUiLoader>
#include <QFile>
#include <QSpinBox>
#include <QLabel>
#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QUiLoader loader;
    QFile file( ":/forms/mytest.ui" );
    file.open( QFile::ReadOnly );
    QWidget * formWidget = loader.load( &file, this );
    //formWidget->show();
    file.close();
    this->dumpObjectTree();
    this->ui_spinBox1 = findChild<QSpinBox *>( "spinBox1" );
    this->ui_spinBox2 = findChild<QSpinBox *>( "spinBox2" );
    this->ui_labelSum = findChild<QLabel *>( "labelSum" );
    qDebug() << "this->ui_spinBox1->objectName() = " << this->ui_spinBox1->objectName();
    qDebug() << "this->ui_spinBox2->objectName() = " << this->ui_spinBox2->objectName();
    qDebug() << "this->ui_labelSum->objectName() = " << this->ui_labelSum->objectName();
    //QMetaObject::connectSlotsByName( this );
    this->connect( this->ui_spinBox1, &QSpinBox::valueChanged, this, &Widget::on_spinBox1_valueChanged );
    this->connect( this->ui_spinBox2, &QSpinBox::valueChanged, this, &Widget::on_spinBox2_valueChanged );
    //QVBoxLayout * layout = new QVBoxLayout();
    //this->setLayout( layout );
    this->setWindowTitle( tr( "Calculator Builder" ) );
}

Widget::~Widget()
{
}

void Widget::on_spinBox1_valueChanged( int value )
{
    this->ui_labelSum->setText( QString::number( value + this->ui_spinBox2->value() ) );
}

void Widget::on_spinBox2_valueChanged( int value )
{
    this->ui_labelSum->setText( QString::number( value + this->ui_spinBox1->value() ) );
}

