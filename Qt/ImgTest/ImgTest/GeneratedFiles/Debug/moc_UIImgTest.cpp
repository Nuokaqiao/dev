/****************************************************************************
** Meta object code from reading C++ file 'UIImgTest.h'
**
** Created: Mon Jul 14 22:19:53 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../UIImgTest.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UIImgTest.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_UIImgTest[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x0a,
      26,   10,   10,   10, 0x0a,
      33,   10,   10,   10, 0x0a,
      54,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_UIImgTest[] = {
    "UIImgTest\0\0PickOpenFile()\0Exit()\0"
    "ShowFileListWindow()\0ShowInforWindow()\0"
};

void UIImgTest::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        UIImgTest *_t = static_cast<UIImgTest *>(_o);
        switch (_id) {
        case 0: _t->PickOpenFile(); break;
        case 1: _t->Exit(); break;
        case 2: _t->ShowFileListWindow(); break;
        case 3: _t->ShowInforWindow(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData UIImgTest::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject UIImgTest::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_UIImgTest,
      qt_meta_data_UIImgTest, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &UIImgTest::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *UIImgTest::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *UIImgTest::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_UIImgTest))
        return static_cast<void*>(const_cast< UIImgTest*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int UIImgTest::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
