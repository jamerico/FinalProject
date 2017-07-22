/****************************************************************************
** Meta object code from reading C++ file 'projetofinal.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../projetofinal.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'projetofinal.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ProjetoFinal_t {
    QByteArrayData data[13];
    char stringdata0[327];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ProjetoFinal_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ProjetoFinal_t qt_meta_stringdata_ProjetoFinal = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ProjetoFinal"
QT_MOC_LITERAL(1, 13, 24), // "processFrameAndUpdateGUI"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 22), // "on_startButton_clicked"
QT_MOC_LITERAL(4, 62, 22), // "on_pauseButton_clicked"
QT_MOC_LITERAL(5, 85, 29), // "on_checkShowBlob_stateChanged"
QT_MOC_LITERAL(6, 115, 5), // "state"
QT_MOC_LITERAL(7, 121, 33), // "on_checkShowimageBox_stateCha..."
QT_MOC_LITERAL(8, 155, 32), // "on_checkShowDrawBox_stateChanged"
QT_MOC_LITERAL(9, 188, 42), // "on_actionCalibrar_Filtros_de_..."
QT_MOC_LITERAL(10, 231, 36), // "on_actionCalibrar_Controle_tr..."
QT_MOC_LITERAL(11, 268, 28), // "on_actionNovo_Robo_triggered"
QT_MOC_LITERAL(12, 297, 29) // "on_checkShowTraj_stateChanged"

    },
    "ProjetoFinal\0processFrameAndUpdateGUI\0"
    "\0on_startButton_clicked\0on_pauseButton_clicked\0"
    "on_checkShowBlob_stateChanged\0state\0"
    "on_checkShowimageBox_stateChanged\0"
    "on_checkShowDrawBox_stateChanged\0"
    "on_actionCalibrar_Filtros_de_Cor_triggered\0"
    "on_actionCalibrar_Controle_triggered\0"
    "on_actionNovo_Robo_triggered\0"
    "on_checkShowTraj_stateChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProjetoFinal[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x0a /* Public */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    1,   67,    2, 0x08 /* Private */,
       7,    1,   70,    2, 0x08 /* Private */,
       8,    1,   73,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    0,   78,    2, 0x08 /* Private */,
      12,    1,   79,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,

       0        // eod
};

void ProjetoFinal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ProjetoFinal *_t = static_cast<ProjetoFinal *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->processFrameAndUpdateGUI(); break;
        case 1: _t->on_startButton_clicked(); break;
        case 2: _t->on_pauseButton_clicked(); break;
        case 3: _t->on_checkShowBlob_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_checkShowimageBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_checkShowDrawBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_actionCalibrar_Filtros_de_Cor_triggered(); break;
        case 7: _t->on_actionCalibrar_Controle_triggered(); break;
        case 8: _t->on_actionNovo_Robo_triggered(); break;
        case 9: _t->on_checkShowTraj_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject ProjetoFinal::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ProjetoFinal.data,
      qt_meta_data_ProjetoFinal,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ProjetoFinal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProjetoFinal::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ProjetoFinal.stringdata0))
        return static_cast<void*>(const_cast< ProjetoFinal*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ProjetoFinal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
