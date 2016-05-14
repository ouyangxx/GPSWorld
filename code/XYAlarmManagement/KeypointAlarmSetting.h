#ifndef KEYPOINTALARMSETTING_H
#define KEYPOINTALARMSETTING_H

#include <QWidget>
#include "ui_KeypointAlarmSetting.h"

class KeypointAlarmSetting : public QWidget
{
	Q_OBJECT

public:
	KeypointAlarmSetting(QWidget *parent = 0);
	~KeypointAlarmSetting();

private:
	Ui::KeypointAlarmSetting ui;
};

#endif // KEYPOINTALARMSETTING_H
