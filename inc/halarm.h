#ifndef HALARM_H
#define HALARM_H

#include <QObject>
#include <QMap>
#include <QTimer>
#include "halarmengine_global.h"
#include "hclientengine_const.h"

class HAlarm;
class HAlarmEngine;
class HAlarmManager;
class HRegion;
class HOfflineRule;

//typedef QMap<QString, HAlarm*>  HAlarmList;
typedef QList<HRegion*> HRgnList;

typedef struct HAlarmInfo {
    QString              rgnName;
    QDateTime         lastTime;    //上次定位数据的时间
    int                     affirmDuration;  //已符合规则持续的时间
    HAlarmInfo(QString _rgnName, QDateTime _lastTime, int _duration){
        rgnName = _rgnName;
        lastTime = _lastTime;
        affirmDuration = _duration;
    }
}HAlarmInfo ;

class HBaseRule : public QObject
{
public:
    HBaseRule(HAlarmManager* pManager);

    void setDuration(int duration);
    int duration() const;

    void setActive(bool isActive);
    bool isActive() const;

    void setRuleName(const QString ruleName);
    const QString& ruleName() const;

    virtual void saveToStream(QByteArray& stream);

protected:
    virtual HRuleType ruleType() const = 0;

protected:
    friend class HOfflineTimer;
    HAlarmManager                       * m_pAlarmManager;
    int                                             m_duration;                         //超时时间
    bool                                           m_isActive;
    QString                                      m_ruleName;
};

class HAlarmRule : public HBaseRule
{
    Q_OBJECT

public:
    HAlarmRule(HAlarmManager* pManager);
    virtual ~HAlarmRule();

signals:
    void sig_checkRule(const QString& deviceID,
                       const HTerminalMsgLocation& location);

protected slots:
    virtual void onCheckRule(const QString& deviceID,
                             const HTerminalMsgLocation& location);

//    void addPrepareAlarmVehicle(const QString& deviceID, int currInterval);
//    void deletePrepareAlarmVehicle(const QString& deviceID);

protected:
    friend class HOfflineTimer;

    QMap<QString, HAlarmInfo>    * m_pPrepareAlarmList;          //预准报警的车辆列表, int表示持续的时间
    double                          m_lng;
    double                          m_lat;
};

class HRgnRule : public HAlarmRule
{
public:
    HRgnRule(HAlarmManager* pManager);
    virtual ~HRgnRule();

    void addRgnName(const QString& rgnName);
    void removeRgnName(const QString& rgnName);

    void addVehicle(const QString& vehicleName);
    void removeVehicle(const QString& vehicleName);
    virtual void saveToStream(QByteArray& stream);

protected:
    friend class HAlarmManager;
    friend class HAlarmEngine;
    QMap<QString, void*>              * m_pRgnList;
    QMap<QString, void*>              * m_pVehicleList;
};

class HInRgnRule : public HRgnRule
{
public:
    HInRgnRule(HAlarmManager* pManager);

protected:
    virtual HRuleType ruleType() const;
    virtual void onCheckRule(const QString &deviceID,
                             const HTerminalMsgLocation& location);
};

class HOutRgnRule : public HRgnRule
{
public:
    HOutRgnRule(HAlarmManager* pManager);

protected:
    virtual HRuleType ruleType() const;
    virtual void onCheckRule(const QString& deviceID,
                             const HTerminalMsgLocation& location);
};

class HVelocityRule: public HAlarmRule
{
public:
    explicit HVelocityRule(HAlarmManager* pManager);
    void setVehicleLimit(int vehicleLimit);
    int vehicleLimit() const;
    virtual void saveToStream(QByteArray& stream);

protected:
    int                         m_vehicleLimit;
};

class HHiVelRule : public HVelocityRule
{
public:
    explicit HHiVelRule(HAlarmManager* pManager);

protected:
    virtual HRuleType ruleType() const;
    virtual void onCheckRule(const QString& deviceID,
                             const HTerminalMsgLocation& location);
};

class HLoVelRule : public HVelocityRule
{
public:
    explicit HLoVelRule(HAlarmManager* pManager);

protected:
    virtual HRuleType ruleType() const;
    virtual void onCheckRule(const QString& deviceID,
                             const HTerminalMsgLocation& location);
};

class HOfflineTimer : public QTimer
{
    Q_OBJECT
public:
    explicit HOfflineTimer(const QString &deviceID, HOfflineRule* pOfflineRule);

private slots:
    void onTimeout();

private:
    QString                             m_deviceID;
    HOfflineRule                    * m_pOfflineRule;
};

class HOfflineRule : public HBaseRule
{
    Q_OBJECT
public:
    explicit HOfflineRule(HAlarmManager* pManager);
    virtual ~HOfflineRule();

    virtual void saveToStream(QByteArray& stream);

protected slots:
    void onOffline(const QString& deviceID);
    void onInline(const QString& deviceID);

protected:
    virtual HRuleType ruleType() const;
    void clearOfflineVehicleList();

protected:
    QMap<QString, QTimer*>              * m_pOfflineVehicleList;
};

