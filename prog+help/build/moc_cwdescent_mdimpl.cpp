/****************************************************************************
** Meta object code from reading C++ file 'cwdescent_mdimpl.h'
**
** Created: Fri 21. May 00:18:00 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/cwdescent_mdimpl.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cwdescent_mdimpl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CWdescent_mdImpl[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      36,   17,   17,   17, 0x08,
      43,   17,   17,   17, 0x08,
      56,   17,   17,   17, 0x08,
      69,   17,   17,   17, 0x08,
      82,   17,   17,   17, 0x08,
      95,   17,   17,   17, 0x08,
     108,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CWdescent_mdImpl[] = {
    "CWdescent_mdImpl\0\0stateHasEntered()\0"
    "init()\0so_entered()\0s1_entered()\0"
    "s2_entered()\0s3_entered()\0sf_entered()\0"
    "registriEraro()\0"
};

const QMetaObject CWdescent_mdImpl::staticMetaObject = {
    { &AlgoritmoWin::staticMetaObject, qt_meta_stringdata_CWdescent_mdImpl,
      qt_meta_data_CWdescent_mdImpl, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CWdescent_mdImpl::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CWdescent_mdImpl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CWdescent_mdImpl::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CWdescent_mdImpl))
        return static_cast<void*>(const_cast< CWdescent_mdImpl*>(this));
    if (!strcmp(_clname, "Ui::CWdescent_md"))
        return static_cast< Ui::CWdescent_md*>(const_cast< CWdescent_mdImpl*>(this));
    return AlgoritmoWin::qt_metacast(_clname);
}

int CWdescent_mdImpl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AlgoritmoWin::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: stateHasEntered(); break;
        case 1: init(); break;
        case 2: so_entered(); break;
        case 3: s1_entered(); break;
        case 4: s2_entered(); break;
        case 5: s3_entered(); break;
        case 6: sf_entered(); break;
        case 7: registriEraro(); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void CWdescent_mdImpl::stateHasEntered()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
