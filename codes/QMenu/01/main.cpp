﻿#include <QApplication>
#include "MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication a( argc, argv );
    MainWindow w;
    w.resize( 350, 250 );
    w.setWindowTitle( "Menu" );
    w.show();
    return a.exec();
}
