#include <QApplication>
#include <QMetaClassInfo>
#include "MyClass.h"

int main(int argc, char *argv[])
{
    //QApplication a(argc, argv);
    QSharedPointer<MyClass> myClass = QSharedPointer<MyClass>(new MyClass());
    QObject * obj = myClass.get();
    myClass->setPriority( MyClass::VeryLow );
    obj->setProperty( "priority", MyClass::veryHigh );
    obj->setProperty( "isGood", false );

    qInfo() << myClass->priority();
    qInfo() << myClass->property( "isGood" );
    qInfo() << myClass->metaObject()->classInfo( 0 ).name();
    qInfo() << myClass->metaObject()->classInfo( 0 ).value();
    qInfo() << myClass->metaObject()->classInfo( 1 ).name();
    qInfo() << myClass->metaObject()->classInfo( 1 ).value();
    //return a.exec();
}

