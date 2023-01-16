#include "widget.h"
#include <QGuiApplication>

int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
