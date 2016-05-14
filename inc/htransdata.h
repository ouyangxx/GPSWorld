#ifndef HTRANSDATA_H
#define HTRANSDATA_H

#include <QHostAddress>
#include <QByteArray>

typedef struct _HTransData {
    QHostAddress    ip;
    quint16             port;
    QByteArray      data;
} HTransData, *PHTransData;

//enum HTransDataType{
//    tdtRequestTile = 0x01
//};

#endif // HTRANSDATA_H

