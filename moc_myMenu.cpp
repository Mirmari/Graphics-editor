/****************************************************************************
** Meta object code from reading C++ file 'myMenu.h'
**
** Created: Fri Apr 14 10:25:39 2017
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "myMenu.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myMenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_myMenu[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x0a,
      19,    7,    7,    7, 0x0a,
      30,    7,    7,    7, 0x0a,
      40,    7,    7,    7, 0x0a,
      49,    7,    7,    7, 0x0a,
      58,    7,    7,    7, 0x0a,
      67,    7,    7,    7, 0x0a,
      78,    7,    7,    7, 0x0a,
      89,    7,    7,    7, 0x0a,
     102,    7,    7,    7, 0x0a,
     113,    7,    7,    7, 0x0a,
     122,    7,    7,    7, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_myMenu[] = {
    "myMenu\0\0openFile()\0saveFile()\0drPoint()\0"
    "drLine()\0drFree()\0drRect()\0lblClear()\0"
    "setColor()\0changeSize()\0drElipse()\0"
    "drText()\0drErase()\0"
};

void myMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        myMenu *_t = static_cast<myMenu *>(_o);
        switch (_id) {
        case 0: _t->openFile(); break;
        case 1: _t->saveFile(); break;
        case 2: _t->drPoint(); break;
        case 3: _t->drLine(); break;
        case 4: _t->drFree(); break;
        case 5: _t->drRect(); break;
        case 6: _t->lblClear(); break;
        case 7: _t->setColor(); break;
        case 8: _t->changeSize(); break;
        case 9: _t->drElipse(); break;
        case 10: _t->drText(); break;
        case 11: _t->drErase(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData myMenu::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject myMenu::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_myMenu,
      qt_meta_data_myMenu, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &myMenu::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *myMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *myMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_myMenu))
        return static_cast<void*>(const_cast< myMenu*>(this));
    return QWidget::qt_metacast(_clname);
}

int myMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
