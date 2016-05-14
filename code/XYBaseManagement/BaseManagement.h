#ifndef BASEMANAGEMENT_H
#define BASEMANAGEMENT_H

#include <QWidget>
#include "ui_BaseManagement.h"

class BaseManagement : public QWidget
{
	Q_OBJECT

public:
	BaseManagement(QWidget *parent = 0);
	~BaseManagement();

private:
	Ui::BaseManagement ui;
};

#endif // BASEMANAGEMENT_H
