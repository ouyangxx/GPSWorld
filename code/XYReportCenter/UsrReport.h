#ifndef USRREPORT_H
#define USRREPORT_H

#include <QWidget>
#include "ui_UsrReport.h"

class UsrReport : public QWidget
{
	Q_OBJECT

public:
	UsrReport(QWidget *parent = 0);
	~UsrReport();

private:
	Ui::UsrReport ui;
};

#endif // USRREPORT_H
