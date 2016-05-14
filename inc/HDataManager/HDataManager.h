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
//	void displayRuleModel();  //�������������ʾ�ź�
//	void addInruleSuccess();  //�����������ӳɹ�
//	void addOutruleSuccess();  //�����������ӳɹ�
//	void addUpRuleSuccess();   //���ٹ�������޸ĳɹ�
//	void addDownRuleSuccess(); //���ٹ�������޸ĳɹ�
//	void addOffRuleSuccess();  //���߹�������޸ĳɹ�
//	void updateAlarmSuccess(); //�޸ı���״̬�ɹ�
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
	QList<QString>                             m_CompanyList;         //���յĹ�˾����
	QList<XYDeviceHeader::HDeviceInfo *>       m_DeviceInfoList;      //���յ��豸��Ϣ
	QList<XYDeviceHeader::HDeviceInfo *>       m_LocationInfoList;    //���յ�location��Ϣ

	QMap<QString, QList<QString> >        m_LayoutMap;        //��ͼ��
	QList<QString>                        m_LayoutFirstList;  //ͼ��1
	QList<QString>                        m_LayoutSecondList; //ͼ��2

	//QList<XY::HistroyDevice *>            * m_pHistroyDisplayList;  //������ʷԭʼ����
	//QList<HTerminalMsgLocation *>         * m_pDownLoadList;        //����ʷ����Դ
	//QList<HAlarmLogInfo *>                * m_pAlarmList;           //���б�����Ϣ

	//QList<HRgnRuleData>                m_InRuleList;   //�������������
	//QList<HRgnRuleData>                m_OutRuleList;  //���г��������
	//XY::HSpeeedRuleData                m_UpRule;       //���ٹ���
	//XY::HSpeeedRuleData                m_DownRule;     //���ٹ���
	//XY::HOffRuleData                   m_OffRule;      //���߹���


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
