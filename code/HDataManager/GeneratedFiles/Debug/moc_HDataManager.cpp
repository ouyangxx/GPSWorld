/****************************************************************************
** Meta object code from reading C++ file 'HDataManager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../inc/HDataManager/HDataManager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'HDataManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_HDataManager_t {
    QByteArrayData data[45];
    char stringdata0[618];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HDataManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HDataManager_t qt_meta_stringdata_HDataManager = {
    {
QT_MOC_LITERAL(0, 0, 12), // "HDataManager"
QT_MOC_LITERAL(1, 13, 16), // "sig_loginSuccess"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 9), // "isSuccess"
QT_MOC_LITERAL(4, 41, 17), // "sig_updateCarInfo"
QT_MOC_LITERAL(5, 59, 19), // "sig_updateTrackInfo"
QT_MOC_LITERAL(6, 79, 20), // "sig_updateDeviceInfo"
QT_MOC_LITERAL(7, 100, 35), // "QList<XYDeviceHeader::HDevice..."
QT_MOC_LITERAL(8, 136, 14), // "checkedDevices"
QT_MOC_LITERAL(9, 151, 21), // "onClientEngineStarted"
QT_MOC_LITERAL(10, 173, 21), // "onClientEngineStopped"
QT_MOC_LITERAL(11, 195, 14), // "onLoginRespond"
QT_MOC_LITERAL(12, 210, 11), // "respondFlag"
QT_MOC_LITERAL(13, 222, 12), // "onDeviceInfo"
QT_MOC_LITERAL(14, 235, 8), // "deviceID"
QT_MOC_LITERAL(15, 244, 11), // "phoneNumber"
QT_MOC_LITERAL(16, 256, 13), // "vehicleNumber"
QT_MOC_LITERAL(17, 270, 8), // "isOnline"
QT_MOC_LITERAL(18, 279, 8), // "lastTime"
QT_MOC_LITERAL(19, 288, 3), // "lat"
QT_MOC_LITERAL(20, 292, 3), // "lng"
QT_MOC_LITERAL(21, 296, 11), // "orientation"
QT_MOC_LITERAL(22, 308, 10), // "onUserInfo"
QT_MOC_LITERAL(23, 319, 11), // "companyName"
QT_MOC_LITERAL(24, 331, 20), // "onDeviceLocationInfo"
QT_MOC_LITERAL(25, 352, 20), // "HTerminalMsgLocation"
QT_MOC_LITERAL(26, 373, 12), // "locationInfo"
QT_MOC_LITERAL(27, 386, 14), // "HTerminalState"
QT_MOC_LITERAL(28, 401, 5), // "state"
QT_MOC_LITERAL(29, 407, 14), // "onLocationLogs"
QT_MOC_LITERAL(30, 422, 5), // "count"
QT_MOC_LITERAL(31, 428, 5), // "index"
QT_MOC_LITERAL(32, 434, 29), // "QList<HTerminalMsgLocation*>*"
QT_MOC_LITERAL(33, 464, 5), // "pList"
QT_MOC_LITERAL(34, 470, 11), // "onAlarmLogs"
QT_MOC_LITERAL(35, 482, 22), // "QList<HAlarmLogInfo*>*"
QT_MOC_LITERAL(36, 505, 9), // "onOffline"
QT_MOC_LITERAL(37, 515, 8), // "onOnline"
QT_MOC_LITERAL(38, 524, 12), // "onGetAddress"
QT_MOC_LITERAL(39, 537, 6), // "rawLng"
QT_MOC_LITERAL(40, 544, 6), // "rawLat"
QT_MOC_LITERAL(41, 551, 7), // "address"
QT_MOC_LITERAL(42, 559, 11), // "description"
QT_MOC_LITERAL(43, 571, 22), // "onAllRulesLoadedFromDB"
QT_MOC_LITERAL(44, 594, 23) // "onAllShapesLoadedFromDB"

    },
    "HDataManager\0sig_loginSuccess\0\0isSuccess\0"
    "sig_updateCarInfo\0sig_updateTrackInfo\0"
    "sig_updateDeviceInfo\0"
    "QList<XYDeviceHeader::HDeviceInfo*>\0"
    "checkedDevices\0onClientEngineStarted\0"
    "onClientEngineStopped\0onLoginRespond\0"
    "respondFlag\0onDeviceInfo\0deviceID\0"
    "phoneNumber\0vehicleNumber\0isOnline\0"
    "lastTime\0lat\0lng\0orientation\0onUserInfo\0"
    "companyName\0onDeviceLocationInfo\0"
    "HTerminalMsgLocation\0locationInfo\0"
    "HTerminalState\0state\0onLocationLogs\0"
    "count\0index\0QList<HTerminalMsgLocation*>*\0"
    "pList\0onAlarmLogs\0QList<HAlarmLogInfo*>*\0"
    "onOffline\0onOnline\0onGetAddress\0rawLng\0"
    "rawLat\0address\0description\0"
    "onAllRulesLoadedFromDB\0onAllShapesLoadedFromDB"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HDataManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x06 /* Public */,
       4,    0,  102,    2, 0x06 /* Public */,
       5,    0,  103,    2, 0x06 /* Public */,
       6,    1,  104,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,  107,    2, 0x0a /* Public */,
      10,    0,  108,    2, 0x0a /* Public */,
      11,    1,  109,    2, 0x0a /* Public */,
      13,    8,  112,    2, 0x0a /* Public */,
      22,    1,  129,    2, 0x0a /* Public */,
      24,    3,  132,    2, 0x0a /* Public */,
      29,    3,  139,    2, 0x0a /* Public */,
      34,    3,  146,    2, 0x0a /* Public */,
      36,    1,  153,    2, 0x0a /* Public */,
      37,    1,  156,    2, 0x0a /* Public */,
      38,    6,  159,    2, 0x0a /* Public */,
      43,    0,  172,    2, 0x0a /* Public */,
      44,    0,  173,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UShort,   12,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Bool, QMetaType::QDateTime, QMetaType::Int, QMetaType::Int, QMetaType::Short,   14,   15,   16,   17,   18,   19,   20,   21,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 25, 0x80000000 | 27,   14,   26,   28,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 32,   30,   31,   33,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 35,   30,   31,   33,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::QString, QMetaType::QString,   39,   40,   20,   19,   41,   42,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void HDataManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HDataManager *_t = static_cast<HDataManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_loginSuccess((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->sig_updateCarInfo(); break;
        case 2: _t->sig_updateTrackInfo(); break;
        case 3: _t->sig_updateDeviceInfo((*reinterpret_cast< QList<XYDeviceHeader::HDeviceInfo*>(*)>(_a[1]))); break;
        case 4: _t->onClientEngineStarted(); break;
        case 5: _t->onClientEngineStopped(); break;
        case 6: _t->onLoginRespond((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 7: _t->onDeviceInfo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< QDateTime(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< qint16(*)>(_a[8]))); break;
        case 8: _t->onUserInfo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->onDeviceLocationInfo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< HTerminalMsgLocation(*)>(_a[2])),(*reinterpret_cast< HTerminalState(*)>(_a[3]))); break;
        case 10: _t->onLocationLogs((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QList<HTerminalMsgLocation*>*(*)>(_a[3]))); break;
        case 11: _t->onAlarmLogs((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QList<HAlarmLogInfo*>*(*)>(_a[3]))); break;
        case 12: _t->onOffline((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->onOnline((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->onGetAddress((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6]))); break;
        case 15: _t->onAllRulesLoadedFromDB(); break;
        case 16: _t->onAllShapesLoadedFromDB(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< HTerminalMsgLocation >(); break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< HTerminalState >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (HDataManager::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HDataManager::sig_loginSuccess)) {
                *result = 0;
            }
        }
        {
            typedef void (HDataManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HDataManager::sig_updateCarInfo)) {
                *result = 1;
            }
        }
        {
            typedef void (HDataManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HDataManager::sig_updateTrackInfo)) {
                *result = 2;
            }
        }
        {
            typedef void (HDataManager::*_t)(QList<XYDeviceHeader::HDeviceInfo*> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HDataManager::sig_updateDeviceInfo)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject HDataManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_HDataManager.data,
      qt_meta_data_HDataManager,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *HDataManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HDataManager::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_HDataManager.stringdata0))
        return static_cast<void*>(const_cast< HDataManager*>(this));
    return QObject::qt_metacast(_clname);
}

int HDataManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void HDataManager::sig_loginSuccess(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void HDataManager::sig_updateCarInfo()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void HDataManager::sig_updateTrackInfo()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void HDataManager::sig_updateDeviceInfo(QList<XYDeviceHeader::HDeviceInfo*> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
