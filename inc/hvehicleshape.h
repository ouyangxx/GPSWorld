#ifndef HVEHICLESHAPE_H
#define HVEHICLESHAPE_H

#include "hbaseshape.h"
#include <QImage>
#include <QMap>
#include "hclientengine_const.h"
#include "hmaps_const.h"
#include <QMouseEvent>

class HMaps;
class HVehicleShapeManage;

class HVehicleImages
{
public:
    explicit HVehicleImages();
    virtual ~HVehicleImages();

    QImage * getRunImg() const;

private:
    QImage                              * m_pRunImg;
};

class HVehicleShape : public HBaseShape
{
public:
    explicit HVehicleShape(HMapSheet * pSheet);
    virtual ~HVehicleShape();

    virtual void paint(QPainter * pPainter);
    virtual void paintShape(QPainter *pPainter);

    //virtual void setTerminalLocation(const HTerminalMsgLocation& location);
    virtual double getLng();
    virtual double getLat();

    virtual void setPhoneNumber(const QString& phoneNumber);
    virtual const QString& getPhoneNumber() const;

    virtual void setVehicleNumber(const QString& vehicleNumber);
    virtual const QString& getVehicleNumber() const;

    static HVehicleShape* getNewVehicleShape(HMapSheet *pSheet);

private:
    friend class HMaps;
    static HVehicleImages           * s_pVehicleImages; //杩欎釜闇€瑕侀潤鎬佸彉閲?
    QString                                 m_phoneNumber;
    QString                                 m_vehicleNumber;
    //杞﹁締鐨勪綅缃俊鎭敱鍙︿竴涓嚎绋嬭繘琛屼慨鏀癸紝鏄剧ず鏃剁敤shapePointList鍦ㄤ富绾跨▼锛屼慨鏀规椂鍦ㄥ彟涓€绾跨▼锛岃淇濇姢ShapePointList
    QMutex                                  * m_pShapePointListMut;
};

#define HVehicleShapeList   QMap<QString, HVehicleShape *>

class HLocationRecvThread : public QThread
{
    Q_OBJECT
public:
    explicit HLocationRecvThread(HVehicleShapeManage* pManager);
    virtual ~HLocationRecvThread();

protected:
    virtual void run();

private slots:
    void onDeviceLocationInfo(QString deviceID,
                              HTerminalMsgLocation locationInfo,
                              HTerminalState state);

private:
    HVehicleShapeManage         * m_pVehicleShapeManage;
};

class HMAPSSHARED_EXPORT HVehicleShapeManage : public QObject
{
    Q_OBJECT
public:
    explicit HVehicleShapeManage(HMaps * pMaps);
    virtual ~HVehicleShapeManage();

    void clearShapeList(QMap<QString, HVehicleShape *> *pShapeList);
    HVehicleShape *addVehicleShape(const QString &deviceID);
    void setLocationInfo(const QString &deviceID,
                         const HTerminalMsgLocation &location);
    HTerminalMsgLocation *getLocationInfo(const QString& deviceID);
    void removeVehicleShape(const QString &deviceID);

    //鍦ㄥ睆骞曚笂鐨刅ehicleShape閮芥斁鍦╩_pVehcileShapeListInScreen鍒楄〃涓?
    void calcVehicleShapesPoint();
    void calcVirtualVehiclePoint();

    void setSize(int width, int height);
    const QImage* getShapesBuffer() const;
    void drawVehicleShapes() const;

    void mousePressEvent(QMouseEvent *e);

    HVehicleShapeList* getAllVehicleShapeList() const;

private:
    friend class HMaps;
    HVehicleShapeList                       * m_pVehicleShapeList;
    HVehicleShapeList                       * m_pVehcileShapeListInScreen;
    QImage                                      * m_pShapesBuffer;
    HMaps                                        * m_pMaps;
    HLocationRecvThread            * m_pLocationRecvThread;
    HVehicleShape                             * m_pVirtualVehicle;
};

#endif // HVEHICLESHAPE_H
