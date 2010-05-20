/****************************************************************************
** Meta object code from reading C++ file 'mapoporfunkcioimpl.h'
**
** Created: Fri 21. May 00:17:52 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/mapoporfunkcioimpl.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mapoporfunkcioimpl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MapoPorFunkcioImpl[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       2,   59, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x05,
      36,   19,   19,   19, 0x05,
      52,   19,   19,   19, 0x05,

 // slots: signature, parameters, type, tag, flags
      69,   19,   19,   19, 0x0a,
     101,   94,   19,   19, 0x0a,
     119,  117,   19,   19, 0x0a,
     149,  143,   19,   19, 0x0a,
     169,   19,   19,   19, 0x08,
     197,   19,   19,   19, 0x08,

 // properties: name, type, flags
     229,  223, (QMetaType::QReal << 24) | 0x00095003,
     242,  235, 0x43095003,

       0        // eod
};

static const char qt_meta_stringdata_MapoPorFunkcioImpl[] = {
    "MapoPorFunkcioImpl\0\0MusaPosX(qreal)\0"
    "MusaPosY(qreal)\0MusaPos(QString)\0"
    "difiniFonaKoloro(QColor)\0factor\0"
    "setScale(qreal)\0f\0difiniFunkcio(funkcio*)\0"
    "Spuro\0difiniSpuro(spuro*)\0"
    "on_PligrandigiBtn_clicked()\0"
    "on_MalpliigiBtn_clicked()\0qreal\0skalo\0"
    "QColor\0fonaKoloro\0"
};

const QMetaObject MapoPorFunkcioImpl::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MapoPorFunkcioImpl,
      qt_meta_data_MapoPorFunkcioImpl, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MapoPorFunkcioImpl::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MapoPorFunkcioImpl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MapoPorFunkcioImpl::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MapoPorFunkcioImpl))
        return static_cast<void*>(const_cast< MapoPorFunkcioImpl*>(this));
    if (!strcmp(_clname, "Ui::MapoPorFunkcio"))
        return static_cast< Ui::MapoPorFunkcio*>(const_cast< MapoPorFunkcioImpl*>(this));
    return QWidget::qt_metacast(_clname);
}

int MapoPorFunkcioImpl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: MusaPosX((*reinterpret_cast< const qreal(*)>(_a[1]))); break;
        case 1: MusaPosY((*reinterpret_cast< const qreal(*)>(_a[1]))); break;
        case 2: MusaPos((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: difiniFonaKoloro((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 4: setScale((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 5: difiniFunkcio((*reinterpret_cast< funkcio*(*)>(_a[1]))); break;
        case 6: difiniSpuro((*reinterpret_cast< spuro*(*)>(_a[1]))); break;
        case 7: on_PligrandigiBtn_clicked(); break;
        case 8: on_MalpliigiBtn_clicked(); break;
        default: ;
        }
        _id -= 9;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< qreal*>(_v) = Scale(); break;
        case 1: *reinterpret_cast< QColor*>(_v) = fonaKoloro(); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setScale(*reinterpret_cast< qreal*>(_v)); break;
        case 1: difiniFonaKoloro(*reinterpret_cast< QColor*>(_v)); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void MapoPorFunkcioImpl::MusaPosX(const qreal _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MapoPorFunkcioImpl::MusaPosY(const qreal _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MapoPorFunkcioImpl::MusaPos(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
