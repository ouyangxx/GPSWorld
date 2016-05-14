#ifndef HALARMENGINE_GLOBAL_H
#define HALARMENGINE_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QString>
#include <Qtcore>

#if defined(HALARMENGINE_LIBRARY)
#  define HALARMENGINESHARED_EXPORT Q_DECL_EXPORT
#else
#  define HALARMENGINESHARED_EXPORT Q_DECL_IMPORT
#endif

enum HRuleType{
    rtInRgnRule = 0x01,
    rtOutRgnRule,
    rtHiVelRule,
    rtLoVelRule,
    rtOfflineRule
};

//typedef struct {
//    bool            isAlarm;
//    QString     rgnName;
////    int             velocityLimit;       //速度上限
//    int             duration;       //持续时间 单位：second
//} HAlarmOpt_InRgn;

//typedef struct {
//    bool            isAlarm;
//    QString     rgnName;
//    int             duration;
//} HAlarmOpt_OutRgn;

//typedef struct {
//    bool            isAlarm;
//    int             velocity;
//    int             duration;
//} HAlarmOpt_Velocity;

//typedef struct {
//    bool            isAlarm;
//    QDateTime  intervalBegin;
//    QDateTime  intervalEnd;
//    int             duration;
//} HAlarmOpt_Offline;

//typedef struct {
//    bool            isAlarm;
//    int             duration;
//} HAlarmOpt_Tired;

//typedef struct HAlarmOption{
////    QString deviceID;
//    HAlarmOpt_InRgn         alarmInRgn;
//    HAlarmOpt_OutRgn       alarmOutRgn;
//    HAlarmOpt_Velocity      alarmVelocity;
//    HAlarmOpt_Offline        alarmOffline;
//    HAlarmOpt_Tired          alarmTired;

//    HAlarmOption & operator= (const HAlarmOption& opt) {
//        alarmInRgn.rgnName = opt.alarmInRgn.rgnName;
//        alarmInRgn.isAlarm = opt.alarmInRgn.isAlarm;
//        alarmInRgn.duration = opt.alarmInRgn.duration;

//        alarmOutRgn.rgnName = opt.alarmOutRgn.rgnName;
//        alarmOutRgn.isAlarm = opt.alarmOutRgn.isAlarm;
//        alarmOutRgn.duration = opt.alarmOutRgn.duration;

//        alarmVelocity.isAlarm = opt.alarmVelocity.isAlarm;
//        alarmVelocity.velocity = opt.alarmVelocity.velocity;
//        alarmVelocity.duration = opt.alarmVelocity.duration;

//        alarmOffline.isAlarm = opt.alarmOffline.isAlarm;
//        alarmOffline.intervalBegin = opt.alarmOffline.intervalBegin;
//        alarmOffline.intervalEnd = opt.alarmOffline.intervalEnd;
//        alarmOffline.duration = opt.alarmOffline.duration;

//        alarmTired.isAlarm = opt.alarmTired.isAlarm;
//        alarmTired.duration = opt.alarmTired.duration;
//        return *this;
//    }
//} HAlarmOption;
//Q_DECLARE_METATYPE(HAlarmOption);


#endif // HALARMENGINE_GLOBAL_H
