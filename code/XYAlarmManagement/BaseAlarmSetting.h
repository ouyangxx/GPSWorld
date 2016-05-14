#ifndef BASEALARMSETTING_H
#define BASEALARMSETTING_H

#include <QWidget>
#include "ui_BaseAlarmSetting.h"

class BaseAlarmSetting : public QWidget
{
	Q_OBJECT

public:
	BaseAlarmSetting(QWidget *parent = 0);
	~BaseAlarmSetting();

private:
	Ui::BaseAlarmSetting ui;
};

#endif // BASEALARMSETTING_H
