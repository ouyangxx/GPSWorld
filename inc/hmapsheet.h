#ifndef HMAPSHEET_H
#define HMAPSHEET_H

#include <QObject>
#include "htileinfo.h"
#include <QList>
#include <QPainter>
#include <QString>
#include <QMouseEvent>
#include <QMap>
#include <QTimer>
#include "hmaptypeinfo_google.h"
#include "hshape.h"

#define     HList_TileInfos      QList<QList<HTileInfo *> *>
#define     HMap_TileInfos     QMap<HTileOrder, HTileInfo *>

class HMapSheet;

class HAutoMoveMapTimer : public QTimer
{
    Q_OBJECT

public:
    HAutoMoveMapTimer(QObject *parent);
    void setMapEdge(int value);

public slots:
    void autoMoveMap();

private:
    HMapSheet                       * m_pSheet;
    int                                     m_mapEdge;      //寰€鍝釜鏂瑰悜绉诲姩鍦板浘
};

struct HTileOrder{
//public:
    int mapLevel;
    int columnIndex;
    int rowIndex;

    HTileOrder(int _mapLevel, int _columnIndex, int _rowIndex) {
        mapLevel = _mapLevel;
        columnIndex = _columnIndex;
        rowIndex = _rowIndex;
    }

    bool operator < (const HTileOrder& tileOrder) const {
        if (mapLevel < tileOrder.mapLevel)
            return true;
        else if (mapLevel == tileOrder.mapLevel) {
            if (columnIndex < tileOrder.columnIndex)
                return true;
            else if (columnIndex == tileOrder.columnIndex) {
                if (rowIndex < tileOrder.rowIndex)
                    return true;
            }
        }

        return false;
    }
};

typedef struct HTileOrder HTileOrder;

class HMaps;

enum HMapOperationType {
    otNone = 0,
    otMove,
    otGrafixCreate,
    otGrafixEdit
};

class HMapSheet : public QObject
{
    Q_OBJECT
public:
    explicit HMapSheet(HMaps *parent = 0);
    virtual ~HMapSheet();

    HMaps * getMaps() const;
    HMapTypeInfo * getMapTypeInfo() const;
    bool setMapLevelIndex(int index);
    int getMapLevelIndex() const;

//    void setTileColumnCount(const quint32 count);
//    quint32 getColumnCount() const;

//    void setTileRowCount(const quint32 count);
//    quint32 getTileRowCount() const;

//    void setTileColumnIndex(const quint32 index);

    int getTileColumnBeginIndex() const;
    int getTileRowBeginIndex() const;
    void getTileColumnIndexByPoint(
            int x, int * pTileIndexX, int * pOffsetX) const;
    void getTileRowIndexByPoint(
            int y, int * pTileIndexY, int * pOffsetY) const;

//    void setMapOffSetX(const int offsetX);
    int getMapOffSetX() const;

//    void setMapOffSetY(const int offsetY);
    int getMapOffSetY() const;

    void clearTileInfosList();
    void resetTileInfosList();
    void clearTileInfosMap();

    //杩斿洖鍊艰〃绀烘槸鍚︽湁鏀瑰彉
    bool setTileListSize(int screenWidth, int screenHeight);

    //鍏朵腑涓€涓弬鏁颁负0锛屼笉瀵瑰叾杩涜璁剧疆
    void setSize(int oldWidth, int oldHeight, int width, int height);
    void fillMapList(bool isDrawTile);
    HTileInfo * fillOneTileInfo(int mapLevel, int columnIndex, int rowIndex);
//    bool resetMapListBySize();  //璐熻矗璋冩暣鍙冲悗鏁版嵁
    int getTileRectShowOffsetX() const;
    int getTileRectShowOffsetY() const;

    //鏍规嵁鍋忕Щ璋冩暣tileColumnIndex銆乼ileRowIndex鍜宮_mapOffsetX銆乵_mapOffsetY鐨勫€硷紝
    //杩斿洖鍊艰〃绀簍ileColumnIndex鍜宼ileRowIndex鏄惁鏈夋敼鍙?
    bool adjustTileIndex(int offsetX, int offsetY);
    void moveMap(int offsetX, int offsetY);
    const QImage * getMapBuffer() const;
    const QImage * getLayerBuffer() const;

    //鍙栧緱鍘熺偣鐨勭粡绾害
    void getOriginLongLatitude(double * pLng, double * pLat) const;
    //鍙栧緱灞忓箷鐐圭殑缁忕含搴?
    void getLongLatitudeByPoint(int x, int y, double * pLng, double * pLat) const;
    //閫氳繃缁忕含搴︽壘鍒板睆骞曚笂鐨勭偣
    void getPointByLongLatitude(double lng, double lat, int * pX, int * pY) const;

    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void mouseDoubleClickEvent(QMouseEvent * e);
    void wheelEvent(QWheelEvent *e);

    //x y鏄斁澶т箣鍓嶇殑鐐癸紝screenX screenY鏄斁澶т箣鍚庣殑鐐?
    bool zoomIn(int screenX, int screenY, int x, int y);
    bool zoomOut(int screenX, int screenY, int x, int y);

