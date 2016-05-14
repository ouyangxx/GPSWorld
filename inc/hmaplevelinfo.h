#ifndef HMAPLEVELINFO_H
#define HMAPLEVELINFO_H

#include <QObject>

class HMapLevelInfo
{
public:
    HMapLevelInfo();

    quint32 getInitTileColumnIndex() const;
    void setInitTileColumnIndex(quint32 index);

    quint32 getInitTileRowIndex() const;
    void setInitTileRowIndex(quint32 index);

    double getInitOriginLongitude() const;
    void setInitOriginLongitude(double value);

    double getInitOriginLatitude() const;
    void setInitOriginLatitude(double value);

    double getScale() const;
    void setScale(double value);

private:
    quint32         m_initTileColumnIndex;
    quint32         m_initTileRowIndex;
    double          m_initOriginLongitude;
    double          m_initOriginLatitude;
    double          m_scale;
};

#endif // HMAPLEVELINFO_H
