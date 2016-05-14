#ifndef BOTTOMTABLETRACKING_H
#define BOTTOMTABLETRACKING_H

#include <QWidget>
#include "ui_BottomTableTracking.h"
#include <QStandardItemModel>

class BottomTableTracking : public QWidget
{
	Q_OBJECT

public:
	BottomTableTracking(QWidget *parent = 0);
	~BottomTableTracking();

	void initStyle();
	void updateCurrentDevice(const QString &currentDeviceId);
	bool writeDataToExcel(const QString &file);//保存数据到Excel

public slots:
	void onUpdateTrackInfo();

private:
	Ui::BottomTableTracking ui;

	QStandardItemModel * m_pTableModel;
	QString m_CurrentDeviceId;
};

#endif // BOTTOMTABLETRACKING_H
