#ifndef GOVERREGULATION_H
#define GOVERREGULATION_H

#include <QWidget>
#include "ui_GoverRegulation.h"

class GoverRegulation : public QWidget
{
	Q_OBJECT

public:
	GoverRegulation(QWidget *parent = 0);
	~GoverRegulation();

private:
	Ui::GoverRegulation ui;
};

#endif // GOVERREGULATION_H
