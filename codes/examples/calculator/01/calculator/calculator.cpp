#include "calculator.h"
#include "./ui_calculator.h"
#include <QRegularExpression>

double calcVal = 0.0;
bool divTrigger = false;
bool mulTrigger = false;
bool addTrigger = false;
bool subTrigger = false;

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);
    this->ui->Display->setText(QString::number(calcVal));
    QPushButton *numButtons[10];
    for(int i=0; i <10; ++i){
        QString butName = "Button" + QString::number(i);
        numButtons[i] = Calculator::findChild<QPushButton *>(butName);
        connect( numButtons[i], SIGNAL(released()), this, SLOT(NumPressed()) );
    }
    connect( this->ui->Add, SIGNAL(released()), this, SLOT(MathButtonPressed()) );
    connect( this->ui->Substract, SIGNAL(released()), this, SLOT(MathButtonPressed()) );
    connect( this->ui->Multiply, SIGNAL(released()), this, SLOT(MathButtonPressed()) );
    connect( this->ui->Divide, SIGNAL(released()), this, SLOT(MathButtonPressed()) );

    connect( this->ui->Equals, SIGNAL(released()), this, SLOT(EqualButtonPressed()) );
    connect( this->ui->ChangeSign, SIGNAL(released()), this, SLOT(ChangeNumberSign()) );
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::NumPressed(){
    QPushButton *button = (QPushButton *)sender();
    QString butVal = button->text();
    QString displayVal = this->ui->Display->text();
    if( (displayVal.toDouble()==0) || (displayVal.toDouble()==0.0)){
        this->ui->Display->setText(butVal);
    } else {
        QString newVal = displayVal + butVal;
        double dblNewVal = newVal.toDouble();
        this->ui->Display->setText(QString::number(dblNewVal,'g',16));
    }
}

void Calculator::MathButtonPressed(){
    divTrigger = false;
    mulTrigger = false;
    addTrigger = false;
    subTrigger = false;
    QString displayVal = this->ui->Display->text();
    calcVal = displayVal.toDouble();
    QPushButton *button = ( QPushButton * )sender();
    QString butVal = button->text();
    if( QString::compare(butVal,"/",Qt::CaseInsensitive) == 0 ){
        divTrigger = true;
    }else if( QString::compare(butVal,"*",Qt::CaseInsensitive) == 0 ){
        mulTrigger = true;
    }else if( QString::compare(butVal,"+",Qt::CaseInsensitive) == 0 ){
        addTrigger = true;
    }else{
        subTrigger = true;
    }
    this->ui->Display->setText("");
}

void Calculator::EqualButtonPressed(){
    double solution = 0.0;
    QString displayVal = this->ui->Display->text();
    double dblDisplayVal = displayVal.toDouble();
    if( addTrigger || mulTrigger ||divTrigger || subTrigger ){
        if(addTrigger ){
            solution = calcVal + dblDisplayVal;
        }else if( subTrigger ){
            solution = calcVal - dblDisplayVal;
        }else if( mulTrigger ){
            solution = calcVal * dblDisplayVal;
        }else{
            solution = calcVal / dblDisplayVal;
        }
        this->ui->Display->setText(QString::number(solution));
    }

}

void Calculator::ChangeNumberSign(){
    QString displayVal = this->ui->Display->text();
    static QRegularExpression reg("[-]?[0-9.]*");

    if( reg.match(displayVal).hasMatch() ){
        double dblDisplayVal = displayVal.toDouble();
        double dblDisplayValSign = -1 * dblDisplayVal;
        this->ui->Display->setText(QString::number(dblDisplayValSign));
    }
}
