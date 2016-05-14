#ifndef HALARMENGINE_H
#define HALARMENGINE_H

#include "halarmengine_global.h"
#include <QObject>
#include "hclientengine.h"

class HAlarmEngineThread;
class HAlarmManager;

Q_DECLARE_METATYPE(QList<QString>);

typedef struct HRgnRuleData {
    bool                            isActive;
    QString                       ruleName;
    QList<QString>           rgnList;
    QList<QString>          vehicleList;
    int                             duration;
} HRgnRuleData;

class HALARMENGINESHARED_EXPORT HAlarmEngine : public QObject
{
    Q_OBJECT
public:
    explicit HAlarmEngine(QObject * parent = 0);
    virtual ~HAlarmEngine();

    void startEngine();
    void stopEngine();
    int version() const;  //每次升级后，version加1

    void connectTo(HClientEngine* pClientEngine);
    void saveRulesToDB();
    void loadRulesFromDB();

    bool containsInRgnRule(const QString& ruleName) const;
    void addInRgnRule(QString ruleName, bool isActive, QList<QString> rgnList,
                      QList<QString> vehicleList, int duration);
    void removeInRgnRule(QString ruleName);
    QList<HRgnRuleData> getInRgnRuleList() const;

    bool containsOutRgnRule(const QString& ruleName) const;
    void addOutRgnRule(QString ruleName, bool isActive, QList<QString> rgnList,
                       QList<QString> vehicleList, int duration);
    void removeOutRgnRule(QString ruleName);
    QList<HRgnRuleData> getOutRgnRuleList() const;

    void setHiVelRule(bool isActive, int velocityLimit, int duration);
    void getHiVelRule(bool& isActive, int& velocityLimit, int& duration) const;

    void setLoVelRule(bool isActive, int velocityLimit, int duration);
    void getLoVelRule(bool &isActive, int& velocityLimit, int& duration) const;

    void setOfflineRule(bool isActive, int duration);
    void getOfflineRule(bool& isActive, int& duration);

    void addSupervisoryVehicle(const QString& deviceID);
    void removeSupervisoryVehicle(const QString& deviceID);

//    static void initializeAlarmOption(HAlarmOption* p);

signals:
    void sig_engineStarted();
    void sig_engineStopped();
    void sig_in_getRulesStream();
    void sig_rulesStream(QByteArray stream);
//    void sig_rule(QString deviceID, HAlarmOption opt);
    void sig_respondWriteAllRules(quint16 isSuccessed); //0成功
    void sig_allRulesloadedFromDB();

    void sig_offline(QString deviceID);
    void sig_online(QString deviceID);

    //设置报警信号
    void sig_inRgnAlarm(QString deviceID, QString rgnName);
    void sig_outRgnAlarm(QString deviceID, QString rgnName);
    void sig_hiVelLimitAlarm(QString deviceID, int velocity);
    void sig_loVelLimitAlarm(QString deviceID, int velocity);
    void sig_offlineAlarm(QString deviceID);

private slots:
    void onThreadStarted();
    void onRulesStream(QByteArray stream);

private:
    friend class HInRgnRule;
    friend class HOutRgnRule;
    friend class HHiVelRule;
    friend class HLoVelRule;
    friend class HOfflineRule;
    bool                                m_isEngineStarted;
    HAlarmEngineThread          * m_pAlarmEngineThread;
    HAlarmManager               * m_pAlarmManager;
    HClientEngine                   * m_pClientEngine;
};

#endif // HALARMENGINE_H
