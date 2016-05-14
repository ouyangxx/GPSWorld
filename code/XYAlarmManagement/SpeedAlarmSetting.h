#ifndef SPEEDALARMSETTING_H
#define SPEEDALARMSETTING_H

#include <QWidget>
#include "ui_SpeedAlarmSetting.h"

class SpeedAlarmSetting : public QWidget
{
	Q_OBJECT

public:
	SpeedAlarmSetting(QWidget *parent = 0);
	~SpeedAlarmSetting();

private:
	Ui::SpeedAlarmSetting ui;
};

#endif // SPEEDALARMSETTING_H
