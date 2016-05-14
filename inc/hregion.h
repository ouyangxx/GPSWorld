#ifndef HREGION_H
#define HREGION_H

#include <QObject>

typedef QList<QPointF>  HPointFList;

class HAlarmManager;
class QPolygonF;

//在数据库中的shape数据都是以google坐标格式存储的
class HRegion : public QObject
{
public:
    explicit HRegion(HAlarmManager* pManager);
    virtual ~HRegion();
    virtual bool isInRgn(double lng, double lat) = 0;
    virtual void addPoint(double lng, double lat);

    void setRgnName(const QString& rgnName);
    const QString& rgnName() const;

protected:
    HAlarmManager                        * m_pAlarmManager;
    HPointFList                             * m_pPointFList;
    QString                                 m_rgnName;
};

class HCircleRgn : public HRegion
{
public:
    explicit HCircleRgn(HAlarmManager* pManager);
    virtual bool isInRgn(double lng, double lat);
    virtual void addPoint(double lng, double lat);

private:
    double                  m_radius;
};

class HRectRgn : public HRegion
{
public:
    explicit HRectRgn(HAlarmManager* pManager);
    virtual bool isInRgn(double lng, double lat);
};

class HPolygonRgn : public HRegion
{
public:
    explicit HPolygonRgn(HAlarmManager* pManager);
    virtual ~HPolygonRgn();
    virtual bool isInRgn(double lng, double lat);
    virtual void addPoint(double lng, double lat);

private:
    QPolygonF               * m_pPolygon;
};

#endif // HREGION_H
