#pragma execution_character_set("utf-8")
#include "XYEngineerManagement\XYEngineerManagement.h"
#include "EngineerManagement.h"

XYEngineerManagement::XYEngineerManagement(QObject *parent)
: QObject(parent)
{
	m_pEngineerManagement = new EngineerManagement;
}

QWidget * XYEngineerManagement::ActiveEngineerManagement()
{
	return m_pEngineerManagement;
}
