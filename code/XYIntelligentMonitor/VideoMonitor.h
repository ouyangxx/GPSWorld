#ifndef VIDEOMONITOR_H
#define VIDEOMONITOR_H

#include <QWidget>
#include "ui_VideoMonitor.h"

class VideoMonitor : public QWidget
{
	Q_OBJECT

public:
	VideoMonitor(QWidget *parent = 0);
	~VideoMonitor();

private:
	Ui::VideoMonitor ui;
};

#endif // VIDEOMONITOR_H
