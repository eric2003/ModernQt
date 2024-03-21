#include "work.h"
#include <QThread>
#include <QDebug>

Work::Work(QObject *parent)
    : QObject{parent}
{}

void Work::working()
{
    qDebug() << "Work Thread ID: " << QThread::currentThreadId();
    qDebug() << "I'm working...";
}
