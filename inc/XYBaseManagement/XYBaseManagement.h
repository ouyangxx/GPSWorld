#ifndef XYBASEMANAGEMENT_H
#define XYBASEMANAGEMENT_H

#include <QObject>
#include "xybasemanagement_global.h"

class BaseManagement;

class XYBASEMANAGEMENT_EXPORT XYBaseManagement : public QObject
{
	Q_OBJECT

public:
	virtual ~XYBaseManagement(){}

	static XYBaseManagement& instance()
	{
		static XYBaseManagement _Instance;
		return _Instance;
	}

	XYBaseManagement(const XYBaseManagement &me) = delete;
	XYBaseManagement operator = (XYBaseManagement me) = delete;

public:
	QWidget * ActiveBaseManagement();

private:
	explicit XYBaseManagement(QObject *parent = 0);

private:
	BaseManagement * m_pBaseManagement;
};

#endif // XYBASEMANAGEMENT_H
