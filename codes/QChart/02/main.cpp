#include "mainwindow.h"

#include <QApplication>
#include <QIcon>
#include <QFile>
#include <QDir>
#include <QChartView>
#include <QLineSeries>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QLineSeries *series = new QLineSeries();
    series->append( 0, 6 );
    series->append( 2, 4 );
    series->append( 3, 8 );
    series->append( 7, 4 );
    series->append( 10, 5 );
    *series << QPoint( 11, 1 ) << QPoint( 13, 3 ) << QPoint( 17, 6 )
            << QPoint( 18, 3 ) << QPoint( 20, 2 );
    QChart *chart = new QChart();
    chart->addSeries( series );
    QChartView * chartView = new QChartView( chart );
    w.setCentralWidget( chartView );
    QFile file( "../images/printer.png" );
    qDebug() << "QDir::currentPath() = " << QDir::currentPath();
    if ( !file.open(QIODevice::ReadOnly ))
    {
        qDebug() << "not open";
    }
    else
    {
        qDebug() << "open";
    }
    w.setWindowIcon( QIcon("../images/printer.png") );
    //w.setWindowIcon( QIcon("../images/boat.png") );
    w.setWindowTitle("QChart");
    w.resize( 400, 300 );
    w.show();
    return a.exec();
}
