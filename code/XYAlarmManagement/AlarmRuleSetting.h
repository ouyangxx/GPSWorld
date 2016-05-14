#ifndef ALARMRULESETTING_H
#define ALARMRULESETTING_H

#include <QWidget>
#include "ui_AlarmRuleSetting.h"

class AlarmRuleSetting : public QWidget
{
	Q_OBJECT

public:
	AlarmRuleSetting(QWidget *parent = 0);
	~AlarmRuleSetting();

private:
	Ui::AlarmRuleSetting ui;
};

#endif // ALARMRULESETTING_H
