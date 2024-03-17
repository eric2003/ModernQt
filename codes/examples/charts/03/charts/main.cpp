#include "mainwindow.h"

#include <QApplication>

#include <QPieSeries>
#include <QChart>
#include <QChartView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 4. Pie Chart Example
    // Define slices and percentage of whole they take up
    QPieSeries *series = new QPieSeries();
    series->append("Vegetables",.40);
    series->append("Beans",.20);
    series->append("Fruits",.15);
    series->append("Seeds/Nuts",.10);
    series->append("Whole Grains",.15);

    // Add label to 1st slice
    QPieSlice *slice0 = series->slices().at(0);
    slice0->setLabelVisible();

    // Add label, explode and define brush for 2nd slice
    QPieSlice *slice1 = series->slices().at(1);
    slice1->setExploded();
    slice1->setLabelVisible();
    slice1->setPen(QPen(Qt::darkGreen, 2));
    slice1->setBrush(Qt::green);

    // Add labels to rest of slices
    QPieSlice *slice2 = series->slices().at(2);
    slice2->setLabelVisible();
    QPieSlice *slice3 = series->slices().at(3);
    slice3->setLabelVisible();
    QPieSlice *slice4 = series->slices().at(4);
    slice4->setLabelVisible();

    // Create the chart widget
    QChart *chart = new QChart();

    // Add data to chart with title and hide legend
    chart->addSeries(series);
    chart->setTitle("What Derek Ate this Week");
    chart->legend()->hide();

    // Used to display the chart
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Create the main app window
    MainWindow  w;
    w.setWindowTitle("QPieSeries");
    w.setCentralWidget(chartView);
    w.resize(420, 300);
    w.show();
    return a.exec();
}
