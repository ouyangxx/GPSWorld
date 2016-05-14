#ifndef ALARMMONITOR_H
#define ALARMMONITOR_H

#include <QWidget>
#include "ui_AlarmMonitor.h"

class AlarmMonitor : public QWidget
{
	Q_OBJECT

public:
	AlarmMonitor(QWidget *parent = 0);
	~AlarmMonitor();

private:
	Ui::AlarmMonitor ui;
};

#endif // ALARMMONITOR_H
