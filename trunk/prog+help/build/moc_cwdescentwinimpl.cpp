/****************************************************************************
** Meta object code from reading C++ file 'cwdescentwinimpl.h'
**
** Created: Fri 21. May 00:17:56 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/cwdescentwinimpl.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cwdescentwinimpl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CWdescentWinImpl[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x05,
      34,   17,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      52,   17,   17,   17, 0x08,
      75,   17,   17,   17, 0x08,
     106,   17,   17,   17, 0x08,
     113,   17,   17,   17, 0x08,
     126,   17,   17,   17, 0x08,
     139,   17,   17,   17, 0x08,
     152,   17,   17,   17, 0x08,
     165,   17,   17,   17, 0x08,
     178,   17,   17,   17, 0x08,
     191,   17,   17,   17, 0x08,
     204,   17,   17,   17, 0x08,
     217,   17,   17,   17, 0x08,
     230,   17,   17,   17, 0x08,
     243,   17,   17,   17, 0x08,
     257,   17,   17,   17, 0x08,
     271,   17,   17,   17, 0x08,
     285,   17,   17,   17, 0x08,
     298,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CWdescentWinImpl[] = {
    "CWdescentWinImpl\0\0usiloPlenumis()\0"
    "stateHasEntered()\0on_BroHelp_activated()\0"
    "on_difiniFonto_act_activated()\0init()\0"
    "so_entered()\0s1_entered()\0s2_entered()\0"
    "s3_entered()\0s4_entered()\0s5_entered()\0"
    "s6_entered()\0s7_entered()\0s8_entered()\0"
    "s9_entered()\0s10_entered()\0s11_entered()\0"
    "s12_entered()\0sf_entered()\0registriEraro()\0"
};

const QMetaObject CWdescentWinImpl::staticMetaObject = {
    { &AlgoritmoWin::staticMetaObject, qt_meta_stringdata_CWdescentWinImpl,
      qt_meta_data_CWdescentWinImpl, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CWdescentWinImpl::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CWdescentWinImpl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CWdescentWinImpl::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CWdescentWinImpl))
        return static_cast<void*>(const_cast< CWdescentWinImpl*>(this));
    if (!strcmp(_clname, "Ui::CWdescentWin"))
        return static_cast< Ui::CWdescentWin*>(const_cast< CWdescentWinImpl*>(this));
    return AlgoritmoWin::qt_metacast(_clname);
}

int CWdescentWinImpl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AlgoritmoWin::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: usiloPlenumis(); break;
        case 1: stateHasEntered(); break;
        case 2: on_BroHelp_activated(); break;
        case 3: on_difiniFonto_act_activated(); break;
        case 4: init(); break;
        case 5: so_entered(); break;
        case 6: s1_entered(); break;
        case 7: s2_entered(); break;
        case 8: s3_entered(); break;
        case 9: s4_entered(); break;
        case 10: s5_entered(); break;
        case 11: s6_entered(); break;
        case 12: s7_entered(); break;
        case 13: s8_entered(); break;
        case 14: s9_entered(); break;
        case 15: s10_entered(); break;
        case 16: s11_entered(); break;
        case 17: s12_entered(); break;
        case 18: sf_entered(); break;
        case 19: registriEraro(); break;
        default: ;
        }
        _id -= 20;
    }
    return _id;
}

// SIGNAL 0
void CWdescentWinImpl::usiloPlenumis()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void CWdescentWinImpl::stateHasEntered()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
