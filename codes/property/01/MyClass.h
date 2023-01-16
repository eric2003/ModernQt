#pragma once
#include <QObject>

class MyClass : public QObject
{
    Q_OBJECT
    Q_PROPERTY( Priority priority READ priority WRITE setPriority )
    Q_CLASSINFO( "author", "my" )
    Q_CLASSINFO( "Version", "1.0.0" )
public:
    enum Priority { High, Low, veryHigh, VeryLow };
    Q_ENUM( Priority )
    void setPriority( Priority priority ) {
        this->m_priority = priority;
        emit priorityChanged( priority );
    }
    Priority priority() const {
        return this->m_priority;
    }
signals:
    void priorityChanged( MyClass::Priority );
private:
    Priority m_priority;
};
