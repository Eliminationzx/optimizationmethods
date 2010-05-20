/****************************************************************************
** Meta object code from reading C++ file 'signalantoporpointf.h'
**
** Created: Fri 21. May 00:17:59 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/signalantoporpointf.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'signalantoporpointf.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SignalantoPorPointF[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x05,
      57,   20,   20,   20, 0x05,
      94,   20,   20,   20, 0x05,
     117,   20,   20,   20, 0x05,
     140,   20,   20,   20, 0x05,
     167,  160,   20,   20, 0x05,
     190,   20,   20,   20, 0x05,
     214,   20,   20,   20, 0x05,
     234,  160,   20,   20, 0x05,
     257,   20,   20,   20, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_SignalantoPorPointF[] = {
    "SignalantoPorPointF\0\0"
    "proviziValoroFukcioEnPointo(double)\0"
    "proviziValoroFukcioEnPointo(QString)\0"
    "proviziValoro(QPointF)\0proviziValoro(QString)\0"
    "proviziXValoro(int)\0valoro\0"
    "proviziXValoro(double)\0proviziXValoro(QString)\0"
    "proviziYValoro(int)\0proviziYValoro(double)\0"
    "proviziYValoro(QString)\0"
};

const QMetaObject SignalantoPorPointF::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SignalantoPorPointF,
      qt_meta_data_SignalantoPorPointF, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SignalantoPorPointF::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SignalantoPorPointF::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SignalantoPorPointF::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SignalantoPorPointF))
        return static_cast<void*>(const_cast< SignalantoPorPointF*>(this));
    return QObject::qt_metacast(_clname);
}

int SignalantoPorPointF::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: proviziValoroFukcioEnPointo((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: proviziValoroFukcioEnPointo((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: proviziValoro((*reinterpret_cast< const QPointF(*)>(_a[1]))); break;
        case 3: proviziValoro((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: proviziXValoro((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: proviziXValoro((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: proviziXValoro((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: proviziYValoro((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: proviziYValoro((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: proviziYValoro((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void SignalantoPorPointF::proviziValoroFukcioEnPointo(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SignalantoPorPointF::proviziValoroFukcioEnPointo(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SignalantoPorPointF::proviziValoro(const QPointF & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SignalantoPorPointF::proviziValoro(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void SignalantoPorPointF::proviziXValoro(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void SignalantoPorPointF::proviziXValoro(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void SignalantoPorPointF::proviziXValoro(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void SignalantoPorPointF::proviziYValoro(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void SignalantoPorPointF::proviziYValoro(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void SignalantoPorPointF::proviziYValoro(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_END_MOC_NAMESPACE
