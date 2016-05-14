#ifndef XYREPORTCENTER_H
#define XYREPORTCENTER_H

#include <QObject>
#include "xyreportcenter_global.h"

class BaseReport;
class UsrReport;

class XYREPORTCENTER_EXPORT XYReportCenter : public QObject
{
	Q_OBJECT

public:
	virtual ~XYReportCenter(){}

	static XYReportCenter& instance()
	{
		static XYReportCenter _Instance;
		return _Instance;
	}

	XYReportCenter(const XYReportCenter &me) = delete;
	XYReportCenter operator = (XYReportCenter me) = delete;

public:
	QWidget * ActiveBaseReport();
	QWidget * ActiveUsrReport();

private:
	explicit XYReportCenter(QObject *parent = 0);

private:
	BaseReport * m_pBaseReport;
	UsrReport  * m_pUsrReport;
};

#endif // XYREPORTCENTER_H
