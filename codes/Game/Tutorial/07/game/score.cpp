#include "score.h"
#include <QFont>

Score::Score() {
    // initialize the score to 0
    this->score = 0;

    //draw the text
    this->setPlainText(QString("Score: ") + QString::number(this->score) ); // Score 0
    this->setDefaultTextColor(Qt::blue);
    this->setFont(QFont("times",16));
}

void Score::increase()
{
    this->score ++;
    //draw the text
    this->setPlainText(QString("Score: ") + QString::number(this->score) );
}

int Score::getScore()
{
    return this->score;
}
