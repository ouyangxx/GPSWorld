#ifndef HMAPTYPEINFO_H
#define HMAPTYPEINFO_H

#include <QObject>
#include <QString>
#include <QList>
#include "hmaplevelinfo.h"
#include "hmaps_const.h"

#define Screen_DPI  96

//ee: 妞悆鐨勫亸蹇冪巼銆俥llipse eccentricity
#define earthEE  0.00669342162296594323

enum HMapType{
    mtGoogle = 0x01,
    mtBaidu
};

class HMAPSSHARED_EXPORT HMapInfo : public QObject
{
public:
    explicit HMapInfo(QObject * parent = 0);
    static double getDistance(double lng1, double lat1, double lng2, double lat2);
    static void gpsToGoogle(double gpsLng, double gpsLat, double *pLng, double *pLat);
    static void googleToBD(double glLng, double glLat, double *pLng, double *pLat);

    static void googleToGps(double lng, double lat, double *pLng, double *pLat);
    static void BDToGoogle(double lng, double lat, double *pLng, double *pLat);
};

class HMapTypeInfo : public HMapInfo
{
public:
    explicit HMapTypeInfo(QObject * parent = 0);
    virtual ~HMapTypeInfo();

    virtual const QString getMapName() const = 0;
    virtual HMapType getMapType() const = 0;
    virtual int  getTileWidth() const = 0;
    virtual int  getTileHeight() const = 0;
    virtual int getMapLevelCount() const = 0;

    //閫氳繃tileIndex鍙栧緱鍥剧墖宸︿笂瑙掔粡绾害
    virtual void getLongLatitudeByTileIndex(int tileIndexX, int tileIndexY,
            double *pLng, double *pLat, int zoom) const = 0;
    //缁忓害杞寲涓栫晫鍥惧儚绱?
    virtual double lngToPoint_x(double lng, int zoom) const = 0;
    //涓栫晫鍥惧儚绱犺浆鍖栫粡搴?
    virtual double pointTolng_x(long x, int zoom) const = 0;
    virtual double latToPoint_y(double lat, int zoom) const = 0;
    virtual double pointToLat_y(long y, int zoom) const = 0;
    //缁忕含搴﹀彇寰梩ileIndex鍜屽湪鍗曚釜鐡︾墖涓殑鍋忕Щ
    virtual void getPointOffsetByLongLatitude(double lng, double lat,
            int *pTileIndexX, int *pTileIndexY, int *pX, int *pY, int zoom) const = 0;
    virtual void getLongLatitudeByPointOffset(int tileIndexX, int tileIndexY,
            int x, int y, double *pLng, double *pLat, int zoom) const = 0;

    //姹備袱鐐圭殑璺濈
    virtual double getAngleByTwoPoint(long x1, long y1,
            long x2, long y2) const = 0;
    //閫氳繃璺濈璁＄畻缁忕含搴?
    virtual double getLongitudeByDistance(double distance,
            double lng1, double lat1, double angle) const = 0;
    virtual double getLatitudeByDistance(double distance,
             double lat1, double angle) const = 0;
    virtual bool isOverlapTilePoint(int tileIndexX1, int offsetX1,
                                   int tileIndexY1, int offsetY1,
                                   int tileIndexX2, int offsetX2,
                                   int tileIndexY2, int offsetY2) = 0;

    //杩欐槸涓熀绫诲嚱鏁帮紝灏唃ps鍧愭爣杞崲鍒扮浉搴旂殑鍧愭爣浣撶郴锛屽瓙绫诲啀鏍规嵁鍏蜂綋瀹為檯鍧愭爣绯昏繘琛岃浆鎹?
    virtual void transformLngLat(double gpsLng, double gpsLat,
            double *pLng, double *pLat) const = 0;
    //灏嗗綋鍓嶅潗鏍囦綋绯昏浆鎹㈠埌GPS鍧愭爣绯?
    virtual void transfromLngLatToGPS(double lng, double lat,
                                      double *pLng, double *pLat) const = 0;

protected:
    //QList<HMapLevelInfo *>      * m_pList_MapLevelInfos;
    //int     m_currLevelIndex;
};

#endif // HMAPTYPEINFO_H
