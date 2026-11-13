/****************************************************************************
** Meta object code from reading C++ file 'ExerciseBackend.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/modules/exercise/ExerciseBackend.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ExerciseBackend.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_ExerciseBackend_t {
    uint offsetsAndSizes[34];
    char stringdata0[16];
    char stringdata1[15];
    char stringdata2[1];
    char stringdata3[16];
    char stringdata4[15];
    char stringdata5[15];
    char stringdata6[8];
    char stringdata7[11];
    char stringdata8[8];
    char stringdata9[16];
    char stringdata10[6];
    char stringdata11[10];
    char stringdata12[5];
    char stringdata13[7];
    char stringdata14[4];
    char stringdata15[6];
    char stringdata16[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_ExerciseBackend_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_ExerciseBackend_t qt_meta_stringdata_ExerciseBackend = {
    {
        QT_MOC_LITERAL(0, 15),  // "ExerciseBackend"
        QT_MOC_LITERAL(16, 14),  // "readingChanged"
        QT_MOC_LITERAL(31, 0),  // ""
        QT_MOC_LITERAL(32, 15),  // "startMonitoring"
        QT_MOC_LITERAL(48, 14),  // "stopMonitoring"
        QT_MOC_LITERAL(63, 14),  // "previewProgram"
        QT_MOC_LITERAL(78, 7),  // "workout"
        QT_MOC_LITERAL(86, 10),  // "difficulty"
        QT_MOC_LITERAL(97, 7),  // "minutes"
        QT_MOC_LITERAL(105, 15),  // "openDiagnostics"
        QT_MOC_LITERAL(121, 5),  // "state"
        QT_MOC_LITERAL(127, 9),  // "connected"
        QT_MOC_LITERAL(137, 4),  // "live"
        QT_MOC_LITERAL(142, 6),  // "absent"
        QT_MOC_LITERAL(149, 3),  // "rpm"
        QT_MOC_LITERAL(153, 5),  // "watts"
        QT_MOC_LITERAL(159, 10)   // "resistance"
    },
    "ExerciseBackend",
    "readingChanged",
    "",
    "startMonitoring",
    "stopMonitoring",
    "previewProgram",
    "workout",
    "difficulty",
    "minutes",
    "openDiagnostics",
    "state",
    "connected",
    "live",
    "absent",
    "rpm",
    "watts",
    "resistance"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_ExerciseBackend[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       7,   55, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x06,    8 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   45,    2, 0x02,    9 /* Public */,
       4,    0,   46,    2, 0x02,   10 /* Public */,
       5,    3,   47,    2, 0x102,   11 /* Public | MethodIsConst  */,
       9,    0,   54,    2, 0x02,   15 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QVariantMap, QMetaType::QString, QMetaType::QString, QMetaType::Int,    6,    7,    8,
    QMetaType::Void,

 // properties: name, type, flags
      10, QMetaType::QString, 0x00015001, uint(0), 0,
      11, QMetaType::Bool, 0x00015001, uint(0), 0,
      12, QMetaType::Bool, 0x00015001, uint(0), 0,
      13, QMetaType::Bool, 0x00015001, uint(0), 0,
      14, QMetaType::Int, 0x00015001, uint(0), 0,
      15, QMetaType::Int, 0x00015001, uint(0), 0,
      16, QMetaType::Int, 0x00015001, uint(0), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject ExerciseBackend::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ExerciseBackend.offsetsAndSizes,
    qt_meta_data_ExerciseBackend,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_ExerciseBackend_t,
        // property 'state'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'connected'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'live'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'absent'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'rpm'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'watts'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'resistance'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ExerciseBackend, std::true_type>,
        // method 'readingChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'startMonitoring'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'stopMonitoring'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'previewProgram'
        QtPrivate::TypeAndForceComplete<QVariantMap, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'openDiagnostics'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void ExerciseBackend::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ExerciseBackend *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->readingChanged(); break;
        case 1: _t->startMonitoring(); break;
        case 2: _t->stopMonitoring(); break;
        case 3: { QVariantMap _r = _t->previewProgram((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])));
            if (_a[0]) *reinterpret_cast< QVariantMap*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->openDiagnostics(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ExerciseBackend::*)();
            if (_t _q_method = &ExerciseBackend::readingChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<ExerciseBackend *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->state(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->connected(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->live(); break;
        case 3: *reinterpret_cast< bool*>(_v) = _t->absent(); break;
        case 4: *reinterpret_cast< int*>(_v) = _t->rpm(); break;
        case 5: *reinterpret_cast< int*>(_v) = _t->watts(); break;
        case 6: *reinterpret_cast< int*>(_v) = _t->resistance(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *ExerciseBackend::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ExerciseBackend::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ExerciseBackend.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ExerciseBackend::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void ExerciseBackend::readingChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
