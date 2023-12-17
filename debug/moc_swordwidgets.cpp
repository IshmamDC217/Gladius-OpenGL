/****************************************************************************
** Meta object code from reading C++ file 'swordwidgets.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../swordwidgets.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'swordwidgets.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_swordwidgets_t {
    QByteArrayData data[15];
    char stringdata0[70];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_swordwidgets_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_swordwidgets_t qt_meta_stringdata_swordwidgets = {
    {
QT_MOC_LITERAL(0, 0, 12), // "swordwidgets"
QT_MOC_LITERAL(1, 13, 3), // "xax"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 1), // "x"
QT_MOC_LITERAL(4, 20, 3), // "yax"
QT_MOC_LITERAL(5, 24, 1), // "y"
QT_MOC_LITERAL(6, 26, 3), // "zax"
QT_MOC_LITERAL(7, 30, 1), // "z"
QT_MOC_LITERAL(8, 32, 3), // "wax"
QT_MOC_LITERAL(9, 36, 1), // "w"
QT_MOC_LITERAL(10, 38, 5), // "l_xax"
QT_MOC_LITERAL(11, 44, 5), // "l_yax"
QT_MOC_LITERAL(12, 50, 5), // "l_zax"
QT_MOC_LITERAL(13, 56, 9), // "playPause"
QT_MOC_LITERAL(14, 66, 3) // "ang"

    },
    "swordwidgets\0xax\0\0x\0yax\0y\0zax\0z\0wax\0"
    "w\0l_xax\0l_yax\0l_zax\0playPause\0ang"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_swordwidgets[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x0a /* Public */,
       4,    1,   62,    2, 0x0a /* Public */,
       6,    1,   65,    2, 0x0a /* Public */,
       8,    1,   68,    2, 0x0a /* Public */,
      10,    1,   71,    2, 0x0a /* Public */,
      11,    1,   74,    2, 0x0a /* Public */,
      12,    1,   77,    2, 0x0a /* Public */,
      13,    0,   80,    2, 0x0a /* Public */,
      14,    0,   81,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void swordwidgets::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<swordwidgets *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->xax((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->yax((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->zax((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->wax((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->l_xax((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->l_yax((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->l_zax((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->playPause(); break;
        case 8: _t->ang(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject swordwidgets::staticMetaObject = { {
    QMetaObject::SuperData::link<QGLWidget::staticMetaObject>(),
    qt_meta_stringdata_swordwidgets.data,
    qt_meta_data_swordwidgets,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *swordwidgets::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *swordwidgets::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_swordwidgets.stringdata0))
        return static_cast<void*>(this);
    return QGLWidget::qt_metacast(_clname);
}

int swordwidgets::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
