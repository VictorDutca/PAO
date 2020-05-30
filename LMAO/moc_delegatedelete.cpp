/****************************************************************************
** Meta object code from reading C++ file 'delegatedelete.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MODEL/delegatedelete.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'delegatedelete.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DelegateDelete_t {
    QByteArrayData data[5];
    char stringdata0[51];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DelegateDelete_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DelegateDelete_t qt_meta_stringdata_DelegateDelete = {
    {
QT_MOC_LITERAL(0, 0, 14), // "DelegateDelete"
QT_MOC_LITERAL(1, 15, 11), // "AlertDelete"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 11), // "ModelDelete"
QT_MOC_LITERAL(4, 40, 10) // "DeleteSlot"

    },
    "DelegateDelete\0AlertDelete\0\0ModelDelete\0"
    "DeleteSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DelegateDelete[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       3,    1,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void DelegateDelete::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DelegateDelete *_t = static_cast<DelegateDelete *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->AlertDelete((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->ModelDelete((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->DeleteSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (DelegateDelete::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DelegateDelete::AlertDelete)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (DelegateDelete::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DelegateDelete::ModelDelete)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject DelegateDelete::staticMetaObject = {
    { &DelegateButton::staticMetaObject, qt_meta_stringdata_DelegateDelete.data,
      qt_meta_data_DelegateDelete,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DelegateDelete::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DelegateDelete::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DelegateDelete.stringdata0))
        return static_cast<void*>(this);
    return DelegateButton::qt_metacast(_clname);
}

int DelegateDelete::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DelegateButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void DelegateDelete::AlertDelete(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DelegateDelete::ModelDelete(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
