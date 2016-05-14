#ifndef ALARMSUPER_H
#define ALARMSUPER_H

#include <QWidget>
#include "ui_AlarmSuper.h"

class AlarmSuper : public QWidget
{
	Q_OBJECT

public:
	AlarmSuper(QWidget *parent = 0);
	~AlarmSuper();

private:
	Ui::AlarmSuper ui;
};

#endif // ALARMSUPER_H
