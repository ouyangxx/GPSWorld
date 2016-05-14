#ifndef HDATAMANAGER_H
#define HDATAMANAGER_H

#include <QObject>
#include "hdatamanager_global.h"
#include "XYDeviceHeader.h"
#include "hclientengine.h"
#include "haddressdetail.h"
#include "halarmengine.h"
#include "hmaps.h"
#include "hvehiclereport.h"
#include "hvelocitylevel.h"

class HDATAMANAGER_EXPORT HDataManager : public QObject
{
	Q_OBJECT

private:
	explicit HDataManager(QObject *parent = 0);

public:
	virtual ~HDataManager();

	static HDataManager& instance()
	{
		static HDataManager _Instance;
		return _Instance;
	}
	HDataManager(const HDataManager &me) = delete;
	HDataManager operator =(HDataManager &me) = delete;

signals:
	void sig_loginSuccess(bool isSuccess);
	void sig_updateCarInfo();
	void sig_updateTrackInfo();
	void sig_updateDeviceInfo(QList<XYDeviceHeader::HDeviceInfo *> checkedDevices);
//	void updateModel();
//	void displayCheckedTree(int);
//	void displayRuleModel();  //进出区域规则显示信号
//	void addInruleSuccess();  //入区域规则添加成功
//	void addOutruleSuccess();  //出区域规则添加成功
//	void addUpRuleSuccess();   //超速规则添加修改成功
//	void addDownRuleSuccess(); //低速规则添加修改成功
//	void addOffRuleSuccess();  //离线规则添加修改成功
//	void updateAlarmSuccess(); //修改报警状态成功
//
public:
	void startClientEngine();
	void startMapEngine();
	void startAlarmEngine();
	void destroyEngine();

public slots:
	void onClientEngineStarted();
	void onClientEngineStopped();
	void onLoginRespond(quint16 respondFlag);
	void onDeviceInfo(QString deviceID, QString phoneNumber, QString vehicleNumber, bool isOnline, QDateTime lastTime, int lat, int lng, qint16 orientation);
	void onUserInfo(QString companyName);
	void onDeviceLocationInfo(QString deviceID, HTerminalMsgLocation locationInfo, HTerminalState state);
	void onLocationLogs(int count, int index, QList<HTerminalMsgLocation*>* pList);
	void onAlarmLogs(int count, int index, QList<HAlarmLogInfo*>* pList);
	void onOffline(QString deviceID);
	void onOnline(QString deviceID);
	void onGetAddress(double rawLng, double rawLat, double lng, double lat,
		QString address, QString description);
	void onAllRulesLoadedFromDB();
	void onAllShapesLoadedFromDB();

// data
public:
	QList<QString>                             m_CompanyList;         //接收的公司名称
	QList<XYDeviceHeader::HDeviceInfo *>       m_DeviceInfoList;      //接收的设备信息
	QList<XYDeviceHeader::HDeviceInfo *>       m_LocationInfoList;    //接收的location信息

	QMap<QString, QList<QString> >        m_LayoutMap;        //总图层
	QList<QString>                        m_LayoutFirstList;  //图层1
	QList<QString>                        m_LayoutSecondList; //图层2

	//QList<XY::HistroyDevice *>            * m_pHistroyDisplayList;  //下载历史原始数据
	//QList<HTerminalMsgLocation *>         * m_pDownLoadList;        //总历史数据源
	//QList<HAlarmLogInfo *>                * m_pAlarmList;           //所有报警信息

	//QList<HRgnRuleData>                m_InRuleList;   //所有入区域规则
	//QList<HRgnRuleData>                m_OutRuleList;  //所有出区域规则
	//XY::HSpeeedRuleData                m_UpRule;       //超速规则
	//XY::HSpeeedRuleData                m_DownRule;     //低速规则
	//XY::HOffRuleData                   m_OffRule;      //离线规则


// engine
public:
	HClientEngine               * m_pClientEngine;
	HAddressDetail              * m_pAddressDetail;
	HAlarmEngine                * m_pAlarmEngine;
	HMaps						* m_pMaps;
	HVehicleReport              * m_pVehicleReport;
	HVelocityLevel              * m_pVelocityLevel;
};

#endif // HDATAMANAGER_H
