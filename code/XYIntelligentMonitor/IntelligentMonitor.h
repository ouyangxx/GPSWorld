#ifndef INTELLIGENTMONITOR_H
#define INTELLIGENTMONITOR_H

#include <QWidget>
#include "ui_IntelligentMonitor.h"
#include "LeftNaviMonitorList.h"
#include "LeftNaviFactory.h"
#include "LeftNaviMap.h"
#include "BottomTableCarMonitor.h"
#include "BottomTableTracking.h"
#include "hmaps.h"

class IntelligentMonitor : public QWidget
{
	Q_OBJECT

public:
	IntelligentMonitor(QWidget *parent = 0);
	~IntelligentMonitor();

	bool writeDataToExcel(const QString &file);//保存数据到Excel

public slots:
	void onUpdateCarBox();
	void onCarcurrentIndexChanged(int index);
	void onClickVechicleShapes(QMap<QString, HVehicleShape *>);

private slots:
	void on_btn_navi1_clicked();
	void on_btn_navi2_clicked();
	void on_btn_navi3_clicked();
	void on_btn_carMonitor_clicked();
	void on_btn_curvey_clicked();
	void on_btn_excel_clicked();

protected:
	bool eventFilter(QObject *obj, QEvent *event);

private:
	Ui::IntelligentMonitor ui;

	LeftNaviMonitorList * m_pLeftNaviMonitorList;
	LeftNaviFactory * m_pLeftNaviFactory;
	LeftNaviMap * m_pLeftNaviMap;
	BottomTableCarMonitor * m_pBottomTableCarMonitor;
	BottomTableTracking   * m_pBottomTableTracking;
};

#endif // INTELLIGENTMONITOR_H
