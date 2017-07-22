/****************************************************************************
** Meta object code from reading C++ file 'roboconfig.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../roboconfig.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'roboconfig.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RoboConfig_t {
    QByteArrayData data[14];
    char stringdata0[218];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RoboConfig_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RoboConfig_t qt_meta_stringdata_RoboConfig = {
    {
QT_MOC_LITERAL(0, 0, 10), // "RoboConfig"
QT_MOC_LITERAL(1, 11, 21), // "on_saveButton_clicked"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 20), // "on_newButton_clicked"
QT_MOC_LITERAL(4, 55, 23), // "on_deleteButton_clicked"
QT_MOC_LITERAL(5, 79, 13), // "SelecionaRobo"
QT_MOC_LITERAL(6, 93, 12), // "AtualizaTipo"
QT_MOC_LITERAL(7, 106, 11), // "AtualizaPID"
QT_MOC_LITERAL(8, 118, 14), // "AtualizaCorPri"
QT_MOC_LITERAL(9, 133, 14), // "AtualizaCorSec"
QT_MOC_LITERAL(10, 148, 14), // "AtualizaCorTer"
QT_MOC_LITERAL(11, 163, 15), // "AtualizaEndXBee"
QT_MOC_LITERAL(12, 179, 19), // "AtualizaSetPointVel"
QT_MOC_LITERAL(13, 199, 18) // "AtualizaTrajetoria"

    },
    "RoboConfig\0on_saveButton_clicked\0\0"
    "on_newButton_clicked\0on_deleteButton_clicked\0"
    "SelecionaRobo\0AtualizaTipo\0AtualizaPID\0"
    "AtualizaCorPri\0AtualizaCorSec\0"
    "AtualizaCorTer\0AtualizaEndXBee\0"
    "AtualizaSetPointVel\0AtualizaTrajetoria"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RoboConfig[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    1,   77,    2, 0x08 /* Private */,
       6,    0,   80,    2, 0x08 /* Private */,
       7,    0,   81,    2, 0x08 /* Private */,
       8,    0,   82,    2, 0x08 /* Private */,
       9,    0,   83,    2, 0x08 /* Private */,
      10,    0,   84,    2, 0x08 /* Private */,
      11,    0,   85,    2, 0x08 /* Private */,
      12,    0,   86,    2, 0x08 /* Private */,
      13,    0,   87,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RoboConfig::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RoboConfig *_t = static_cast<RoboConfig *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_saveButton_clicked(); break;
        case 1: _t->on_newButton_clicked(); break;
        case 2: _t->on_deleteButton_clicked(); break;
        case 3: _t->SelecionaRobo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->AtualizaTipo(); break;
        case 5: _t->AtualizaPID(); break;
        case 6: _t->AtualizaCorPri(); break;
        case 7: _t->AtualizaCorSec(); break;
        case 8: _t->AtualizaCorTer(); break;
        case 9: _t->AtualizaEndXBee(); break;
        case 10: _t->AtualizaSetPointVel(); break;
        case 11: _t->AtualizaTrajetoria(); break;
        default: ;
        }
    }
}

const QMetaObject RoboConfig::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_RoboConfig.data,
      qt_meta_data_RoboConfig,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RoboConfig::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RoboConfig::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RoboConfig.stringdata0))
        return static_cast<void*>(const_cast< RoboConfig*>(this));
    return QWidget::qt_metacast(_clname);
}

int RoboConfig::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
