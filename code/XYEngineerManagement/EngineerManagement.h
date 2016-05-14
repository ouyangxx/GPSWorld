#ifndef ENGINEERMANAGEMENT_H
#define ENGINEERMANAGEMENT_H

#include <QWidget>
#include "ui_EngineerManagement.h"

class EngineerManagement : public QWidget
{
	Q_OBJECT

public:
	EngineerManagement(QWidget *parent = 0);
	~EngineerManagement();

private:
	Ui::EngineerManagement ui;
};

#endif // ENGINEERMANAGEMENT_H
