#ifndef AREAALARMSETTING_H
#define AREAALARMSETTING_H

#include <QWidget>
#include "ui_AreaAlarmSetting.h"

class AreaAlarmSetting : public QWidget
{
	Q_OBJECT

public:
	AreaAlarmSetting(QWidget *parent = 0);
	~AreaAlarmSetting();

private:
	Ui::AreaAlarmSetting ui;
};

#endif // AREAALARMSETTING_H
