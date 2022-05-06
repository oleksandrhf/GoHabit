/****************************************************************************
** Meta object code from reading C++ file 'auth_window.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../log/auth_window.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'auth_window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_auth_window_t {
    const uint offsetsAndSize[18];
    char stringdata0[172];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_auth_window_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_auth_window_t qt_meta_stringdata_auth_window = {
    {
QT_MOC_LITERAL(0, 11), // "auth_window"
QT_MOC_LITERAL(12, 20), // "login_button_clicked"
QT_MOC_LITERAL(33, 0), // ""
QT_MOC_LITERAL(34, 23), // "register_button_clicked"
QT_MOC_LITERAL(58, 32), // "on_register_pushButton_2_clicked"
QT_MOC_LITERAL(91, 27), // "on_login_PushButton_clicked"
QT_MOC_LITERAL(119, 22), // "on_lineEdit_textEdited"
QT_MOC_LITERAL(142, 4), // "arg1"
QT_MOC_LITERAL(147, 24) // "on_lineEdit_2_textEdited"

    },
    "auth_window\0login_button_clicked\0\0"
    "register_button_clicked\0"
    "on_register_pushButton_2_clicked\0"
    "on_login_PushButton_clicked\0"
    "on_lineEdit_textEdited\0arg1\0"
    "on_lineEdit_2_textEdited"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_auth_window[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x06,    1 /* Public */,
       3,    0,   51,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   52,    2, 0x08,    3 /* Private */,
       5,    0,   53,    2, 0x08,    4 /* Private */,
       6,    1,   54,    2, 0x08,    5 /* Private */,
       8,    1,   57,    2, 0x08,    7 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,

       0        // eod
};

void auth_window::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<auth_window *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->login_button_clicked(); break;
        case 1: _t->register_button_clicked(); break;
        case 2: _t->on_register_pushButton_2_clicked(); break;
        case 3: _t->on_login_PushButton_clicked(); break;
        case 4: _t->on_lineEdit_textEdited((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->on_lineEdit_2_textEdited((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (auth_window::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&auth_window::login_button_clicked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (auth_window::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&auth_window::register_button_clicked)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject auth_window::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_auth_window.offsetsAndSize,
    qt_meta_data_auth_window,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_auth_window_t
, QtPrivate::TypeAndForceComplete<auth_window, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>


>,
    nullptr
} };


const QMetaObject *auth_window::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *auth_window::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_auth_window.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int auth_window::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void auth_window::login_button_clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void auth_window::register_button_clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
