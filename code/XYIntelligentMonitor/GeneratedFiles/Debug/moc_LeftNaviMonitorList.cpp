/****************************************************************************
** Meta object code from reading C++ file 'LeftNaviMonitorList.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../LeftNaviMonitorList.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LeftNaviMonitorList.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_LeftNaviMonitorList_t {
    QByteArrayData data[7];
    char stringdata0[84];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LeftNaviMonitorList_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LeftNaviMonitorList_t qt_meta_stringdata_LeftNaviMonitorList = {
    {
QT_MOC_LITERAL(0, 0, 19), // "LeftNaviMonitorList"
QT_MOC_LITERAL(1, 20, 15), // "onUpdateCarInfo"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 17), // "onTreeItemChanged"
QT_MOC_LITERAL(4, 55, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(5, 72, 4), // "item"
QT_MOC_LITERAL(6, 77, 6) // "column"

    },
    "LeftNaviMonitorList\0onUpdateCarInfo\0"
    "\0onTreeItemChanged\0QTreeWidgetItem*\0"
    "item\0column"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LeftNaviMonitorList[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x0a /* Public */,
       3,    2,   25,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, QMetaType::Int,    5,    6,

       0        // eod
};

void LeftNaviMonitorList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LeftNaviMonitorList *_t = static_cast<LeftNaviMonitorList *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onUpdateCarInfo(); break;
        case 1: _t->onTreeItemChanged((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject LeftNaviMonitorList::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_LeftNaviMonitorList.data,
      qt_meta_data_LeftNaviMonitorList,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *LeftNaviMonitorList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LeftNaviMonitorList::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_LeftNaviMonitorList.stringdata0))
        return static_cast<void*>(const_cast< LeftNaviMonitorList*>(this));
    return QWidget::qt_metacast(_clname);
}

int LeftNaviMonitorList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
