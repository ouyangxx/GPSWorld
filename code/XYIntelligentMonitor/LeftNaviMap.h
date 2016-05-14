#ifndef LEFTNAVIMAP_H
#define LEFTNAVIMAP_H

#include <QWidget>
#include "ui_LeftNaviMap.h"

class LeftNaviMap : public QWidget
{
	Q_OBJECT

public:
	LeftNaviMap(QWidget *parent = 0);
	~LeftNaviMap();

private:
	Ui::LeftNaviMap ui;
};

#endif // LEFTNAVIMAP_H