    //閫氳繃灞忓箷涓績鐐瑰潗鏍囩粡绾害鍙栧緱宸︿笂瑙掔偣鐨則ileIndex鍜宱ffset
    //鍙傛暟offset鏄痶ile涓婄殑鍋忕Щ
    void getOriginTileIndexAndOffset(int screenX, int screenY,
                double centerLng, double centerLat,
                int * pOriginTileIndexX, int * pOriginTileIndexY,
                int * pOriginTileOffsetX, int * pOriginTileOffSetY);

    //灏嗘寚瀹氱粡绾害璁剧疆鎴愬睆骞曚腑蹇冪偣
    void setScreenCenterByLngLat(double lng, double lat);

    //閫氳繃tileIndex鍜宱ffse鍙栧緱灞忓箷涓婄殑鐐?
    //鍙傛暟offset鏄痶ile涓婄殑鍋忕Щ
    void getPointByTileIndexAndOffset(int tileColumnIndex, int tileRowIndex,
                int tileOffsetX, int tileOffsetY, int *pX, int *pY);

    void startShapeCreateMode(HShapeType type);
    void startShapeEditMode(int layerIndex, int shapeIndex);
    void endShapeCreateMode();
    void endShapeEditMode();

    int getTileColumnIndex() const;
    int getTileRowIndex() const;
    int getTileColumnCount() const;
    int getTileRowCount() const;

    HMapOperationType getOperationType() const;
    HGrafixManager * getGrafixManager() const;

private:
    friend class HMaps;
    bool isTileInScreen(int columnIndex, int rowIndex) const;
    //鍦板浘buffer涓婄殑鐐硅浆鎹㈠埌灞忓箷涓?
    void pointToScreen(int x, int y, int * pScreenX, int * pScreenY) const;
    //鍦板浘鍖哄煙鍜屽睆骞曞尯鍩熶氦鍙夋椂闇€瑕侀噸缁?
    bool isNeedDraw() const;
    void drawMap() const;

    //pX pY琛ㄧず褰撳墠缁樺埗鐨則ile鍦╰ile缂撳瓨涓殑x,y
    void drawTile(int mapLevel, int columnIndex, int rowIndex, HTileInfo* pTileInfo,
                int *pX, int *pY) const;
    void clearMap();

    void removeTileInfosByRow(QList<HTileInfo *>* pList);

    void insertTileInfoByFirstColumn(int count);
    void removeTileInfoByFirstColumn(int count);
    void appendTileInfoByLastColumn(int count);
    void removeTileInfoByLastColumn(int count);

    void insertTileInfoByFirstRow(int count);
    void removeTileInfoByFirstRow(int count);
    void appendTileInfoByLastRow(int count);
    void removeTileInfoByLastRow(int count);

    HTileInfo* getTileInfoFromHash(int mapLevel, int columnIndex,
                                         int rowIndex);
    HTileInfo* getTileInfoFromFile(int mapLevel, int columnIndex,
                                          int rowIndex);

    void setOperationType(HMapOperationType type);

signals:
    void sig_drawTile(int mapLevel, int columnIndex, int rowIndex, HTileInfo* pTileInfo);
    //濡傛灉width==-1 || height == -1琛ㄧず鍒锋柊鍏ㄩ儴鍖哄煙
    void sig_mapChanged(int x, int y, int width, int height);

public slots:
    //void onRepaintMap();
    void onTileReadied(const QString mapType, int mapLevel,
                       int tileColumnIndex, int tileRowIndex);
    void onDrawTile(int mapLevel, int columnIndex, int rowIndex, HTileInfo* pTileInfo);

private:
    HMaps               *m_pMaps;
    int                     m_mapLevelIndex;
    int                     m_tileColumnCount;
    int                     m_tileRowCount;
    int                     m_tileColumnIndex;     //灞忓箷宸︿笂瑙抰ile鐨刬ndex
    int                     m_tileRowIndex;
    int                     m_tileListColumnIndex;
    int                     m_tileListRowIndex;
    int                     m_mapOffsetX;           //灞忓箷宸︿笂瑙抰ile鐨勫亸绉伙紝杩欐槸涓礋鍊?
    int                     m_mapOffsetY;
//    long                    m_mapTotalOffsetX;
//    long                    m_mapTotalOffsetY;
    HList_TileInfos              m_list_TileInfos;
    double              m_initOriginLongitude;          //鍘熺偣缁忓害鍊?
    double              m_initOriginLatitude;           //鍘熺偣绾害鍊?
    double              m_originLongitude;
    double              m_originLatitude;
    int                     m_screenWidth;
    int                     m_screenHeight;
    HMapTypeInfo   * m_pMapTypeInfo;

    //QString                m_localMapDir;
    QImage              * m_pMapBuffer;
    HMapOperationType   m_operationType;
    HMap_TileInfos           m_map_TileInfos;
    HGrafixManager          * m_pGrafixManager;
    HAutoMoveMapTimer       m_autoMoveMapTimer;

    int                             m_oldMouseX;
    int                             m_oldMouseY;
};

#endif // HMAPSHEET_H
