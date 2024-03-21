#ifndef WORK_H
#define WORK_H

#include <QObject>

class Work : public QObject
{
    Q_OBJECT
public:
    explicit Work(QObject *parent = nullptr);

public slots:
    void working();

signals:
    void startWorking();
};

#endif // WORK_H
