#ifndef HISTRACK_H
#define HISTRACK_H

#include <QWidget>
#include "ui_HisTrack.h"

class HisTrack : public QWidget
{
	Q_OBJECT

public:
	HisTrack(QWidget *parent = 0);
	~HisTrack();

private:
	Ui::HisTrack ui;
};

#endif // HISTRACK_H