//class HAlarm : public QObject
//{
//    Q_OBJECT
//public:
//    explicit HAlarm(HAlarmManager * pAlarmManager);
//    virtual ~HAlarm();

//    void setDeviceID(const QString& deviceID);
//    const QString& getDeviceID() const;

//    void setAlarmOption(const HAlarmOption& opt);
//    const HAlarmOption& getAlarmOption() const;

//    void saveRulesToStream(QByteArray& stream);

//    void setRuleName(const QString& ruleName);
//    const QString& getRuleName() const;

//signals:
//    void sig_deviceLocationInfo(
//            QString deviceID, HTerminalMsgLocation locationInfo,
//            HTerminalState state);

//private slots:
//    void onDeviceLocationInfo(
//            QString deviceID, HTerminalMsgLocation locationInfo,
//            HTerminalState state);

//private:
//    HAlarmOption                      m_alarmOption;
////    QMutex                              * m_pAlarmOptMut;
//    HAlarmManager                   * m_pAlarmManager;
//    HTerminalMsgLocation           m_lastLocation;
//    QString                               m_deviceID;
//    QString                               m_ruleName;

//    //报警过后此变量设为false，出区域后该变量设为true
//    bool                                    m_isPrepareInRgnAlarm;
//    int                                      m_inRgnDuration;  //当前进区域后持续的时间，单位：秒

//    bool                                    m_isPrepareOutRgnAlarm;
//    int                                     m_outRgnDuration;

//    int                                     m_outOfVelDuration;  //当前超速持续时间 单位：秒

//    //报警后置为false,上线后再置为true
//    bool                                    m_isPrepareOfflineAlarm;

//    //报警后置为0，再重新记时。当前疲劳驾驶持续时间，单位：秒
//    int                                     m_tiredDuration;
//};

class HAlarmManager : public QObject
{
    Q_OBJECT
public:
    explicit HAlarmManager(HAlarmEngine * pEngine);
    virtual ~HAlarmManager();

    void clearRgnList();
    void clearInRgnRuleList();
    void clearOutRgnRuleList();


signals:
    void sig_in_addInRgnRule(QString ruleName, bool isActive, QList<QString> rgnList,
                             QList<QString> vehicleList, int duration);
    void sig_in_removeInRgnRule(QString ruleName);

    void sig_in_addOutRgnRule(QString ruleName, bool isActive, QList<QString> rgnList,
                             QList<QString> vehicleList, int duration);
    void sig_in_removeOutRgnRule(QString ruleName);

    void sig_in_setHiVelRule(bool isActive, int velocity, int duration);
    void sig_in_setLoVelRule(bool isActive, int velocity, int duration);

    void sig_in_setOfflineRule(bool isActive, int duration);

    void sig_in_addSupervisoryVehicle(QString deviceID);
    void sig_in_removeSupervisoryVehicle(QString deviceID);

private slots:
    void onDeviceLocationInfo(
            QString deviceID, HTerminalMsgLocation locationInfo,
            HTerminalState state);

    void onGetRulesStream();
    void onRulesData(QByteArray stream);

    //每次重新取得数据，都要检查区域报警中的区域是否还存在，如果不存在，修改此规则，
    //如果此规则只有这一个区域对象，直接删除此规则，并保存数据库
    void onShapesData(QByteArray stream);

    void onAddInRgnRule(QString ruleName, bool isActive, QList<QString> rgnList,
                             QList<QString> vehicleList, int duration);
    void onRemoveInRgnRule(QString ruleName);

    void onAddOutRgnRule(QString ruleName, bool isActive, QList<QString> rgnList,
                             QList<QString> vehicleList, int duration);
    void onRemoveOutRgnRule(QString ruleName);

    void onSetHiVelRule(bool isActive, int velocity, int duration);
    void onSetLoVelRule(bool isActive, int velocity, int duration);

    void onSetOfflineRule(bool isActive, int duration);

    void onAddSupervisoryVehicle(QString deviceID);
    void onRemoveSupervisoryVehicle(QString deviceID);
private:
    friend class HInRgnRule;
    friend class HOutRgnRule;
    friend class HHiVelRule;
    friend class HLoVelRule;
    friend class HOfflineRule;
    friend class HOfflineTimer;
    friend class HAlarmEngine;

    HAlarmEngine                        * m_pAlarmEngine;
    //HAlarmList                              * m_pAlarmList;
    HRgnList                                * m_pRgnList;

    QMap<QString, HInRgnRule *>             * m_pInRgnRuleList;
    QMap<QString, HOutRgnRule *>           * m_pOutRgnRuleList;
    HHiVelRule                                          * m_pHiVelRule;
    HLoVelRule                                          * m_pLoVelRule;
    HOfflineRule                                        * m_pOfflineRule;
    QMap<QString, void*>                        * m_pSupervisoryVehicleList;
};

#endif // HALARM_H
