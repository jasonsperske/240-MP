/****************************************************************************
** Meta object code from reading C++ file 'IdleTracker.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/input/IdleTracker.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'IdleTracker.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_IdleTracker_t {
    uint offsetsAndSizes[34];
    char stringdata0[12];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[19];
    char stringdata4[17];
    char stringdata5[15];
    char stringdata6[17];
    char stringdata7[20];
    char stringdata8[17];
    char stringdata9[5];
    char stringdata10[14];
    char stringdata11[7];
    char stringdata12[12];
    char stringdata13[10];
    char stringdata14[8];
    char stringdata15[10];
    char stringdata16[13];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_IdleTracker_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_IdleTracker_t qt_meta_stringdata_IdleTracker = {
    {
        QT_MOC_LITERAL(0, 11),  // "IdleTracker"
        QT_MOC_LITERAL(12, 13),  // "activeChanged"
        QT_MOC_LITERAL(26, 0),  // ""
        QT_MOC_LITERAL(27, 18),  // "idleSecondsChanged"
        QT_MOC_LITERAL(46, 16),  // "thresholdChanged"
        QT_MOC_LITERAL(63, 14),  // "enabledChanged"
        QT_MOC_LITERAL(78, 16),  // "mpvActiveChanged"
        QT_MOC_LITERAL(95, 19),  // "scriptActiveChanged"
        QT_MOC_LITERAL(115, 16),  // "activityDetected"
        QT_MOC_LITERAL(132, 4),  // "tick"
        QT_MOC_LITERAL(137, 13),  // "resetActivity"
        QT_MOC_LITERAL(151, 6),  // "active"
        QT_MOC_LITERAL(158, 11),  // "idleSeconds"
        QT_MOC_LITERAL(170, 9),  // "threshold"
        QT_MOC_LITERAL(180, 7),  // "enabled"
        QT_MOC_LITERAL(188, 9),  // "mpvActive"
        QT_MOC_LITERAL(198, 12)   // "scriptActive"
    },
    "IdleTracker",
    "activeChanged",
    "",
    "idleSecondsChanged",
    "thresholdChanged",
    "enabledChanged",
    "mpvActiveChanged",
    "scriptActiveChanged",
    "activityDetected",
    "tick",
    "resetActivity",
    "active",
    "idleSeconds",
    "threshold",
    "enabled",
    "mpvActive",
    "scriptActive"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_IdleTracker[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       6,   77, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x06,    7 /* Public */,
       3,    0,   69,    2, 0x06,    8 /* Public */,
       4,    0,   70,    2, 0x06,    9 /* Public */,
       5,    0,   71,    2, 0x06,   10 /* Public */,
       6,    0,   72,    2, 0x06,   11 /* Public */,
       7,    0,   73,    2, 0x06,   12 /* Public */,
       8,    0,   74,    2, 0x06,   13 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       9,    0,   75,    2, 0x08,   14 /* Private */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      10,    0,   76,    2, 0x02,   15 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void,

 // properties: name, type, flags
      11, QMetaType::Bool, 0x00015001, uint(0), 0,
      12, QMetaType::Int, 0x00015001, uint(1), 0,
      13, QMetaType::Int, 0x00015103, uint(2), 0,
      14, QMetaType::Bool, 0x00015103, uint(3), 0,
      15, QMetaType::Bool, 0x00015103, uint(4), 0,
      16, QMetaType::Bool, 0x00015103, uint(5), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject IdleTracker::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_IdleTracker.offsetsAndSizes,
    qt_meta_data_IdleTracker,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_IdleTracker_t,
        // property 'active'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'idleSeconds'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'threshold'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'enabled'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'mpvActive'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'scriptActive'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<IdleTracker, std::true_type>,
        // method 'activeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'idleSecondsChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'thresholdChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'enabledChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'mpvActiveChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'scriptActiveChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'activityDetected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'tick'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'resetActivity'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void IdleTracker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<IdleTracker *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->activeChanged(); break;
        case 1: _t->idleSecondsChanged(); break;
        case 2: _t->thresholdChanged(); break;
        case 3: _t->enabledChanged(); break;
        case 4: _t->mpvActiveChanged(); break;
        case 5: _t->scriptActiveChanged(); break;
        case 6: _t->activityDetected(); break;
        case 7: _t->tick(); break;
        case 8: _t->resetActivity(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (IdleTracker::*)();
            if (_t _q_method = &IdleTracker::activeChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (IdleTracker::*)();
            if (_t _q_method = &IdleTracker::idleSecondsChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (IdleTracker::*)();
            if (_t _q_method = &IdleTracker::thresholdChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (IdleTracker::*)();
            if (_t _q_method = &IdleTracker::enabledChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (IdleTracker::*)();
            if (_t _q_method = &IdleTracker::mpvActiveChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (IdleTracker::*)();
            if (_t _q_method = &IdleTracker::scriptActiveChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (IdleTracker::*)();
            if (_t _q_method = &IdleTracker::activityDetected; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
    }else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<IdleTracker *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->isActive(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->idleSeconds(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->threshold(); break;
        case 3: *reinterpret_cast< bool*>(_v) = _t->isEnabled(); break;
        case 4: *reinterpret_cast< bool*>(_v) = _t->isMpvActive(); break;
        case 5: *reinterpret_cast< bool*>(_v) = _t->isScriptActive(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<IdleTracker *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 2: _t->setThreshold(*reinterpret_cast< int*>(_v)); break;
        case 3: _t->setEnabled(*reinterpret_cast< bool*>(_v)); break;
        case 4: _t->setMpvActive(*reinterpret_cast< bool*>(_v)); break;
        case 5: _t->setScriptActive(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
    (void)_a;
}

const QMetaObject *IdleTracker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IdleTracker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_IdleTracker.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int IdleTracker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void IdleTracker::activeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void IdleTracker::idleSecondsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void IdleTracker::thresholdChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void IdleTracker::enabledChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void IdleTracker::mpvActiveChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void IdleTracker::scriptActiveChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void IdleTracker::activityDetected()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
