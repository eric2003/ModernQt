#pragma once
#include <QObject>

class Sender : public QObject
{
    Q_OBJECT
public:
    explicit Sender( QObject *parent = nullptr);
public:
    int data = 0;
public:
    void Increase();
signals:
    void DataChanged( int value );
};