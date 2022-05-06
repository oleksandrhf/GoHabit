/****************************************************************************
** Meta object code from reading C++ file 'reg_window.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../log/reg_window.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'reg_window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_reg_window_t {
    const uint offsetsAndSize[18];
    char stringdata0[188];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_reg_window_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_reg_window_t qt_meta_stringdata_reg_window = {
    {
QT_MOC_LITERAL(0, 10), // "reg_window"
QT_MOC_LITERAL(11, 24), // "register_button_clicked2"
QT_MOC_LITERAL(36, 0), // ""
QT_MOC_LITERAL(37, 26), // "on_nameLineEdit_textEdited"
QT_MOC_LITERAL(64, 4), // "arg1"
QT_MOC_LITERAL(69, 30), // "on_passwordLineEdit_textEdited"
QT_MOC_LITERAL(100, 29), // "on_confirmLineEdit_textEdited"
QT_MOC_LITERAL(130, 29), // "on_registerPushButton_clicked"
QT_MOC_LITERAL(160, 27) // "on_LoginlineEdit_textEdited"

    },
    "reg_window\0register_button_clicked2\0"
    "\0on_nameLineEdit_textEdited\0arg1\0"
    "on_passwordLineEdit_textEdited\0"
    "on_confirmLineEdit_textEdited\0"
    "on_registerPushButton_clicked\0"
    "on_LoginlineEdit_textEdited"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_reg_window[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    1,   51,    2, 0x08,    2 /* Private */,
       5,    1,   54,    2, 0x08,    4 /* Private */,
       6,    1,   57,    2, 0x08,    6 /* Private */,
       7,    0,   60,    2, 0x08,    8 /* Private */,
       8,    1,   61,    2, 0x08,    9 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,

       0        // eod
};

void reg_window::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<reg_window *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->register_button_clicked2(); break;
        case 1: _t->on_nameLineEdit_textEdited((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->on_passwordLineEdit_textEdited((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->on_confirmLineEdit_textEdited((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->on_registerPushButton_clicked(); break;
        case 5: _t->on_LoginlineEdit_textEdited((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (reg_window::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&reg_window::register_button_clicked2)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject reg_window::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_reg_window.offsetsAndSize,
    qt_meta_data_reg_window,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_reg_window_t
, QtPrivate::TypeAndForceComplete<reg_window, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>


>,
    nullptr
} };


const QMetaObject *reg_window::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *reg_window::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_reg_window.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int reg_window::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void reg_window::register_button_clicked2()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
