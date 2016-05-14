#pragma execution_character_set("utf-8")
#include "HDataManager\HDataManager.h"
#include "hmaps.h"

HDataManager::HDataManager(QObject *parent)
:QObject(parent),
m_pMaps(NULL)
{
	m_pClientEngine  = new HClientEngine;
	m_pAddressDetail = new HAddressDetail;
	m_pAlarmEngine   = new HAlarmEngine;
	m_pVehicleReport = new HVehicleReport;
	m_pVelocityLevel = new HVelocityLevel;
}

HDataManager::~HDataManager()
{
	for (auto deviceInfo : m_DeviceInfoList) {
		if (NULL != deviceInfo) { delete deviceInfo;  deviceInfo = NULL; }
	}
	for (auto locationInfo : m_LocationInfoList) {
		if (NULL != locationInfo) { delete locationInfo;  locationInfo = NULL; }
	}

	if (m_pVelocityLevel != NULL)   m_pVelocityLevel->deleteLater();
	if (m_pVehicleReport != NULL)   m_pVehicleReport->deleteLater();
	if (m_pMaps != NULL)			m_pMaps->deleteLater();
	if (m_pAlarmEngine != NULL)		m_pAlarmEngine->deleteLater();
	if (m_pAddressDetail != NULL)   m_pAddressDetail->deleteLater();
	if (m_pClientEngine != NULL)    m_pClientEngine->deleteLater();
}

void HDataManager::startClientEngine()
{
	for (int i = 0; i < 1; i++) {
		connect(m_pClientEngine, SIGNAL(sig_engineStarted()), this, SLOT(onClientEngineStarted()));
		connect(m_pClientEngine, SIGNAL(sig_engineStopped()), this, SLOT(onClientEngineStopped()));
		connect(m_pClientEngine, SIGNAL(sig_respondLogin(quint16)), this, SLOT(onLoginRespond(quint16)));
		connect(m_pClientEngine, SIGNAL(sig_deviceInfo(QString, QString, QString, bool, QDateTime, int, int, qint16)),
			this, SLOT(onDeviceInfo(QString, QString, QString, bool, QDateTime, int, int, qint16)));
		connect(m_pClientEngine, SIGNAL(sig_userInfo(QString)), this, SLOT(onUserInfo(QString)));
		connect(m_pClientEngine, SIGNAL(sig_deviceLocationInfo(QString, HTerminalMsgLocation, HTerminalState)),
			this, SLOT(onDeviceLocationInfo(QString, HTerminalMsgLocation, HTerminalState)));
		connect(m_pClientEngine, SIGNAL(sig_locationLogs(int, int, QList<HTerminalMsgLocation*>*)),
			this, SLOT(onLocationLogs(int, int, QList<HTerminalMsgLocation*>*)));
		connect(m_pClientEngine, SIGNAL(sig_alarmLogs(int, int, QList<HAlarmLogInfo*>*)),
			this, SLOT(onAlarmLogs(int, int, QList<HAlarmLogInfo*>*)));
		connect(m_pClientEngine, SIGNAL(sig_online(QString)), this, SLOT(onOnline(QString)));
		connect(m_pClientEngine, SIGNAL(sig_offline(QString)), this, SLOT(onOffline(QString)));

		m_pClientEngine->startEngine();
		QThread::currentThread()->msleep(50);
	}
}

void HDataManager::startMapEngine()
{
	if (m_pMaps) {
		connect(m_pMaps, SIGNAL(sig_allShapesLoadedFromDB()), this, SLOT(onAllShapesLoadedFromDB()));
		m_pMaps->startMapUdpEngine();
		m_pMaps->connectTo(m_pClientEngine);
	}

	connect(m_pAddressDetail,
		SIGNAL(sig_getAddress(double, double, double, double, QString, QString)),
		this, SLOT(onGetAddress(double, double, double, double, QString, QString)));
	m_pAddressDetail->request(112.123456, 32.123456);
}

void HDataManager::startAlarmEngine()
{
	connect(m_pAlarmEngine, SIGNAL(sig_allRulesloadedFromDB()), this, SLOT(onAllRulesLoadedFromDB()));
	m_pAlarmEngine->startEngine();
	m_pAlarmEngine->connectTo(m_pClientEngine);
	QThread::currentThread()->msleep(50);
}

void HDataManager::destroyEngine()
{
	if (m_pClientEngine)
		m_pClientEngine->stopEngine();
	if (m_pMaps)
		m_pMaps->destroyMapUdpEngine();
	if (m_pAlarmEngine)
		m_pAlarmEngine->stopEngine();
}

void HDataManager::onClientEngineStarted()
{
	//please login
}

void HDataManager::onClientEngineStopped()
{
	//stop engine
}

void HDataManager::onLoginRespond(quint16 respondFlag)
{
	bool isSuccessed = (respondFlag == 0) ? true : false;
	if (isSuccessed) {
		m_pClientEngine->loadShapeFromDB();
		m_pClientEngine->loadRulesFromDB();
	}
	emit sig_loginSuccess(isSuccessed);
}

