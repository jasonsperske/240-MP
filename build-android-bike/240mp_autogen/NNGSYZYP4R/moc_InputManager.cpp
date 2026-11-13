/****************************************************************************
** Meta object code from reading C++ file 'InputManager.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/input/InputManager.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'InputManager.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_InputManager_t {
    uint offsetsAndSizes[50];
    char stringdata0[13];
    char stringdata1[24];
    char stringdata2[1];
    char stringdata3[23];
    char stringdata4[13];
    char stringdata5[16];
    char stringdata6[4];
    char stringdata7[17];
    char stringdata8[14];
    char stringdata9[8];
    char stringdata10[21];
    char stringdata11[13];
    char stringdata12[17];
    char stringdata13[5];
    char stringdata14[20];
    char stringdata15[6];
    char stringdata16[26];
    char stringdata17[15];
    char stringdata18[6];
    char stringdata19[16];
    char stringdata20[7];
    char stringdata21[7];
    char stringdata22[17];
    char stringdata23[16];
    char stringdata24[6];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_InputManager_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_InputManager_t qt_meta_stringdata_InputManager = {
    {
        QT_MOC_LITERAL(0, 12),  // "InputManager"
        QT_MOC_LITERAL(13, 23),  // "gamepadConnectedChanged"
        QT_MOC_LITERAL(37, 0),  // ""
        QT_MOC_LITERAL(38, 22),  // "lastInputDeviceChanged"
        QT_MOC_LITERAL(61, 12),  // "hintsChanged"
        QT_MOC_LITERAL(74, 15),  // "mpvKeyRequested"
        QT_MOC_LITERAL(90, 3),  // "key"
        QT_MOC_LITERAL(94, 16),  // "auxButtonPressed"
        QT_MOC_LITERAL(111, 13),  // "extendedKeyId"
        QT_MOC_LITERAL(125, 7),  // "pollSdl"
        QT_MOC_LITERAL(133, 20),  // "onRepeatDelayElapsed"
        QT_MOC_LITERAL(154, 12),  // "onRepeatTick"
        QT_MOC_LITERAL(167, 16),  // "onDataDirChanged"
        QT_MOC_LITERAL(184, 4),  // "path"
        QT_MOC_LITERAL(189, 19),  // "onAppSettingChanged"
        QT_MOC_LITERAL(209, 5),  // "value"
        QT_MOC_LITERAL(215, 25),  // "onConsumerControlReadable"
        QT_MOC_LITERAL(241, 14),  // "keyDisplayName"
        QT_MOC_LITERAL(256, 5),  // "qtKey"
        QT_MOC_LITERAL(262, 15),  // "setRemapCapture"
        QT_MOC_LITERAL(278, 6),  // "active"
        QT_MOC_LITERAL(285, 6),  // "tapKey"
        QT_MOC_LITERAL(292, 16),  // "gamepadConnected"
        QT_MOC_LITERAL(309, 15),  // "lastInputDevice"
        QT_MOC_LITERAL(325, 5)   // "hints"
    },
    "InputManager",
    "gamepadConnectedChanged",
    "",
    "lastInputDeviceChanged",
    "hintsChanged",
    "mpvKeyRequested",
    "key",
    "auxButtonPressed",
    "extendedKeyId",
    "pollSdl",
    "onRepeatDelayElapsed",
    "onRepeatTick",
    "onDataDirChanged",
    "path",
    "onAppSettingChanged",
    "value",
    "onConsumerControlReadable",
    "keyDisplayName",
    "qtKey",
    "setRemapCapture",
    "active",
    "tapKey",
    "gamepadConnected",
    "lastInputDevice",
    "hints"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_InputManager[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       3,  128, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   98,    2, 0x06,    4 /* Public */,
       3,    0,   99,    2, 0x06,    5 /* Public */,
       4,    0,  100,    2, 0x06,    6 /* Public */,
       5,    1,  101,    2, 0x06,    7 /* Public */,
       7,    1,  104,    2, 0x06,    9 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       9,    0,  107,    2, 0x08,   11 /* Private */,
      10,    0,  108,    2, 0x08,   12 /* Private */,
      11,    0,  109,    2, 0x08,   13 /* Private */,
      12,    1,  110,    2, 0x08,   14 /* Private */,
      14,    2,  113,    2, 0x08,   16 /* Private */,
      16,    0,  118,    2, 0x08,   19 /* Private */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      17,    1,  119,    2, 0x102,   20 /* Public | MethodIsConst  */,
      19,    1,  122,    2, 0x02,   22 /* Public */,
      21,    1,  125,    2, 0x02,   24 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::Int,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,   15,
    QMetaType::Void,

 // methods: parameters
    QMetaType::QString, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Bool,   20,
    QMetaType::Void, QMetaType::Int,   18,

 // properties: name, type, flags
      22, QMetaType::Bool, 0x00015001, uint(0), 0,
      23, QMetaType::QString, 0x00015001, uint(1), 0,
      24, QMetaType::QVariantMap, 0x00015001, uint(2), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject InputManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_InputManager.offsetsAndSizes,
    qt_meta_data_InputManager,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_InputManager_t,
        // property 'gamepadConnected'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'lastInputDevice'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'hints'
        QtPrivate::TypeAndForceComplete<QVariantMap, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<InputManager, std::true_type>,
        // method 'gamepadConnectedChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'lastInputDeviceChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'hintsChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'mpvKeyRequested'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'auxButtonPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'pollSdl'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onRepeatDelayElapsed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onRepeatTick'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onDataDirChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'onAppSettingChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'onConsumerControlReadable'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'keyDisplayName'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setRemapCapture'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'tapKey'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void InputManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<InputManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->gamepadConnectedChanged(); break;
        case 1: _t->lastInputDeviceChanged(); break;
        case 2: _t->hintsChanged(); break;
        case 3: _t->mpvKeyRequested((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->auxButtonPressed((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->pollSdl(); break;
        case 6: _t->onRepeatDelayElapsed(); break;
        case 7: _t->onRepeatTick(); break;
        case 8: _t->onDataDirChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 9: _t->onAppSettingChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 10: _t->onConsumerControlReadable(); break;
        case 11: { QString _r = _t->keyDisplayName((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 12: _t->setRemapCapture((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 13: _t->tapKey((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (InputManager::*)();
            if (_t _q_method = &InputManager::gamepadConnectedChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (InputManager::*)();
            if (_t _q_method = &InputManager::lastInputDeviceChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (InputManager::*)();
            if (_t _q_method = &InputManager::hintsChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (InputManager::*)(const QString & );
            if (_t _q_method = &InputManager::mpvKeyRequested; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (InputManager::*)(int );
            if (_t _q_method = &InputManager::auxButtonPressed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
    }else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<InputManager *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->gamepadConnected(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->lastInputDevice(); break;
        case 2: *reinterpret_cast< QVariantMap*>(_v) = _t->hints(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *InputManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *InputManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_InputManager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int InputManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void InputManager::gamepadConnectedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void InputManager::lastInputDeviceChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void InputManager::hintsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void InputManager::mpvKeyRequested(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void InputManager::auxButtonPressed(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
