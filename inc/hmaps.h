#ifndef HMAPS_H
#define HMAPS_H

#include <QtCore/qglobal.h>
#include <QObject>
#include <QWidget>
#include <QPaintEvent>
#include <QString>
#include <QList>
#include "hmapsheet.h"
#include "hmapudpmanager.h"
#include "hshape.h"
#include "hvehicleshape.h"
#include "hclientengine.h"

class HMAPSSHARED_EXPORT HMaps : public QWidget
{
    Q_OBJECT

public:
    explicit HMaps(QWidget *parent, const QString& serverName, quint16 serverPort);
    virtual ~HMaps();

    int version() const;
    void moveMap(int offsetX, int offsetY);

    const QString& getServerName() const;
    void setServerName(const QString& serverName);

    int getServerPort() const;
    void setServerPort(int serverPort);

    int startMapUdpEngine();
    void destroyMapUdpEngine();
    bool mapUdpEngineaIsVailable();

    void startShapeCreateMode(HShapeType type);
    void endShapeEditMode();
    HMapSheet * getCurrSheet() const;

    void connectTo(HClientEngine* pClientEngine);

    HVehicleShapeManage* getVehicleShapeManage() const;

    HLayerList* getLayerList() const;
    HLayer* getLayerByName(const QString& name) const;

    void setShapeEditMode(HShape* pShape);
    void setShapeEditMode(const QString& shapeName);

    void setCenterByDeviceID(const QString& deviceID) const;
    int getMapLevel() const;
    void getMapLngLatOfCenter(double *pLng, double *pLat) const;
    void setMapLevelLngLat(int level, double lng, double lat);

    //鍙傛暟鍙互涓虹┖
    void setLocationTrail(QList<HTerminalMsgLocation*>* pList);

    bool isShowVehicle() const;
    void setShowVehicle(bool value);

    bool isShowLocationTrail() const;
    void setShowLocationTrail(bool value);

    bool isShowVirtualVehicle() const;
    void setShowVirtualVehicle(bool value);
    void setVirtualVehicle(HTerminalMsgLocation location);

    void saveShapeToStream(QByteArray& stream);
    void saveShapeToDB();
    void loadShapeFromDB();

    //鍙栧緱vehicleShape鍦ㄥ湴鍥炬帶浠剁殑灞忓箷鍧愭爣
    QPoint getPointOfVehicleShape(const QString& deviceID) const;

private:

Q_SIGNALS:
    void downloadFinished();
    void sig_clickVehicleShapes(HVehicleShapeList list);
    void sig_respondWriteAllShapes(quint16 isSuccessed);
    void sig_allShapesLoadedFromDB();

//    void s();

private slots:
    void onEngineStarted();
    void onEngineDestroyed();
    void onMapChanged(int x, int y, int width, int height);
    void onAutoDrawTimeOut();

public Q_SLOTS:
    void onDeviceInfo(QString deviceID,
                      QString phoneNumber, QString vehicleNumber, bool,
                      QDateTime, int lat, int lng, qint16 orientation);

    void onShapeData(QByteArray stream);
//    void onDeviceLocationInfo(QString deviceID,
//                              HTerminalMsgLocation locationInfo,
//                              HTerminalState state);

protected:
    virtual void paintEvent(QPaintEvent * e);
    virtual void resizeEvent(QResizeEvent *e);
    virtual void mousePressEvent(QMouseEvent *e);
    virtual void mouseMoveEvent(QMouseEvent *e);
    virtual void mouseReleaseEvent(QMouseEvent *e);
    virtual void mouseDoubleClickEvent(QMouseEvent * e);
    virtual void wheelEvent(QWheelEvent *e);

public:
//    Q_INVOKABLE

private:
    int                                     m_version;
    HMapSheet                       * m_pMapSheet;

    QImage                              * m_pFrameBuffer;

    int                                     m_mousePressX;
    int                                     m_mousePressY;
    QString                             m_mapServerName;
    int                                     m_mapServerPort;

    friend class HMapSheet;
    friend class HMapUdpManager;
    HMapUdpManager              * m_pMapUdpManager;
    QString                               m_mapLocalDir;
    QImage                               * m_pDefaultImage;
    HVehicleShapeManage         * m_pVehicleShapeManage;
    QTimer                                       * m_pAutoDrawTimer;
//    QList<HTerminalMsgLocation*>    * m_pLocationLogsList;
    bool                                    m_isShowVehicle;
    bool                                    m_isShowLocationTrail;      //鏄惁鏄剧ず杞ㄨ抗
    bool                                    m_isShowVirtualVehicle;    //鏄惁鏄剧ず铏氭嫙杞?
    HClientEngine                       * m_pClientEngine;
};

#endif // HMAPS_H
