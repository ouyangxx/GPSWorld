#ifndef HCLIENTENGINE_CONST_H
#define HCLIENTENGINE_CONST_H

#include <QtCore>

#if defined(HCLIENTENGINE_LIBRARY)
#  define HCLIENTENGINESHARED_EXPORT Q_DECL_EXPORT
#else
#  define HCLIENTENGINESHARED_EXPORT Q_DECL_IMPORT
#endif

typedef struct {
    quint32                 alarm;
    quint32                 state;
    quint32                 lat;        //纬度
    quint32                 lng;        //经度
    quint16                 alt;        //高程
    quint16                 vel;        //速度
    quint16                 ori;        //方向
    uint                      time;
    int                        stayTime;       //单位:second
    int                        runTime;
    qint16                  mileToday;
    qint16                  rollerState;
    qint16                  oilmass;
} HTerminalMsgLocation;  //位置
Q_DECLARE_METATYPE(HTerminalMsgLocation);

typedef struct {
    bool                    ACC;
    bool                    isLocated;
    bool                    isNorthLat;
    bool                    isEastLng;
    bool                    isRunning;
    bool                    isOilwayWell;
    bool                    isElectricityWell;
} HTerminalState;
Q_DECLARE_METATYPE(HTerminalState);

typedef struct HAlarmLogInfo{
    int                      id;
    QString               deviceID;
    quint16               alarmType;
    QDateTime           time;
    QString               inRgn;
    QString               outRgn;
    int                      vel;
    int                      duration;
    quint16              state;
} HAlarmLogInfo;
Q_DECLARE_METATYPE(HAlarmLogInfo);

#endif // HCLIENTENGINE_CONST_H

