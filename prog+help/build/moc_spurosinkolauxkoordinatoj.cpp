/****************************************************************************
** Meta object code from reading C++ file 'spurosinkolauxkoordinatoj.h'
**
** Created: Fri 21. May 00:17:55 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/spurosinkolauxkoordinatoj.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'spurosinkolauxkoordinatoj.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_spuroSinkoLauxKoordinatoj[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      29,   27,   26,   26, 0x0a,
      59,   55,   26,   26, 0x0a,
      89,   26,   26,   26, 0x0a,
     107,   26,   26,   26, 0x0a,
     131,   26,   26,   26, 0x0a,
     162,   26,   26,   26, 0x0a,
     202,  191,   26,   26, 0x0a,
     241,  227,   26,   26, 0x0a,
     269,   26,   26,   26, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_spuroSinkoLauxKoordinatoj[] = {
    "spuroSinkoLauxKoordinatoj\0\0p\0"
    "difiniUnuaPointo(QPointF)\0x,y\0"
    "difiniUnuaPointo(qreal,qreal)\0"
    "finisxiIteracio()\0reveniAlMomentoPointo()\0"
    "aldoniSercxantaPointo(QPointF)\0"
    "difiniMomentaPointo(QPointF)\0bazaKoloro\0"
    "difiniBazaKoloro(QColor)\0momentaKoloro\0"
    "difiniMomentaKoloro(QColor)\0senspurigi()\0"
};

const QMetaObject spuroSinkoLauxKoordinatoj::staticMetaObject = {
    { &spuro::staticMetaObject, qt_meta_stringdata_spuroSinkoLauxKoordinatoj,
      qt_meta_data_spuroSinkoLauxKoordinatoj, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &spuroSinkoLauxKoordinatoj::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *spuroSinkoLauxKoordinatoj::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *spuroSinkoLauxKoordinatoj::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_spuroSinkoLauxKoordinatoj))
        return static_cast<void*>(const_cast< spuroSinkoLauxKoordinatoj*>(this));
    return spuro::qt_metacast(_clname);
}

int spuroSinkoLauxKoordinatoj::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = spuro::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: difiniUnuaPointo((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 1: difiniUnuaPointo((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        case 2: finisxiIteracio(); break;
        case 3: reveniAlMomentoPointo(); break;
        case 4: aldoniSercxantaPointo((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 5: difiniMomentaPointo((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 6: difiniBazaKoloro((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 7: difiniMomentaKoloro((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 8: senspurigi(); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
