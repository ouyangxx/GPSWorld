#ifndef BOTTOMTABLECARMONITOR_H
#define BOTTOMTABLECARMONITOR_H

#include <QWidget>
#include "ui_BottomTableCarMonitor.h"
#include <QStandardItemModel>
#include "HDataManager/XYDeviceHeader.h"

class BottomTableCarMonitor : public QWidget
{
	Q_OBJECT

public:
	BottomTableCarMonitor(QWidget *parent = 0);
	~BottomTableCarMonitor();

	void initStyle();
	bool writeDataToExcel(const QString &file);//保存数据到Excel

protected:
	bool eventFilter(QObject *obj, QEvent *event);

public slots:
	void onUpdateDeviceInfo(QList<XYDeviceHeader::HDeviceInfo *> checkedDevices);

private:
	Ui::BottomTableCarMonitor ui;

	QStandardItemModel * m_pTableModel;
};

#endif // BOTTOMTABLECARMONITOR_H
