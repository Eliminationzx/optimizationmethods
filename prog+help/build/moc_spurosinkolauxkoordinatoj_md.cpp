/****************************************************************************
** Meta object code from reading C++ file 'spurosinkolauxkoordinatoj_md.h'
**
** Created: Fri 21. May 00:18:07 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/spurosinkolauxkoordinatoj_md.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'spurosinkolauxkoordinatoj_md.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_spuroSinkoLauxKoordinatoj_md[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      32,   30,   29,   29, 0x0a,
      62,   58,   29,   29, 0x0a,
      92,   29,   29,   29, 0x0a,
     110,   29,   29,   29, 0x0a,
     143,  132,   29,   29, 0x0a,
     182,  168,   29,   29, 0x0a,
     210,   29,   29,   29, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_spuroSinkoLauxKoordinatoj_md[] = {
    "spuroSinkoLauxKoordinatoj_md\0\0p\0"
    "difiniUnuaPointo(QPointF)\0x,y\0"
    "difiniUnuaPointo(qreal,qreal)\0"
    "finisxiIteracio()\0aldoniPointo(QPointF)\0"
    "bazaKoloro\0difiniBazaKoloro(QColor)\0"
    "momentaKoloro\0difiniMomentaKoloro(QColor)\0"
    "senspurigi()\0"
};

const QMetaObject spuroSinkoLauxKoordinatoj_md::staticMetaObject = {
    { &spuro::staticMetaObject, qt_meta_stringdata_spuroSinkoLauxKoordinatoj_md,
      qt_meta_data_spuroSinkoLauxKoordinatoj_md, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &spuroSinkoLauxKoordinatoj_md::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *spuroSinkoLauxKoordinatoj_md::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *spuroSinkoLauxKoordinatoj_md::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_spuroSinkoLauxKoordinatoj_md))
        return static_cast<void*>(const_cast< spuroSinkoLauxKoordinatoj_md*>(this));
    return spuro::qt_metacast(_clname);
}

int spuroSinkoLauxKoordinatoj_md::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = spuro::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: difiniUnuaPointo((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 1: difiniUnuaPointo((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        case 2: finisxiIteracio(); break;
        case 3: aldoniPointo((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 4: difiniBazaKoloro((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 5: difiniMomentaKoloro((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 6: senspurigi(); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
