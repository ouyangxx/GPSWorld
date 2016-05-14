#ifndef XYINTELLIGENTMONITOR_H
#define XYINTELLIGENTMONITOR_H

#include <QObject>
#include "xyintelligentmonitor_global.h"

class IntelligentMonitor;
class HisTrack;
class CurveDiagram;
class VideoMonitor;
class GoverRegulation;

class XYINTELLIGENTMONITOR_EXPORT XYIntelligentMonitor : public QObject
{
	Q_OBJECT

public:
	virtual ~XYIntelligentMonitor(){}

	static XYIntelligentMonitor& instance()
	{
		static XYIntelligentMonitor _Instance;
		return _Instance;
	}

	XYIntelligentMonitor(const XYIntelligentMonitor &me) = delete;
	XYIntelligentMonitor operator = (XYIntelligentMonitor me) = delete;

public:
	QWidget * ActiveIntelligentMonitor();
	QWidget * ActiveHisTrack();
	QWidget * ActiveCurveDiagram();
	QWidget * ActiveVideoMonitor();
	QWidget * ActiveGoverRegulation();

private:
	explicit XYIntelligentMonitor(QObject *parent = 0);

private:
	IntelligentMonitor * m_pIntelligentMonitor;
	HisTrack           * m_pHisTrack;
	CurveDiagram       * m_pCurveDiagram;
	VideoMonitor       * m_pVideoMonitor;
	GoverRegulation    * m_pGoverRegulation;
};

#endif // XYINTELLIGENTMONITOR_H