void HDataManager::onDeviceInfo(QString deviceID, QString phoneNumber, QString vehicleNumber, bool isOnline, QDateTime lastTime, int lat, int lng, qint16 orientation)
{
	XYDeviceHeader::HDeviceInfo *pdeviceInfo = new XYDeviceHeader::HDeviceInfo;
	pdeviceInfo->DeviceNum = deviceID;
	pdeviceInfo->PhoneNumber = phoneNumber;
	pdeviceInfo->VericleNumber = vehicleNumber;
	pdeviceInfo->isOnline = isOnline;
	pdeviceInfo->Alarm = 0;
	pdeviceInfo->ACC = false;
	pdeviceInfo->isLocated = false;
	pdeviceInfo->isNorthLat = false;
	pdeviceInfo->isEastLng = false;
	pdeviceInfo->isRunning = false;
	pdeviceInfo->isOilwayWell = false;
	pdeviceInfo->isElectricityWell = false;
	pdeviceInfo->Lng = QString::number(lng);
	pdeviceInfo->Lat = QString::number(lat);
	pdeviceInfo->Alt = 0;
	pdeviceInfo->Vel = 0;
	pdeviceInfo->Ori = orientation;
	pdeviceInfo->Time = lastTime;
	pdeviceInfo->Address = "";
	if ( !m_DeviceInfoList.contains(pdeviceInfo) ) 
		m_DeviceInfoList.append(pdeviceInfo);
}

void HDataManager::onUserInfo(QString companyName)
{
	if (!m_CompanyList.contains(companyName)) {
		m_CompanyList.append(companyName);
		emit sig_updateCarInfo();
	}
}

void HDataManager::onDeviceLocationInfo(QString deviceID, HTerminalMsgLocation locationInfo, HTerminalState state)
{
	QString    phoneNumber;
	QString    verNumber;
	QString sLng;
	QString sLat;
	QDateTime  lastTime = QDateTime::fromTime_t(locationInfo.time);

	for (auto deviceInfo : m_DeviceInfoList) {
		phoneNumber = deviceInfo->PhoneNumber;
		if (deviceID == deviceInfo->DeviceNum)
			verNumber = deviceInfo->VericleNumber;
	}
	double lng = locationInfo.lng / (double)1000000.0;
	double lat = locationInfo.lat / (double)1000000.0;

	HMapInfo::gpsToGoogle(lng, lat, &lng, &lat);
	HMapInfo::googleToBD(lng, lat, &lng, &lat);

	sLng = QString::number(lng, 'f', 8);
	sLat = QString::number(lat, 'f', 8);

	m_pAddressDetail->request(lng, lat);


	for (auto deviceInfo : m_DeviceInfoList) {
		if (deviceID == deviceInfo->DeviceNum && lastTime.toString() != deviceInfo->Time.toString()) {
			deviceInfo->Lng = sLng;
			deviceInfo->Lat = sLat;
			deviceInfo->Time = lastTime;
			deviceInfo->ACC = state.ACC;
			deviceInfo->isLocated = state.isLocated;
			deviceInfo->isNorthLat = state.isNorthLat;
			deviceInfo->isEastLng = state.isEastLng;
			deviceInfo->isRunning = state.isRunning;
			deviceInfo->isOilwayWell = state.isOilwayWell;
			deviceInfo->isElectricityWell = state.isElectricityWell;
			deviceInfo->Alt = locationInfo.alt;
			deviceInfo->Vel = locationInfo.vel;
			deviceInfo->Ori = locationInfo.ori;
			deviceInfo->Alarm = locationInfo.alarm;
			break;
		}
	}

	XYDeviceHeader::HDeviceInfo *pdeviceInfo = new XYDeviceHeader::HDeviceInfo;
	pdeviceInfo->DeviceNum = deviceID;
	pdeviceInfo->PhoneNumber = phoneNumber;
	pdeviceInfo->VericleNumber = verNumber;
	pdeviceInfo->isOnline = 1;
	pdeviceInfo->Alarm = locationInfo.alarm;
	pdeviceInfo->ACC = state.ACC;
	pdeviceInfo->isLocated = state.isLocated;
	pdeviceInfo->isNorthLat = state.isNorthLat;
	pdeviceInfo->isEastLng = state.isEastLng;
	pdeviceInfo->isRunning = state.isRunning;
	pdeviceInfo->isOilwayWell = state.isOilwayWell;
	pdeviceInfo->isElectricityWell = state.isElectricityWell;
	pdeviceInfo->Lng = sLng;
	pdeviceInfo->Lat = sLat;
	pdeviceInfo->Alt = locationInfo.alt;
	pdeviceInfo->Vel = locationInfo.vel;
	pdeviceInfo->Ori = locationInfo.ori;
	pdeviceInfo->Time = lastTime;
	pdeviceInfo->Address = "";
	if (!m_LocationInfoList.contains(pdeviceInfo)) {
		m_LocationInfoList.append(pdeviceInfo);
		emit sig_updateTrackInfo();
	}
}

void HDataManager::onLocationLogs(int count, int index, QList<HTerminalMsgLocation*>* pList)
{

}

void HDataManager::onAlarmLogs(int count, int index, QList<HAlarmLogInfo*>* pList)
{

}

void HDataManager::onOffline(QString deviceID)
{

}

void HDataManager::onOnline(QString deviceID)
{

}

void HDataManager::onGetAddress(double rawLng, double rawLat, double lng, double lat,
	QString address, QString description)
{

}

void HDataManager::onAllRulesLoadedFromDB()
{

}

void HDataManager::onAllShapesLoadedFromDB()
{
	HLayerList * pList = m_pMaps->getLayerList();
	HLayerList::iterator it1 = pList->begin();
	while (it1 != pList->end()) {
		m_LayoutFirstList.append((*it1)->getName());
		it1++;
	}

	m_LayoutSecondList.clear();
	for (auto name : m_LayoutFirstList) {
		HLayer *pLayer = m_pMaps->getLayerByName(name);
		if (NULL != pLayer) {
			HShapeList::iterator it2 = pLayer->getShapeList()->begin();
			while (it2 != pLayer->getShapeList()->end()) {
				m_LayoutSecondList.append((*it2)->getName());
				it2++;
			}
		}
		m_LayoutMap.insert(name, m_LayoutSecondList);
	}
}