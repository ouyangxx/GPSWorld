#ifndef HCLIENTTCPSOCKET_H
#define HCLIENTTCPSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QThread>
#include <QTimer>
#include <QDateTime>
#include "hclientengine_const.h"

class HClientEngine;

class HClientTcpSocketThread : public QThread
{
protected:
    virtual void run();
};

class HClientTcpSocket : public QTcpSocket
{
    Q_OBJECT
public:
    explicit HClientTcpSocket(HClientEngine * pClientEngine);
    //析构函数在clientThread中运行
    virtual ~HClientTcpSocket();

private:
    inline quint16 getCurrOrderID();

    inline bool isDataVaild(const QByteArray& data);
    inline void addCheckCode(QByteArray& data);
    inline void addDouble7E(QByteArray& data);
    inline void removeDouble7E(QByteArray& data);
    inline void decode7E(QByteArray& data);
    inline void encode7E(QByteArray& data);

    inline HTerminalState parseState(quint32 state) const;
    inline void respondLocationLogs(int index);
    inline void respondAlarmLogs(int index);

    //客户申请平台设备最后一次的定位数据
    inline void requestLastLocationInfo(const QString& deviceID);

signals:
    void sig_clientThreadStarted();

public slots:
    void onThreadStarted();
    void onConnTimerTimeOut();
    void onHeardTimerTimeOut();
    void onCheckHeardTimerTimeOut();
    void onReadyRead();
    void onConnected();
    void onDisconnected();
    void onLogin(QString username, QString password);
    void onRequestDeviceInfo();
    void onRequestLocationLogs(QString deviceID,
                               QDateTime startTime, QDateTime endTime);
    void onRequestAlarmLogs(QString deviceID,
                            QDateTime startTime, QDateTime endTime);

    void onSaveShapeToDB(QByteArray stream);
    void onLoadShapeFromDB();
    void onSaveRulesToDB(QByteArray stream);
    void onLoadRulesFromDB();

    void onSaveAlarmLogToDB(HAlarmLogInfo alarmLogInfo);
    void onUpdateAlarmLogToDB(int id, quint16 state1);

private:
    HClientEngine *                             m_pClientEngine;
    HClientTcpSocketThread                  * m_pClientTcpSocketThread;
    QTimer                                          * m_pConnTimer;
    QTimer                                          * m_pHeardTimer;    //心跳包计时器
    QTimer                                          * m_pCheckHeardTimer;
    quint16                                             m_currOrderID;  //平台发的消息的流水号
    QDateTime                                    m_lastConnTime;
    QList<HTerminalMsgLocation*>        * m_pLocationLogsList;
    QList<HAlarmLogInfo*>                   * m_pAlarmLogsList;
    QByteArray                                   m_data;
    QDateTime                                    m_heardBegin;
};

#endif // HCLIENTTCPSOCKET_H
