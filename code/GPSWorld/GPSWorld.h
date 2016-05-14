#ifndef GPSWORLD_H
#define GPSWORLD_H

#include <QWidget>
#include "ui_GPSWorld.h"

class GPSWorld : public QWidget
{
	Q_OBJECT

public:
	GPSWorld(QWidget *parent = 0);
	~GPSWorld();

	void initStyle();

protected:
	bool eventFilter(QObject *obj, QEvent *event);

private slots:
	void on_btnMenu_Close_clicked();
	void on_btnMenu_Max_clicked();
	void on_btnMenu_Min_clicked();
	void on_watchButton_clicked();
	void on_warningButton_clicked();
	void on_baseButton_clicked();
	void on_proButton_clicked();
	void on_reportButton_clicked();

	void onAction_HisTrack();
	void onAction_CurveDiagram();
	void onAction_VideoMonitor();
	void onAction_GoverRegulation();
	void onAction_AlarmSetting();
	void onAction_AlarmMonitor();
	void onAction_AlarmSuper();
	void onAction_AlarmStatistics();
	void onAction_BaseReport();
	void onAction_UsrReport();

private:
	Ui::GPSWorld ui;

	QPoint mousePoint;
	bool mousePressed;
	QRect location;
	bool max;
	QMenu *m_pWatchMenu;
	QMenu *m_pWarnMenu;
	QMenu *m_pRepMenu;

	QWidget * m_pCentralWidget;
};

#endif // GPSWORLD_H
