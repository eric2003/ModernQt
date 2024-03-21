#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>

class MyThread : public QThread
{
    Q_OBJECT
public:
    MyThread();
    void run();
signals:
    void newValue(int num);
};

#endif // MYTHREAD_H
