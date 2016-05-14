#ifndef CURVEDIAGRAM_H
#define CURVEDIAGRAM_H

#include <QWidget>
#include "ui_CurveDiagram.h"

class CurveDiagram : public QWidget
{
	Q_OBJECT

public:
	CurveDiagram(QWidget *parent = 0);
	~CurveDiagram();

private:
	Ui::CurveDiagram ui;
};

#endif // CURVEDIAGRAM_H
