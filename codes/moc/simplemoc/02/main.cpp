#include "Sender.h"
#include <QDebug>


int main(int argc, char *argv[])
{
    Sender sender;
    qDebug() << " sender.data = " << sender.data;
    sender.Increase();
    qDebug() << " sender.data = " << sender.data;

    return 0;
}
