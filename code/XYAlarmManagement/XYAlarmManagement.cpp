#pragma execution_character_set("utf-8")
#include "XYAlarmManagement\XYAlarmManagement.h"
#include "AlarmManagement.h"

XYAlarmManagement::XYAlarmManagement(QObject *parent) :
QObject(parent)
{
	m_pAlarmManagement = new AlarmManagement;
}

QWidget * XYAlarmManagement::ActiveAlarmManagement()
{
	return m_pAlarmManagement;
}

QWidget * XYAlarmManagement::ActiveAlarmSetting()
{
	m_pAlarmManagement->showAlarmSetting();
	return m_pAlarmManagement;
}

QWidget * XYAlarmManagement::ActiveAlarmMonitor()
{
	m_pAlarmManagement->showAlarmMonitor();
	return m_pAlarmManagement;
}

QWidget * XYAlarmManagement::ActiveAlarmSuper()
{
	m_pAlarmManagement->showAlarmSuper();
	return m_pAlarmManagement;
}

QWidget * XYAlarmManagement::ActiveAlarmStatistics()
{
	m_pAlarmManagement->showAlarmStatistics();
	return m_pAlarmManagement;
}