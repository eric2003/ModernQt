#include "health.h"
#include <QFont>

Health::Health() {
    this->health = 3;

    //draw the text
    this->setPlainText(QString("Health: ") + QString::number(this->health) );
    this->setDefaultTextColor(Qt::red);
    this->setFont(QFont("times",16));
}

void Health::decrease()
{
    this->health --;
    //draw the text
    this->setPlainText(QString("Health: ") + QString::number(this->health) );
}

int Health::getHealth()
{
    return this->health;
}
