/****************************************************************************
** Meta object code from reading C++ file 'MapCanvas.h'
**
** Created: Tue Jul 15 22:43:13 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MapCanvas.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MapCanvas.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MapCanvas[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x0a,
      20,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MapCanvas[] = {
    "MapCanvas\0\0ZoomIn()\0ZoomOut()\0"
};

void MapCanvas::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MapCanvas *_t = static_cast<MapCanvas *>(_o);
        switch (_id) {
        case 0: _t->ZoomIn(); break;
        case 1: _t->ZoomOut(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MapCanvas::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MapCanvas::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_MapCanvas,
      qt_meta_data_MapCanvas, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MapCanvas::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MapCanvas::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MapCanvas::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MapCanvas))
        return static_cast<void*>(const_cast< MapCanvas*>(this));
    return QGraphicsView::qt_metacast(_clname);
}

int MapCanvas::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
