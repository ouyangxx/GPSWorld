#ifndef XYALARMMANAGEMENT_H
#define XYALARMMANAGEMENT_H

#include <QObject>
#include "xyalarmmanagement_global.h"

class AlarmManagement;

class XYALARMMANAGEMENT_EXPORT XYAlarmManagement : QObject
{
	Q_OBJECT

public:
	virtual ~XYAlarmManagement(){}

	static XYAlarmManagement& instance()
	{
		static XYAlarmManagement _Instance;
		return _Instance;
	}

	XYAlarmManagement(const XYAlarmManagement &me) = delete;
	XYAlarmManagement operator = (XYAlarmManagement me) = delete;

public:
	QWidget * ActiveAlarmManagement();
	QWidget * ActiveAlarmSetting();
	QWidget * ActiveAlarmMonitor();
	QWidget * ActiveAlarmSuper();
	QWidget * ActiveAlarmStatistics();

private:
	explicit XYAlarmManagement(QObject *parent = 0);

private:
	AlarmManagement * m_pAlarmManagement;
};

#endif // XYALARMMANAGEMENT_H
