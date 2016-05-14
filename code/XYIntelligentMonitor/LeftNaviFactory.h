#ifndef LEFTNAVIFACTORY_H
#define LEFTNAVIFACTORY_H

#include <QWidget>
#include "ui_LeftNaviFactory.h"

class LeftNaviFactory : public QWidget
{
	Q_OBJECT

public:
	LeftNaviFactory(QWidget *parent = 0);
	~LeftNaviFactory();

private:
	Ui::LeftNaviFactory ui;
};

#endif // LEFTNAVIFACTORY_H
