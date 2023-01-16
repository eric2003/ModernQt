#include <QCoreApplication>

class MyObj : public QObject
{
public:
    MyObj(QObject *parent=nullptr);
    ~MyObj(){ qDebug() << this << " is destroyed!"; };
};

MyObj::MyObj(QObject *parent) : QObject(parent)
{
    qDebug() << this << " is constructed!";
}

int main(int argc, char *argv[])
{
    MyObj objA;
    objA.setObjectName( "A" );
    MyObj * objB = new MyObj( & objA );
    objB->setObjectName( "B" );
    MyObj * objC = new MyObj( objB );
    objC->setObjectName( "C" );
    objA.dumpObjectTree();

    return 0;
}
