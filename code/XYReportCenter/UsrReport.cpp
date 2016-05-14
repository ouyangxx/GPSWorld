#pragma execution_character_set("utf-8")
#include "UsrReport.h"
#include "QtCharts\QLineSeries"
#include "QtCharts\QChart"
#include "QtCharts\QChartView"

using namespace QtCharts;

UsrReport::UsrReport(QWidget *parent)
: QWidget(parent)
{
	ui.setupUi(this);

	//QLineSeries *series = new QLineSeries();

	//series->append(0, 6);
	//series->append(2, 4);
	//series->append(3, 8);
	//series->append(7, 4);
	//series->append(10, 5);
	//*series << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2);

	//QChart *chart = new QChart();
	//chart->legend()->hide();
	//chart->addSeries(series);
	//chart->createDefaultAxes();
	//chart->setTitle("Simple line chart example");

	//QChartView *chartView = new QChartView(chart, this);
	//chartView->setRenderHint(QPainter::Antialiasing);
}

UsrReport::~UsrReport()
{

}
