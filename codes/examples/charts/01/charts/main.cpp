#include "mainwindow.h"

#include <QApplication>
#include <QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLineSeries  *series = new QLineSeries();

    series->append(0, 23);
    series->append(1, 22);
    series->append(2, 30);
    series->append(3, 45);
    series->append(4, 56);
    series->append(5, 67);
    series->append(6, 23);
    QPen pen(Qt::blue);
    pen.setWidth(3);
    series->setPen(pen);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->createDefaultAxes();
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    MainWindow  w;
    w.setWindowTitle("QLineSeries");
    w.setCentralWidget(chartView);
    w.resize(400, 300);
    w.show();

    //MainWindow w;
    //w.show();
    return a.exec();
}
