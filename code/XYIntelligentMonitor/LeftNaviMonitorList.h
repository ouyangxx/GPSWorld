#ifndef LEFTNAVIMONITORLIST_H
#define LEFTNAVIMONITORLIST_H

#include <QWidget>
#include "ui_LeftNaviMonitorList.h"
#include "HDataManager/XYDeviceHeader.h"

class LeftNaviMonitorList : public QWidget
{
	Q_OBJECT

public:
	LeftNaviMonitorList(QWidget *parent = 0);
	~LeftNaviMonitorList();

	void UpdateParentTreeItemState(QTreeWidgetItem * parent);

public slots:
	void onUpdateCarInfo();
	void onTreeItemChanged(QTreeWidgetItem *item, int column);

private:
	Ui::LeftNaviMonitorList ui;

	QList<XYDeviceHeader::HDeviceInfo *> m_CheckedDevices;
};

#endif // LEFTNAVIMONITORLIST_H
