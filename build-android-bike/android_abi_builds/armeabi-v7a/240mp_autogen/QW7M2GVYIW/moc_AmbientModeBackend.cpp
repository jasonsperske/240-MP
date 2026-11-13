/****************************************************************************
** Meta object code from reading C++ file 'AmbientModeBackend.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../src/modules/ambient_mode/AmbientModeBackend.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AmbientModeBackend.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_AmbientModeBackend_t {
    uint offsetsAndSizes[30];
    char stringdata0[19];
    char stringdata1[17];
    char stringdata2[1];
    char stringdata3[9];
    char stringdata4[4];
    char stringdata5[6];
    char stringdata6[14];
    char stringdata7[14];
    char stringdata8[10];
    char stringdata9[13];
    char stringdata10[5];
    char stringdata11[11];
    char stringdata12[6];
    char stringdata13[8];
    char stringdata14[10];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_AmbientModeBackend_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_AmbientModeBackend_t qt_meta_stringdata_AmbientModeBackend = {
    {
        QT_MOC_LITERAL(0, 18),  // "AmbientModeBackend"
        QT_MOC_LITERAL(19, 16),  // "onSettingChanged"
        QT_MOC_LITERAL(36, 0),  // ""
        QT_MOC_LITERAL(37, 8),  // "moduleId"
        QT_MOC_LITERAL(46, 3),  // "key"
        QT_MOC_LITERAL(50, 5),  // "value"
        QT_MOC_LITERAL(56, 13),  // "getVideoFiles"
        QT_MOC_LITERAL(70, 13),  // "getAudioFiles"
        QT_MOC_LITERAL(84, 9),  // "mediaRoot"
        QT_MOC_LITERAL(94, 12),  // "setMediaRoot"
        QT_MOC_LITERAL(107, 4),  // "path"
        QT_MOC_LITERAL(112, 10),  // "startAudio"
        QT_MOC_LITERAL(123, 5),  // "paths"
        QT_MOC_LITERAL(129, 7),  // "shuffle"
        QT_MOC_LITERAL(137, 9)   // "stopAudio"
    },
    "AmbientModeBackend",
    "onSettingChanged",
    "",
    "moduleId",
    "key",
    "value",
    "getVideoFiles",
    "getAudioFiles",
    "mediaRoot",
    "setMediaRoot",
    "path",
    "startAudio",
    "paths",
    "shuffle",
    "stopAudio"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_AmbientModeBackend[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,   62,    2, 0x0a,    1 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,   69,    2, 0x102,    5 /* Public | MethodIsConst  */,
       7,    0,   70,    2, 0x102,    6 /* Public | MethodIsConst  */,
       8,    0,   71,    2, 0x102,    7 /* Public | MethodIsConst  */,
       9,    1,   72,    2, 0x02,    8 /* Public */,
      11,    2,   75,    2, 0x02,   10 /* Public */,
      11,    1,   80,    2, 0x22,   13 /* Public | MethodCloned */,
      14,    0,   83,    2, 0x02,   15 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QVariant,    3,    4,    5,

 // methods: parameters
    QMetaType::QVariantList,
    QMetaType::QVariantList,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QStringList, QMetaType::Bool,   12,   13,
    QMetaType::Void, QMetaType::QStringList,   12,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject AmbientModeBackend::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_AmbientModeBackend.offsetsAndSizes,
    qt_meta_data_AmbientModeBackend,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_AmbientModeBackend_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<AmbientModeBackend, std::true_type>,
        // method 'onSettingChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariant &, std::false_type>,
        // method 'getVideoFiles'
        QtPrivate::TypeAndForceComplete<QVariantList, std::false_type>,
        // method 'getAudioFiles'
        QtPrivate::TypeAndForceComplete<QVariantList, std::false_type>,
        // method 'mediaRoot'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'setMediaRoot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'startAudio'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'startAudio'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>,
        // method 'stopAudio'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void AmbientModeBackend::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AmbientModeBackend *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onSettingChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[3]))); break;
        case 1: { QVariantList _r = _t->getVideoFiles();
            if (_a[0]) *reinterpret_cast< QVariantList*>(_a[0]) = std::move(_r); }  break;
        case 2: { QVariantList _r = _t->getAudioFiles();
            if (_a[0]) *reinterpret_cast< QVariantList*>(_a[0]) = std::move(_r); }  break;
        case 3: { QString _r = _t->mediaRoot();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->setMediaRoot((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->startAudio((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 6: _t->startAudio((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 7: _t->stopAudio(); break;
        default: ;
        }
    }
}

const QMetaObject *AmbientModeBackend::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AmbientModeBackend::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AmbientModeBackend.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AmbientModeBackend::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
