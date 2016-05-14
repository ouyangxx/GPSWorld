#ifndef XYDEVICEHEADER_H
#define XYDEVICEHEADER_H

#include <QString>
#include <QDateTime>

namespace XYDeviceHeader
{
	enum XYDeviceHeaderUserRole
	{
		DeviceId = Qt::UserRole + 1,
		VericleNumber,
	};

	typedef struct HUDSpeedRuleData {      //超速规则
		bool                 isActive;
		int                  velocityLimit;
		int                  duration;
	} HSpeeedRuleData;

	typedef struct HOffLineRuleData {      //离线规则
		bool                 isActive;
		int                  duration;
	} HOffRuleData;

	typedef struct HDeviceInfo {          //设备信息
		QString                 DeviceNum;
		QString                 PhoneNumber;
		QString                 VericleNumber;
		bool                    isOnline;
		quint32                 Alarm;
		bool                    ACC;
		bool                    isLocated;
		bool                    isNorthLat;
		bool                    isEastLng;
		bool                    isRunning;
		bool                    isOilwayWell;
		bool                    isElectricityWell;
		QString                 Lng;
		QString                 Lat;
		quint16                 Alt;
		quint16                 Vel;
		quint16                 Ori;
		QDateTime               Time;
		QString                 Address;
	}HDeviceInfo;

	typedef struct DeviceParkEvent {
		QDateTime  m_startTime;
		QDateTime  m_endTime;
		QString    m_duringTime;
		bool       m_dischargeStatus;
		QString    m_address;
	}DeviceParkEvent;

	typedef struct HistroyDevice {
		QString                 DeviceNum;
		QString                 PhoneNumber;
		QString                 VericleNumber;
		quint32                 Alarm;
		quint32                 State;
		QString                 Lng;
		QString                 Lat;
		quint16                 Alt;
		quint16                 Vel;
		quint16                 Ori;
		QDateTime               Time;
		QString                 Address;
	}HistroyDevice;
}



#endif