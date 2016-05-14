#ifndef HBASESHAPE_H
#define HBASESHAPE_H

#include <QObject>
#include <QPainter>
#include <QString>

class HMapSheet;

typedef struct HShapePoint{
    double              lng;    //缁忓害
    double              lat;
    int                     tileColumnIndex;    //褰撳墠鍦板浘绾у埆鏃剁殑tileIndex
    int                     tileRowIndex;
    int                     tileOffsetX;    //褰撳墠鍦板浘绾у埆鏃剁殑tileOffset
    int                     tileOffsetY;

    HShapePoint(double _lng, double _lat, int _tileColumnIndex, int _tileRowIndex,
            int _tileOffsetX, int _tileOffsetY) {
//        lng = _lng;
//        lat = _lat;
//        tileColumnIndex = _tileColumnIndex;
//        tileRowIndex = _tileRowIndex;
//        tileOffsetX = _tileOffsetX;
//        tileOffsetY = _tileOffsetY;
        setValue(_lng, _lat, _tileColumnIndex, _tileRowIndex, _tileOffsetX, _tileOffsetY);
    }

    inline void setValue(double _lng, double _lat, int _tileColumnIndex, int _tileRowIndex,
                         int _tileOffsetX, int _tileOffsetY) {
        lng = _lng;
        lat = _lat;
        tileColumnIndex = _tileColumnIndex;
        tileRowIndex = _tileRowIndex;
        tileOffsetX = _tileOffsetX;
        tileOffsetY = _tileOffsetY;
    }
} HShapePoint;

#define pointEditModeRange  4   //鍦嗚〃绀哄崐寰?
#define pointShowModeRange 2

typedef QList<HShapePoint *>           HShapePointList;        //QPointF 琛ㄧず鍧愭爣鍊?

class HBaseShape : public QObject
{
    Q_OBJECT
public:
    explicit HBaseShape(HMapSheet * pSheet);
    virtual ~HBaseShape();

    void clearShapePointList();

    virtual const QString& getName() const;
    virtual bool setName(const QString& name);

    bool isOverlapPoint(int x1, int y1, int x2, int y2) const;

    virtual void paint(QPainter * pPainter);
    virtual void paintShape(QPainter * pPainter) = 0;

    virtual void addPoint(HShapePoint *value);
    virtual bool isInScreen();
    virtual void clearPointList();
    virtual void removePoint(int index);
    virtual void calcShapePoint();
    HShapePointList* getShapePointList() const;

signals:
    void sig_changePoint(HShapePoint* p, double lng, double lat,
                int tileColumnIndex, int tileRowIndex, int tileOffsetX, int tileOffsetY);

public slots:
    virtual void onChangePoint(HShapePoint* p, double lng, double lat,
                int tileColumnIndex, int tileRowIndex, int tileOffsetX, int tileOffsetY);

protected:
    friend class HGrafixManager;
    friend class HLayer;
    friend class HMaps;
    QString                                 m_name;
    HShapePointList                     * m_pShapePointList;
    HMapSheet                           * m_pSheet;
};

#endif // HBASESHAPE_H
