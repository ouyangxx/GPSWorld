#ifndef ALARMSTATISTICS_H
#define ALARMSTATISTICS_H

#include <QWidget>
#include "ui_AlarmStatistics.h"

class AlarmStatistics : public QWidget
{
	Q_OBJECT

public:
	AlarmStatistics(QWidget *parent = 0);
	~AlarmStatistics();

private:
	Ui::AlarmStatistics ui;
};

#endif // ALARMSTATISTICS_H
