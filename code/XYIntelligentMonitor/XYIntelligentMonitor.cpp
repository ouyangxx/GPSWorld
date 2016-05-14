#pragma execution_character_set("utf-8")
#include "XYIntelligentMonitor\XYIntelligentMonitor.h"
#include "IntelligentMonitor.h"
#include "HisTrack.h"
#include "CurveDiagram.h"
#include "VideoMonitor.h"
#include "GoverRegulation.h"

XYIntelligentMonitor::XYIntelligentMonitor(QObject *parent) :
QObject(parent)
{
	m_pIntelligentMonitor = new IntelligentMonitor;
	m_pHisTrack = new HisTrack;
	m_pCurveDiagram = new CurveDiagram;
	m_pVideoMonitor = new VideoMonitor;
	m_pGoverRegulation = new GoverRegulation;
}

QWidget * XYIntelligentMonitor::ActiveIntelligentMonitor()
{
	return m_pIntelligentMonitor;
}
QWidget * XYIntelligentMonitor::ActiveHisTrack()
{
	return m_pHisTrack;
}
QWidget * XYIntelligentMonitor::ActiveCurveDiagram()
{
	return m_pCurveDiagram;
}
QWidget * XYIntelligentMonitor::ActiveVideoMonitor()
{
	return m_pVideoMonitor;
}
QWidget * XYIntelligentMonitor::ActiveGoverRegulation()
{
	return m_pGoverRegulation;
}