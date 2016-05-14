#ifndef HSHAPE_H
#define HSHAPE_H

#include <QObject>
#include <QPainter>
#include <QString>
#include <QList>
#include <QPoint>
#include <QMouseEvent>
#include <QPen>
#include <QBrush>
#include <QFont>
#include "hbaseshape.h"
#include "hmaps_const.h"

class HShape;
class HLayer;
class HMapSheet;
class HGrafixManager;
class HLocationTrail;

typedef QList<HShape *>       HShapeList;
typedef QList<HLayer *>     HLayerList;

class HGrafixStyle
{
public:
    explicit HGrafixStyle();
    virtual ~HGrafixStyle();

    QPen * getLinePen() const;
    QPen * getTrailPen() const;
    QPen * getPointPen() const;
    QPen * getFramePen() const;
    QBrush * getFrameBrush() const;
    QBrush * getPointBrush() const;

    QFont * getFont() const;
    QBrush * getFillBrush() const;

public:
    QPen                        * m_pLinePen;
    QPen                        * m_pTrailPen;
    QPen                        * m_pPointPen;

    QPen                        * m_pFramePen;
    QBrush                      * m_pFrameBrush;
    QBrush                      * m_pPointBrush;

    QFont                       * m_pFont;
    QPen                        * m_pFontPen;

    QBrush                      * m_pFillBrush;
};

class HMAPSSHARED_EXPORT HLayer : public QObject
{
public:
    explicit HLayer(QObject *parent = 0);
    virtual ~HLayer();

    void clearShapeList();
    void addShape(HShape *pShape);
    void removeShape(HShape*pShape);

    const QString& getName() const;
    bool setName(const QString& name);
    HShapeList * getShapeList() const;
    void drawShapes(QPainter *painter) const;
    void calcShapesPoint();
    bool containsShape(const QString& shapeName);

private:
    friend class HGrafixManager;
    HShapeList                              * m_pShapeList;
    QString                                     m_name;
};

enum HShapeType {
    shapeType_unknown = 0x00,
    shapeType_Point,
    shapeType_Polyline,
    shapeType_DistanceLine,
    shapeType_Rectangle,
    shapeType_Circle,
    shapeType_Polygon,
    shapeType_LocationTrail
};

enum HShapeState {
    shapeState_Create,
    shapeState_Edit,
    shapeState_Show
};

class HMAPSSHARED_EXPORT HShape : public HBaseShape
{
    Q_OBJECT
public:
    explicit HShape(HGrafixManager * pGrafixManager,
                    HMapSheet * pSheet);
    virtual ~HShape();

    virtual void paint(QPainter * pPainter);

    void setMousePoint(const QPoint &value);

    virtual bool setName(const QString name);
    //const QPointF& getMousePoint() const;

    //鍙傛暟x,y鏄睆骞曚笂鐨勭偣锛岃繑鍥炲€艰〃绀烘寜涓嬫帶鍒剁偣鐨勬寚閽?
    virtual HShapePoint *isClickControlPoint(int x, int y) const;
    virtual void saveToStream(QByteArray& stream);

protected:
    HGrafixManager                      * m_pGrafixManager;
    QPoint                                  m_mousePoint; //褰撳墠榧犳爣鐨勭偣锛屽璞″垱寤烘椂鐢?
    HShapeType                          m_shapeType;
};

class HPoint : public HShape
{
public:
    explicit HPoint(HGrafixManager *pGrafixManager, HMapSheet *pSheet);
    virtual void paintShape(QPainter * pPainter);
    virtual void addPoint(HShapePoint *value);

    static HPoint* getNewShape(HGrafixManager *pGrafixManager);
};

class HCircle : public HShape
{
public:
    explicit HCircle(HGrafixManager *pGrafixManager, HMapSheet *pSheet);
    virtual void paintShape(QPainter * pPainter);
    virtual void addPoint(HShapePoint *value);

    static HCircle* getNewShape(HGrafixManager *pGrafixManager);

    virtual void onChangePoint(HShapePoint* p, double lng, double lat,
                               int tileColumnIndex, int tileRowIndex, int tileOffsetX, int tileOffsetY);

private:
    int                 m_r;        //鍗婂緞
};

class HRectangle : public HShape
{
public:
    explicit HRectangle(HGrafixManager *pGrafixManager, HMapSheet *pSheet);
    virtual void paintShape(QPainter * pPainter);
    virtual void addPoint(HShapePoint *value);

    static HRectangle* getNewShape(HGrafixManager *pGrafixManager);
};

class HPolyline: public HShape
{
//    Q_OBJECT
public:
    explicit HPolyline(HGrafixManager *pGrafixManager, HMapSheet *pSheet);
    virtual void paintShape(QPainter * pPainter);

    static HPolyline* getNewShape(HGrafixManager *pGrafixManager);
};

//杞ㄨ抗绾?
class HLocationTrail : public HPolyline
{
//    Q_OBJECT
public:
    explicit HLocationTrail(HGrafixManager *pGrafixManager, HMapSheet *pSheet);
    virtual void paintShape(QPainter * pPainter);
    virtual bool isInScreen();
    virtual void saveToStream(QByteArray& /*stream*/);

    static HLocationTrail* getNewShape(HGrafixManager *pGrafixManager);
};

class HPolygon : public HShape
{
public:
    explicit HPolygon(HGrafixManager *pGrafixManager, HMapSheet *pSheet);
    virtual void paintShape(QPainter * pPainter);

    static HPolygon* getNewShape(HGrafixManager *pGrafixManager);
};

class HDistanceLine : public HPolyline
{

public:
    explicit HDistanceLine(HGrafixManager *pGrafixManager, HMapSheet *pSheet);
    virtual void paintShape(QPainter * pPainter);
    virtual void addPoint(HShapePoint *value);
    void reCalcDistance();
    static HDistanceLine* getNewShape(HGrafixManager* pGrafixManager);

private:
    double                      m_distance;
};

class HGrafixManager : public QObject
{
    Q_OBJECT

public:
    explicit HGrafixManager(QObject *parent = 0);
    virtual ~HGrafixManager();

    virtual bool mousePressEvent(QMouseEvent *e);
    virtual void mouseMoveEvent(QMouseEvent *e);
    virtual void mouseReleaseEvent(QMouseEvent *);
    virtual void mouseDoubleClickEvent(QMouseEvent * e);

    void clearLayerList();
    void addLayer();
    void removeLayer(int index);

    void drawLayers() const;
    void setSize(int width, int height);
    void startShapeCreateMode(HShapeType type);
    void startShapeEditMode(int layerIndex, int shapeIndex);
    void endShapeCreateMode();

    const QImage * getLayerBuffer() const;
    void calcShapesPoint();
    void calcLocationTrailPoint();

    HShape * getCurrShape() const;
    void setCurrShape(HShape* pShape);  //鍙互涓虹┖

    inline HGrafixStyle * getGrafixStyle() const;
    inline HMapSheet * getMapSheet() const;

    HLayerList * getLayerList() const;
    void saveToStream(QByteArray& stream);

private:
    friend class HMaps;
    HLayerList                  * m_pLayerList;
    QImage                      * m_pLayerBuffer;

    HShape                      * m_pCurrShape;
    HShapePoint                 * m_pCurrShapePoint;
    HGrafixStyle                * m_pGrafixStyle;
    HMapSheet                   * m_pSheet;

    HLocationTrail              * m_pLocationTrail;
};

#endif // HSHAPE_H
