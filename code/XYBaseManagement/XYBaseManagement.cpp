#pragma execution_character_set("utf-8")
#include "XYBaseManagement\XYBaseManagement.h"
#include "BaseManagement.h"

XYBaseManagement::XYBaseManagement(QObject *parent) :
QObject(parent)
{
	m_pBaseManagement = new BaseManagement;
}

QWidget * XYBaseManagement::ActiveBaseManagement()
{
	return m_pBaseManagement;
}