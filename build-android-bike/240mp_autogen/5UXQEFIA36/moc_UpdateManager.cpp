/****************************************************************************
** Meta object code from reading C++ file 'UpdateManager.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/update/UpdateManager.h"
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UpdateManager.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_UpdateManager_t {
    uint offsetsAndSizes[36];
    char stringdata0[14];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[16];
    char stringdata5[16];
    char stringdata6[9];
    char stringdata7[15];
    char stringdata8[16];
    char stringdata9[20];
    char stringdata10[6];
    char stringdata11[15];
    char stringdata12[14];
    char stringdata13[13];
    char stringdata14[17];
    char stringdata15[13];
    char stringdata16[9];
    char stringdata17[10];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_UpdateManager_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_UpdateManager_t qt_meta_stringdata_UpdateManager = {
    {
        QT_MOC_LITERAL(0, 13),  // "UpdateManager"
        QT_MOC_LITERAL(14, 12),  // "stateChanged"
        QT_MOC_LITERAL(27, 0),  // ""
        QT_MOC_LITERAL(28, 11),  // "infoChanged"
        QT_MOC_LITERAL(40, 15),  // "progressChanged"
        QT_MOC_LITERAL(56, 15),  // "checkForUpdates"
        QT_MOC_LITERAL(72, 8),  // "download"
        QT_MOC_LITERAL(81, 14),  // "cancelDownload"
        QT_MOC_LITERAL(96, 15),  // "applyAndRestart"
        QT_MOC_LITERAL(112, 19),  // "discardStagedUpdate"
        QT_MOC_LITERAL(132, 5),  // "state"
        QT_MOC_LITERAL(138, 14),  // "currentVersion"
        QT_MOC_LITERAL(153, 13),  // "latestVersion"
        QT_MOC_LITERAL(167, 12),  // "releaseNotes"
        QT_MOC_LITERAL(180, 16),  // "downloadProgress"
        QT_MOC_LITERAL(197, 12),  // "errorMessage"
        QT_MOC_LITERAL(210, 8),  // "canApply"
        QT_MOC_LITERAL(219, 9)   // "applyHint"
    },
    "UpdateManager",
    "stateChanged",
    "",
    "infoChanged",
    "progressChanged",
    "checkForUpdates",
    "download",
    "cancelDownload",
    "applyAndRestart",
    "discardStagedUpdate",
    "state",
    "currentVersion",
    "latestVersion",
    "releaseNotes",
    "downloadProgress",
    "errorMessage",
    "canApply",
    "applyHint"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_UpdateManager[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       8,   70, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x06,    9 /* Public */,
       3,    0,   63,    2, 0x06,   10 /* Public */,
       4,    0,   64,    2, 0x06,   11 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,   65,    2, 0x02,   12 /* Public */,
       6,    0,   66,    2, 0x02,   13 /* Public */,
       7,    0,   67,    2, 0x02,   14 /* Public */,
       8,    0,   68,    2, 0x02,   15 /* Public */,
       9,    0,   69,    2, 0x02,   16 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      10, QMetaType::QString, 0x00015001, uint(0), 0,
      11, QMetaType::QString, 0x00015401, uint(-1), 0,
      12, QMetaType::QString, 0x00015001, uint(1), 0,
      13, QMetaType::QString, 0x00015001, uint(1), 0,
      14, QMetaType::QReal, 0x00015001, uint(2), 0,
      15, QMetaType::QString, 0x00015001, uint(0), 0,
      16, QMetaType::Bool, 0x00015401, uint(-1), 0,
      17, QMetaType::QString, 0x00015401, uint(-1), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject UpdateManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_UpdateManager.offsetsAndSizes,
    qt_meta_data_UpdateManager,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_UpdateManager_t,
        // property 'state'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'currentVersion'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'latestVersion'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'releaseNotes'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'downloadProgress'
        QtPrivate::TypeAndForceComplete<qreal, std::true_type>,
        // property 'errorMessage'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'canApply'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'applyHint'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<UpdateManager, std::true_type>,
        // method 'stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'infoChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'progressChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'checkForUpdates'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'download'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'cancelDownload'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'applyAndRestart'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'discardStagedUpdate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void UpdateManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UpdateManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->stateChanged(); break;
        case 1: _t->infoChanged(); break;
        case 2: _t->progressChanged(); break;
        case 3: _t->checkForUpdates(); break;
        case 4: _t->download(); break;
        case 5: _t->cancelDownload(); break;
        case 6: _t->applyAndRestart(); break;
        case 7: _t->discardStagedUpdate(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (UpdateManager::*)();
            if (_t _q_method = &UpdateManager::stateChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (UpdateManager::*)();
            if (_t _q_method = &UpdateManager::infoChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (UpdateManager::*)();
            if (_t _q_method = &UpdateManager::progressChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<UpdateManager *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->state(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->currentVersion(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->latestVersion(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->releaseNotes(); break;
        case 4: *reinterpret_cast< qreal*>(_v) = _t->downloadProgress(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->errorMessage(); break;
        case 6: *reinterpret_cast< bool*>(_v) = _t->canApply(); break;
        case 7: *reinterpret_cast< QString*>(_v) = _t->applyHint(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
    (void)_a;
}

const QMetaObject *UpdateManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UpdateManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UpdateManager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int UpdateManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void UpdateManager::stateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void UpdateManager::infoChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void UpdateManager::progressChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
