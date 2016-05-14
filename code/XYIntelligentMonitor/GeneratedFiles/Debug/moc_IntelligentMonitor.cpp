/****************************************************************************
** Meta object code from reading C++ file 'IntelligentMonitor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../IntelligentMonitor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'IntelligentMonitor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_IntelligentMonitor_t {
    QByteArrayData data[13];
    char stringdata0[249];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IntelligentMonitor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IntelligentMonitor_t qt_meta_stringdata_IntelligentMonitor = {
    {
QT_MOC_LITERAL(0, 0, 18), // "IntelligentMonitor"
QT_MOC_LITERAL(1, 19, 14), // "onUpdateCarBox"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 24), // "onCarcurrentIndexChanged"
QT_MOC_LITERAL(4, 60, 5), // "index"
QT_MOC_LITERAL(5, 66, 21), // "onClickVechicleShapes"
QT_MOC_LITERAL(6, 88, 28), // "QMap<QString,HVehicleShape*>"
QT_MOC_LITERAL(7, 117, 20), // "on_btn_navi1_clicked"
QT_MOC_LITERAL(8, 138, 20), // "on_btn_navi2_clicked"
QT_MOC_LITERAL(9, 159, 20), // "on_btn_navi3_clicked"
QT_MOC_LITERAL(10, 180, 25), // "on_btn_carMonitor_clicked"
QT_MOC_LITERAL(11, 206, 21), // "on_btn_curvey_clicked"
QT_MOC_LITERAL(12, 228, 20) // "on_btn_excel_clicked"

    },
    "IntelligentMonitor\0onUpdateCarBox\0\0"
    "onCarcurrentIndexChanged\0index\0"
    "onClickVechicleShapes\0"
    "QMap<QString,HVehicleShape*>\0"
    "on_btn_navi1_clicked\0on_btn_navi2_clicked\0"
    "on_btn_navi3_clicked\0on_btn_carMonitor_clicked\0"
    "on_btn_curvey_clicked\0on_btn_excel_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IntelligentMonitor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x0a /* Public */,
       3,    1,   60,    2, 0x0a /* Public */,
       5,    1,   63,    2, 0x0a /* Public */,
       7,    0,   66,    2, 0x08 /* Private */,
       8,    0,   67,    2, 0x08 /* Private */,
       9,    0,   68,    2, 0x08 /* Private */,
      10,    0,   69,    2, 0x08 /* Private */,
      11,    0,   70,    2, 0x08 /* Private */,
      12,    0,   71,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void IntelligentMonitor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IntelligentMonitor *_t = static_cast<IntelligentMonitor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onUpdateCarBox(); break;
        case 1: _t->onCarcurrentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->onClickVechicleShapes((*reinterpret_cast< QMap<QString,HVehicleShape*>(*)>(_a[1]))); break;
        case 3: _t->on_btn_navi1_clicked(); break;
        case 4: _t->on_btn_navi2_clicked(); break;
        case 5: _t->on_btn_navi3_clicked(); break;
        case 6: _t->on_btn_carMonitor_clicked(); break;
        case 7: _t->on_btn_curvey_clicked(); break;
        case 8: _t->on_btn_excel_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject IntelligentMonitor::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_IntelligentMonitor.data,
      qt_meta_data_IntelligentMonitor,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *IntelligentMonitor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IntelligentMonitor::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_IntelligentMonitor.stringdata0))
        return static_cast<void*>(const_cast< IntelligentMonitor*>(this));
    return QWidget::qt_metacast(_clname);
}

int IntelligentMonitor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
