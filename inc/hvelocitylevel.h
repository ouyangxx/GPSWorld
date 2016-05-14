#ifndef HVELOCITYLEVEL_H
#define HVELOCITYLEVEL_H
#include <QWidget>
#include <QImage>
#include <QMouseEvent>

#include <QtCore/qglobal.h>

#define VelocityLevel_ElementWidth    11
#define VelocityLevel_ElementHeight   11

#if defined(VELOCITYLEVEL_LIBRARY)
#  define VELOCITYLEVELSHARED_EXPORT Q_DECL_EXPORT
#else
#  define VELOCITYLEVELSHARED_EXPORT Q_DECL_IMPORT
#endif

class VELOCITYLEVELSHARED_EXPORT HVelocityLevel : public QWidget
{
public:
    explicit HVelocityLevel(QWidget * parent = 0);
    virtual ~HVelocityLevel();

    void setCurrLevel(int level);
    int currLevel() const;

protected:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void paintEvent(QPaintEvent * e);

private:
    QImage                      * m_pSelect1Img;
    QImage                      * m_pSelect2Img;
    int                             m_currLevel;
};

#endif // HVELOCITYLEVEL_H
