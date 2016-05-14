#ifndef BASEREPORT_H
#define BASEREPORT_H

#include <QWidget>
#include "ui_BaseReport.h"

class BaseReport : public QWidget
{
	Q_OBJECT

public:
	BaseReport(QWidget *parent = 0);
	~BaseReport();

private:
	Ui::BaseReport ui;
};

#endif // BASEREPORT_H
