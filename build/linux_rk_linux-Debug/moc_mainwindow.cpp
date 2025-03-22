/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[23];
    char stringdata0[420];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 17), // "onGetProtocolData"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 12), // "VCI_CAN_OBJ*"
QT_MOC_LITERAL(4, 43, 3), // "vci"
QT_MOC_LITERAL(5, 47, 5), // "dwRel"
QT_MOC_LITERAL(6, 53, 7), // "channel"
QT_MOC_LITERAL(7, 61, 11), // "onBoardInfo"
QT_MOC_LITERAL(8, 73, 14), // "VCI_BOARD_INFO"
QT_MOC_LITERAL(9, 88, 3), // "vbi"
QT_MOC_LITERAL(10, 92, 36), // "on_motor_comboBox_currentText..."
QT_MOC_LITERAL(11, 129, 4), // "arg1"
QT_MOC_LITERAL(12, 134, 18), // "on_forward_clicked"
QT_MOC_LITERAL(13, 153, 18), // "on_reverse_clicked"
QT_MOC_LITERAL(14, 172, 27), // "on_run_your_scripts_clicked"
QT_MOC_LITERAL(15, 200, 32), // "on_pro_debug_open_USBCAN_clicked"
QT_MOC_LITERAL(16, 233, 25), // "on_pro_debug_send_clicked"
QT_MOC_LITERAL(17, 259, 29), // "on_pro_debug_init_CAN_clicked"
QT_MOC_LITERAL(18, 289, 30), // "on_pro_debug_start_CAN_clicked"
QT_MOC_LITERAL(19, 320, 26), // "on_pro_debug_reset_clicked"
QT_MOC_LITERAL(20, 347, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(21, 369, 25), // "on_test_pwm_start_clicked"
QT_MOC_LITERAL(22, 395, 24) // "on_test_pwm_stop_clicked"

    },
    "MainWindow\0onGetProtocolData\0\0"
    "VCI_CAN_OBJ*\0vci\0dwRel\0channel\0"
    "onBoardInfo\0VCI_BOARD_INFO\0vbi\0"
    "on_motor_comboBox_currentTextChanged\0"
    "arg1\0on_forward_clicked\0on_reverse_clicked\0"
    "on_run_your_scripts_clicked\0"
    "on_pro_debug_open_USBCAN_clicked\0"
    "on_pro_debug_send_clicked\0"
    "on_pro_debug_init_CAN_clicked\0"
    "on_pro_debug_start_CAN_clicked\0"
    "on_pro_debug_reset_clicked\0"
    "on_pushButton_clicked\0on_test_pwm_start_clicked\0"
    "on_test_pwm_stop_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   84,    2, 0x0a /* Public */,
       7,    1,   91,    2, 0x0a /* Public */,
      10,    1,   94,    2, 0x08 /* Private */,
      12,    0,   97,    2, 0x08 /* Private */,
      13,    0,   98,    2, 0x08 /* Private */,
      14,    0,   99,    2, 0x08 /* Private */,
      15,    0,  100,    2, 0x08 /* Private */,
      16,    0,  101,    2, 0x08 /* Private */,
      17,    0,  102,    2, 0x08 /* Private */,
      18,    0,  103,    2, 0x08 /* Private */,
      19,    0,  104,    2, 0x08 /* Private */,
      20,    0,  105,    2, 0x08 /* Private */,
      21,    0,  106,    2, 0x08 /* Private */,
      22,    0,  107,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::UInt, QMetaType::UInt,    4,    5,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
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

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onGetProtocolData((*reinterpret_cast< VCI_CAN_OBJ*(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3]))); break;
        case 1: _t->onBoardInfo((*reinterpret_cast< VCI_BOARD_INFO(*)>(_a[1]))); break;
        case 2: _t->on_motor_comboBox_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_forward_clicked(); break;
        case 4: _t->on_reverse_clicked(); break;
        case 5: _t->on_run_your_scripts_clicked(); break;
        case 6: _t->on_pro_debug_open_USBCAN_clicked(); break;
        case 7: _t->on_pro_debug_send_clicked(); break;
        case 8: _t->on_pro_debug_init_CAN_clicked(); break;
        case 9: _t->on_pro_debug_start_CAN_clicked(); break;
        case 10: _t->on_pro_debug_reset_clicked(); break;
        case 11: _t->on_pushButton_clicked(); break;
        case 12: _t->on_test_pwm_start_clicked(); break;
        case 13: _t->on_test_pwm_stop_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
