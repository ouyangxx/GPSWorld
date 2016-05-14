#ifndef HMAPTYPEINFO_GOOGLE_H
#define HMAPTYPEINFO_GOOGLE_H

#include <QObject>
#include "hmaptypeinfo.h"

#define GoogleMap_StartLevelIndex 4//9
#define GoogleMap_InitColumnIndex 11//106368
#define GoogleMap_InitRowIndex 5//53208


class HMapTypeInfo_google : public HMapTypeInfo
{

public:
    HMapTypeInfo_google(QObject * parent = 0);

    virtual const QString getMapName() const;
    virtual HMapType getMapType() const;
    virtual inline int  getTileWidth() const;
    virtual inline int  getTileHeight() const;
    virtual int getMapLevelCount() const;

    //閫氳繃tileIndex鍙栧緱鍥剧墖宸︿笂瑙掔粡绾害
    virtual void getLongLatitudeByTileIndex(int tileIndexX, int tileIndexY,
            double *pLng, double *pLat, int zoom) const;
    //缁忓害杞寲涓栫晫鍥惧儚绱?
    virtual inline double lngToPoint_x(double lng, int zoom) const;
    //涓栫晫鍥惧儚绱犺浆鍖栫粡搴?
    virtual inline double pointTolng_x(long x, int zoom) const;
    virtual inline double latToPoint_y(double lat, int zoom) const;
    virtual inline double pointToLat_y(long y, int zoom) const;
    //閫氳繃缁忕含搴﹀彇寰梩ileIndex鍜屽湪鍗曚釜鐡︾墖涓殑鍋忕Щ pX琛ㄧず鍋忕Щ锛屾槸姝ｆ暟
    virtual inline void getPointOffsetByLongLatitude(double lng, double lat,
            int *pTileIndexX, int *pTileIndexY, int *poffSetX, int *poffsetY, int zoom) const;
    virtual inline void getLongLatitudeByPointOffset(int tileIndexX, int tileIndexY,
            int x, int y, double *pLng, double *pLat, int zoom) const;

    //姹備袱鐐圭殑瑙掑害
    virtual double getAngleByTwoPoint(long x1, long y1,
            long x2, long y2) const;
    //閫氳繃璺濈璁＄畻缁忕含搴?
    virtual double getLongitudeByDistance(double distance,
            double lng1, double lat1, double angle) const;
    virtual double getLatitudeByDistance(double distance, double lat1, double angle) const;

    //灏唃ps(WGS-84)鍧愭爣杞崲鎴恎oogle鍧愭爣(GCJ-02)
    virtual void transformLngLat(double gpsLng, double gpsLat,
            double *pLng, double *pLat) const;
    virtual void transfromLngLatToGPS(double lng, double lat,
                                      double *pLng, double *pLat) const;

    virtual bool isOverlapTilePoint(int tileIndexX1, int offsetX1,
                                          int tileIndexY1, int offsetY1,
                                          int tileIndexX2, int offsetX2,
                                          int tileIndexY2, int offsetY2);
};

#endif // HMAPTYPEINFO_GOOGLE_H
