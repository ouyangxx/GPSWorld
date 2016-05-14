#ifndef PROGRESSBARMANAGER_H
#define PROGRESSBARMANAGER_H

#include <QObject>
#include "progressbarmanager_global.h"

enum ProgressBarType
{
	None,
	LineBar,
	RoundBar
};

class NQLineProgressBar;
class NQRoundProgressBar;

class PROGRESSBARMANAGER_EXPORT ProgressBarManager : public QObject
{
	Q_OBJECT
public:
	virtual ~ProgressBarManager(){}

	static ProgressBarManager& instance()
	{
		static ProgressBarManager _Instance;
		return _Instance;
	}
	ProgressBarManager(const ProgressBarManager &me) = delete;
	ProgressBarManager operator =(ProgressBarManager &me) = delete;

public:
	void startProgressBar(QWidget *parent, int type = None, QString &tipInfo = QString("ÕýÔÚ¼ÓÔØ"));
	void stopProgressBar();

private:
	explicit ProgressBarManager(QObject *parent = 0);

private:
	int m_Type;
	NQLineProgressBar * m_LineBar;
	NQRoundProgressBar * m_RoundBar;
};

#endif // PROGRESSBARMANAGER_H
