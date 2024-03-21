#include "renderarea.h"
#include "ui_renderarea.h"

RenderArea::RenderArea(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RenderArea)
{
    ui->setupUi(this);
    this->setBackgroundRole( QPalette::Base );
    this->setAutoFillBackground( true );
}

RenderArea::~RenderArea()
{
    delete ui;
}
