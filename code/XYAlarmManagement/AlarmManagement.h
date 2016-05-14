#ifndef ALARMMANAGEMENT_H
#define ALARMMANAGEMENT_H

#include <QWidget>
#include "ui_AlarmManagement.h"
#include "BaseAlarmSetting.h"
#include "AreaAlarmSetting.h"
#include "OfflineAlarmSetting.h"
#include "SpeedAlarmSetting.h"
#include "KeypointAlarmSetting.h"
#include "AlarmRuleSetting.h"
#include "AlarmMonitor.h"
#include "AlarmSuper.h"
#include "AlarmStatistics.h"

class AlarmManagement : public QWidget
{
	Q_OBJECT

public:
	AlarmManagement(QWidget *parent = 0);
	~AlarmManagement();

	void showAlarmSetting();
	void showAlarmMonitor();
	void showAlarmSuper();
	void showAlarmStatistics();

public slots:
	void onTreeItemClicked(QTreeWidgetItem * item, int column);
	void onTabCurrentChanged(int index);
	void onTabClosed(int index);

private:
	Ui::AlarmManagement ui;

	QList<QWidget *>      * m_pCurrentTabList;
	BaseAlarmSetting      * m_pBaseAlarmSetting;
	AreaAlarmSetting      * m_pAreaAlarmSetting;
	OfflineAlarmSetting   * m_pOfflineAlarmSetting;
	SpeedAlarmSetting     * m_pSpeedAlarmSetting;
	KeypointAlarmSetting  * m_pKeypointAlarmSetting;
	AlarmRuleSetting      * m_pAlarmRuleSetting;
	AlarmMonitor          * m_pAlarmMonitor;
	AlarmSuper            * m_pAlarmSuper;
	AlarmStatistics       * m_pAlarmStatistics;
};

#endif // ALARMMANAGEMENT_H
