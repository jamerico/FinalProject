/****************************************************************************
** Meta object code from reading C++ file 'pidcalib.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../pidcalib.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pidcalib.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PIDCalib_t {
    QByteArrayData data[23];
    char stringdata0[371];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PIDCalib_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PIDCalib_t qt_meta_stringdata_PIDCalib = {
    {
QT_MOC_LITERAL(0, 0, 8), // "PIDCalib"
QT_MOC_LITERAL(1, 9, 21), // "on_saveButton_clicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 25), // "on_newRobotButton_clicked"
QT_MOC_LITERAL(4, 58, 23), // "on_newPIDButton_clicked"
QT_MOC_LITERAL(5, 82, 26), // "on_startTestButton_clicked"
QT_MOC_LITERAL(6, 109, 25), // "on_stopTestButton_clicked"
QT_MOC_LITERAL(7, 135, 13), // "selecionaRobo"
QT_MOC_LITERAL(8, 149, 12), // "selecionaPID"
QT_MOC_LITERAL(9, 162, 19), // "selecionaTrajetoria"
QT_MOC_LITERAL(10, 182, 15), // "atualizaPeriodo"
QT_MOC_LITERAL(11, 198, 12), // "atualizaRaio"
QT_MOC_LITERAL(12, 211, 15), // "atualizaSentido"
QT_MOC_LITERAL(13, 227, 10), // "atualizaPL"
QT_MOC_LITERAL(14, 238, 10), // "atualizaDL"
QT_MOC_LITERAL(15, 249, 10), // "atualizaIL"
QT_MOC_LITERAL(16, 260, 10), // "atualizaPA"
QT_MOC_LITERAL(17, 271, 10), // "atualizaDA"
QT_MOC_LITERAL(18, 282, 10), // "atualizaIA"
QT_MOC_LITERAL(19, 293, 21), // "atualizaParamControle"
QT_MOC_LITERAL(20, 315, 16), // "atualizaSetPoint"
QT_MOC_LITERAL(21, 332, 12), // "mousePressed"
QT_MOC_LITERAL(22, 345, 25) // "desabiltarParametrosTeste"

    },
    "PIDCalib\0on_saveButton_clicked\0\0"
    "on_newRobotButton_clicked\0"
    "on_newPIDButton_clicked\0"
    "on_startTestButton_clicked\0"
    "on_stopTestButton_clicked\0selecionaRobo\0"
    "selecionaPID\0selecionaTrajetoria\0"
    "atualizaPeriodo\0atualizaRaio\0"
    "atualizaSentido\0atualizaPL\0atualizaDL\0"
    "atualizaIL\0atualizaPA\0atualizaDA\0"
    "atualizaIA\0atualizaParamControle\0"
    "atualizaSetPoint\0mousePressed\0"
    "desabiltarParametrosTeste"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PIDCalib[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  119,    2, 0x08 /* Private */,
       3,    0,  120,    2, 0x08 /* Private */,
       4,    0,  121,    2, 0x08 /* Private */,
       5,    0,  122,    2, 0x08 /* Private */,
       6,    0,  123,    2, 0x08 /* Private */,
       7,    2,  124,    2, 0x08 /* Private */,
       8,    1,  129,    2, 0x08 /* Private */,
       9,    1,  132,    2, 0x08 /* Private */,
      10,    1,  135,    2, 0x08 /* Private */,
      11,    1,  138,    2, 0x08 /* Private */,
      12,    1,  141,    2, 0x08 /* Private */,
      13,    1,  144,    2, 0x08 /* Private */,
      14,    1,  147,    2, 0x08 /* Private */,
      15,    1,  150,    2, 0x08 /* Private */,
      16,    1,  153,    2, 0x08 /* Private */,
      17,    1,  156,    2, 0x08 /* Private */,
      18,    1,  159,    2, 0x08 /* Private */,
      19,    0,  162,    2, 0x08 /* Private */,
      20,    0,  163,    2, 0x08 /* Private */,
      21,    0,  164,    2, 0x08 /* Private */,
      22,    1,  165,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void PIDCalib::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PIDCalib *_t = static_cast<PIDCalib *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_saveButton_clicked(); break;
        case 1: _t->on_newRobotButton_clicked(); break;
        case 2: _t->on_newPIDButton_clicked(); break;
        case 3: _t->on_startTestButton_clicked(); break;
        case 4: _t->on_stopTestButton_clicked(); break;
        case 5: _t->selecionaRobo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->selecionaPID((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->selecionaTrajetoria((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->atualizaPeriodo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->atualizaRaio((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->atualizaSentido((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->atualizaPL((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 12: _t->atualizaDL((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 13: _t->atualizaIL((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 14: _t->atualizaPA((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 15: _t->atualizaDA((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 16: _t->atualizaIA((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 17: _t->atualizaParamControle(); break;
        case 18: _t->atualizaSetPoint(); break;
        case 19: _t->mousePressed(); break;
        case 20: _t->desabiltarParametrosTeste((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject PIDCalib::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PIDCalib.data,
      qt_meta_data_PIDCalib,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PIDCalib::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PIDCalib::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PIDCalib.stringdata0))
        return static_cast<void*>(const_cast< PIDCalib*>(this));
    return QWidget::qt_metacast(_clname);
}

int PIDCalib::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 21;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
