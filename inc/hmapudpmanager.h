#ifndef HMAPUDPMANAGER_H
#define HMAPUDPMANAGER_H

#include <QObject>
#include <QThread>
#include <QUdpSocket>
#include <QMutex>
#include <QWaitCondition>
#include <QQueue>
#include <QMap>
#include <QTimer>
#include <QString>
#include "hmapudpsender.h"
#include "hmapudpreceiver.h"
#include "htransdata.h"
#include "hlogfile.h"
#include "hmapsheet.h"

class HMaps;

class HTileTimer : public QTimer
{
    Q_OBJECT

public:
    HTileTimer(QObject * parent);
    void setTimerInfo(const QString& mapName, int mapLevel,
                      int columnIndex, int rowIndex);

signals:
    void sig_sendFinished(int mapLevel, int columnIndex, int rowIndex);

public slots:
    void resendTask();

public:
    HMapUdpManager      * m_pManager;
    QString m_mapName;
    int         m_mapLevel;
    int         m_tileColumnIndex;
    int         m_tileRowIndex;
    int         m_sendedNumber;
    int         m_maxSendNumber;
};

typedef QMap<HTileOrder, HTileTimer *> HRequestTasks;

class HMapUdpManagerThread: public QThread
{
protected:
    virtual void run();
};

class HMapUdpManager : public QObject
{
    Q_OBJECT
public:
    explicit HMapUdpManager(HMaps *parent,
                            const QString& serverName, quint16 serverPort);
    virtual ~HMapUdpManager();
    //startEngine destroyEngine鍦ㄤ富绾跨▼涓皟鐢?
    void startEngine();
    void destroyEngine();
    bool isEngineStarted() const;
    void addTileTimer(const QString& mapName, int mapLevel,
                      int columnIndex, int rowIndex);
    void removeTileTimer(const QString& mapName, int mapLevel,
                         int columnIndex, int rowIndex);
    void clearTileTimer();
    void mergeTileFile(const QString& mapName, int mapLevel,
                    int columnIndex, int rowIndex, int sectionCount);
    //tmpFileName涓嶅寘鍚悗缂€鍚?
    void deleteTempFile(const QString& tmpFileName, int sectionCount);

private:
    void clearTransDatas();

signals:
    void sig_prepareControl();
    void sig_engineStarted();
    void sig_engineDestroyed();

    void sig_destroyControl();
    void sig_requestTile(const QString mapType, int mapLevel,
            int tileColumnIndex, int tileRowIndex, int sectionIndex);
    void sig_respondTile(QByteArray* pDatagram);
    void sig_tileReadied(const QString mapType, int mapLevel,
            int tileColumnIndex, int tileRowIndex);
    void sig_addTileTimer(const QString mapName, int mapLevel,
            int columnIndex, int rowIndex);

public slots:
    void onPrepareControl();    //鍦ㄧ鐞嗙嚎绋嬩腑鍒涘缓鐩稿叧鎺т欢
    void onManagerStarted();
    void onEngineStarted();
    void onSenderStarted();
    void onReceiverStarted();
    void onDestroyControl();    //鍦ㄧ鐞嗙嚎绋嬩腑閿€姣佺浉鍏虫帶浠?
    void onRequestTile(const QString mapType, int mapLevel,
                       int tileColumnIndex, int tileRowIndex, int sectionIndex);
    void onRespondTile(QByteArray *pDatagram);
    void onSendFinished(int mapLevel, int columnIndex, int rowIndex);
    void onAddTileTimer(const QString mapName, int mapLevel,
                int columnIndex, int rowIndex);

public:
    HMaps                                   * m_pMaps;
    HMapUdpManagerThread        * m_pManagerThread;
    HMapUdpSender                   * m_pSender;
    HMapUdpReceiver                 * m_pReceiver;

    QString                                 m_serverName;
    quint16                                 m_serverPort;
    QUdpSocket                          * m_pMapUdpSocket;
    QQueue<PHTransData>         * m_pTransDatas;
    QMutex                                  * m_pMutex;
    QWaitCondition                      * m_pWaitCond;

    bool                                        m_senderIsStarted;
    bool                                        m_receiverIsStarted;
    bool                                        m_isEngineStarted;
    HLogFile                                m_logFile;
    HRequestTasks                       * m_pRequestTasks;
};

#endif // HMAPUDPMANAGER_H
