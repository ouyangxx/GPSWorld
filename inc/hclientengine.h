#ifndef HCLIENTENGINE_H
#define HCLIENTENGINE_H

#include <QtCore/qglobal.h>
#include "hclientengine_const.h"

// 0x0001   平台对客户的通用答复
// 0x0002   发送心跳包
// 0x0003   接收心跳包
// 0x0010   发送登陆 (QString)username帐号 (QString)password密码
// 0x0020   接收登陆反馈信号 quint 0表示成功 1表示失败
// 0x0029   客户端向平台申请设备信息
// 0x0030   平台向客户端发送设备位置信息
// 0x0040   平台向客户端发送此帐号管理所有设备的基本信息
// 0x0050   平台向客户端发送帐号的信息

// 0x0060   客户向平台申请定位历史数据
// 0x0061   客户向平台申请最后一次的定位数据
// 0x0070   平台向客户发送定位历史数据
// 0x0080   客户回复平台所发送数据收到

// 0x0090   客户发送shape的stream到平台保存到数据库
// 0x0100   平台回复客户端保存shape到数据库是否成功
// 0x0110   客户端申请平台所有图形数据
// 0x0120   平台向客户发送所有图形数据

// 0x0130   客户发送报警规则到平台保存到数据库
// 0x0140   平台回复客户保存报警规则到数据库是否成功
// 0x0150   客户申请平台报警规则
// 0x0160   平台向客户发送报警规则

// 0x0170   客户向平台发送报警日志
// 0x0180   平台回复客户保存报警日志到数据库是否成功

// 0x0190   客户申请平台报警日志
// 0x0200   平台向客户发送报警日志
// 0x0210   客户回复平台所发送报警数据是否收到

// 0x0220   客户申请平台修改报警数据状态
// 0x0230   平台回复客户修改报警数据是否成功

class HClientTcpSocket;

class HCLIENTENGINESHARED_EXPORT HClientEngine : public QObject
{
    Q_OBJECT
public:
    explicit HClientEngine();
    virtual ~HClientEngine();

    void startEngine();
    void stopEngine();
    bool isStarted();

    void login(const QString& username, const QString& password);
    void requestDeviceInfo();
    void requestLocationLogs(const QString& deviceID,
                             QDateTime startTime, QDateTime endTime);
    void requestAlarmLogs(const QString& deviceID,
                         QDateTime startTime, QDateTime endTime);

    void saveShapeToDB(const QByteArray& stream);
    void loadShapeFromDB();

    void saveRulesToDB(const QByteArray& stream);
    void loadRulesFromDB();

    void saveAlarmLogToDB(const HAlarmLogInfo& alarmLogInfo);
    //state值，0是默认，1是已处理，2是误报
    void updateAlarmLogToDB(int id, quint16 state);

    const QString& getUsername() const;
    const QString& getPassword() const;

signals:
    void sig_engineStarted();
    void sig_engineStopped();

    void sig_socketConnected();
    void sig_socketDisconnected();

    void sig_respondLogin(quint16 isSuccessed);
    void sig_online(QString deviceID);
    void sig_offline(QString deviceID);
    void sig_deviceLocationInfo(
            QString deviceID, HTerminalMsgLocation locationInfo,
            HTerminalState state);
    void sig_deviceInfo(QString deviceID, QString phoneNumber,
                        QString vehicleNumber, bool isOnline, QDateTime lastTime,
                        int lat, int lng, qint16 orientation);
    void sig_userInfo(QString companyName/*, QByteArray regions,
                      QByteArray rules*/);

    void sig_savingAllShape(QByteArray stream);
    void sig_respondWriteAllShape(quint16 isSuccessed); //收到回复，写图形到图数据库是否成功
    void sig_shapeData(QByteArray stream);  //读取所有图形

    void sig_respondWriteAllRules(quint16 isSuccessed);
    void sig_rulesData(QByteArray stream);   //读取所有规则

    void sig_respondWriteAlarmLog(quint16 isSuccessed);
    //void sig_alarmLogsData(int count, int index, QList<HAlarmLogInfo*>* pList);

    void sig_respondUpdateAlarmLog(quint16 isSuccessed);

    //index+1 == count时，pList才有效
    void sig_locationLogs(int count, int index,
                          QList<HTerminalMsgLocation*>* pList);
    void sig_alarmLogs(int count, int index,
                       QList<HAlarmLogInfo*>* pList);

    void sig_in_login(QString username, QString password);
    void sig_in_requestDeviceInfo();
    void sig_in_requestLocationLogs(QString deviceID,
                                    QDateTime startTime, QDateTime endTime);
    void sig_in_requestAlarmLogs(QString deviceID,
                                 QDateTime startTime, QDateTime endTime);
    void sig_in_saveShapeToDB(QByteArray stream);
    void sig_in_loadShapeFromDB();
    void sig_in_saveRulesToDB(QByteArray stream);
    void sig_in_loadRulesFromDB();

    void sig_in_saveAlarmLogToDB(HAlarmLogInfo alarmLogInfo);
    void sig_in_updateAlarmLogToDB(int id, quint16 state);

private slots:
    void onClientThreadStarted();
    void onRespondLogin(quint16);

    void onSocketDisconnected();

    void onLocationLogs(int count, int index,
                        QList<HTerminalMsgLocation*>* );

    void onRespondWriteAlarmLog(quint16);
    void onAlarmLogs(int count, int index,
                        QList<HAlarmLogInfo*>* );

    void onRespondUpdateAlarmLog(quint16);

    void onRespondWriteAllShape(quint16 /*isSuccessed*/);
    void onShapeData(QByteArray /*stream*/);

    void onRespondWriteAllRules(quint16 /*isSuccessed*/);
    void onRulesData(QByteArray /*stream*/);

private:
    friend class HClientTcpSocket;
    bool                                            m_engineStarted;
    HClientTcpSocket                         * m_pClientTcpSocket;
    QString                                         m_username;
    QString                                         m_password;
    bool                                            m_isRequestedLogs;
    bool                                            m_isRequestedAlarmLogs;

    bool                                            m_isSavingShape;
    bool                                            m_isLoadingShape;

    bool                                            m_isSavingRules;
    bool                                            m_isLoadingRules;

    bool                                            m_isSavingAlarmLog;
    bool                                            m_isLoadingAlarmLog;

    bool                                            m_isUpdatingAlarmLog;

    bool                                            m_isLogined;
};

#endif // HCLIENTENGINE_H
