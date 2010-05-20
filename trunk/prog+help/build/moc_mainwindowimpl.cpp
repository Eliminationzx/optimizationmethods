/****************************************************************************
** Meta object code from reading C++ file 'mainwindowimpl.h'
**
** Created: Fri 21. May 00:17:49 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/mainwindowimpl.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindowimpl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindowImpl[] = {

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
      24,   16,   15,   15, 0x08,
      47,   16,   15,   15, 0x08,
      80,   74,   15,   15, 0x08,
     117,  112,   15,   15, 0x08,
     138,   15,   15,   15, 0x08,
     159,   15,   15,   15, 0x08,
     184,   15,   15,   15, 0x08,
     211,   15,   15,   15, 0x08,
     236,   74,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindowImpl[] = {
    "MainWindowImpl\0\0checked\0on_inArm_clicked(bool)\0"
    "on_choiceVar_clicked(bool)\0index\0"
    "on_choiceMethods_activated(int)\0flag\0"
    "openTakeQuadFun(int)\0on_allow_activated()\0"
    "on_next_button_clicked()\0"
    "on_next_button_2_clicked()\0"
    "on_back_button_clicked()\0"
    "on_comboBox_activated(int)\0"
};

const QMetaObject MainWindowImpl::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindowImpl,
      qt_meta_data_MainWindowImpl, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindowImpl::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindowImpl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindowImpl::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindowImpl))
        return static_cast<void*>(const_cast< MainWindowImpl*>(this));
    if (!strcmp(_clname, "Ui::MainWindow"))
        return static_cast< Ui::MainWindow*>(const_cast< MainWindowImpl*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindowImpl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_inArm_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: on_choiceVar_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: on_choiceMethods_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: openTakeQuadFun((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: on_allow_activated(); break;
        case 5: on_next_button_clicked(); break;
        case 6: on_next_button_2_clicked(); break;
        case 7: on_back_button_clicked(); break;
        case 8: on_comboBox_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
