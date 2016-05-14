#pragma execution_character_set("utf-8")
#include "XYReportCenter\XYReportCenter.h"
#include "BaseReport.h"
#include "UsrReport.h"

XYReportCenter::XYReportCenter(QObject *parent)
: QObject(parent)
{
	m_pBaseReport = new BaseReport;
	m_pUsrReport = new UsrReport;
}

QWidget * XYReportCenter::ActiveBaseReport()
{
	return m_pBaseReport;
}

QWidget * XYReportCenter::ActiveUsrReport()
{
	return m_pUsrReport;
}