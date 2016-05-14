#ifndef XYENGINEERMANAGEMENT_H
#define XYENGINEERMANAGEMENT_H

#include <QObject>
#include "xyengineermanagement_global.h"

class EngineerManagement;

class XYENGINEERMANAGEMENT_EXPORT XYEngineerManagement : public QObject
{
	Q_OBJECT

public:
	virtual ~XYEngineerManagement(){}

	static XYEngineerManagement& instance()
	{
		static XYEngineerManagement _Instance;
		return _Instance;
	}

	XYEngineerManagement(const XYEngineerManagement &me) = delete;
	XYEngineerManagement operator = (XYEngineerManagement me) = delete;

public:
	QWidget * ActiveEngineerManagement();

private:
	explicit XYEngineerManagement(QObject *parent = 0);

private:
	EngineerManagement * m_pEngineerManagement;
};

#endif // XYENGINEERMANAGEMENT_H
