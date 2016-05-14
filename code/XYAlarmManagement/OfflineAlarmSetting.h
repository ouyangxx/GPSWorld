#ifndef OFFLINEALARMSETTING_H
#define OFFLINEALARMSETTING_H

#include <QWidget>
#include "ui_OfflineAlarmSetting.h"

class OfflineAlarmSetting : public QWidget
{
	Q_OBJECT

public:
	OfflineAlarmSetting(QWidget *parent = 0);
	~OfflineAlarmSetting();

private:
	Ui::OfflineAlarmSetting ui;
};

#endif // OFFLINEALARMSETTING_H
