#ifndef HADDRESSDETAIL_H
#define HADDRESSDETAIL_H

#include "hclientengine_const.h"
#include <QNetworkAccessManager>

#include <QObject>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QByteArray>
#include <QQueue>

class HCLIENTENGINESHARED_EXPORT HAddressDetail : public QObject
{
    Q_OBJECT
public:
    explicit HAddressDetail(QObject *parent = 0);
    virtual ~HAddressDetail();

    void request(double lng, double lat);

signals:
    void sig_getAddress(double rawLng, double rawLat, double lng, double lat,
                        QString address, QString description);

public slots:
    void onFinishedSlot(QNetworkReply*pReply);

private:
    QNetworkAccessManager                   * m_pNetworkManager;
    QQueue<QPointF>                             * m_pPointList;
};

#endif // HADDRESSDETAIL_H
