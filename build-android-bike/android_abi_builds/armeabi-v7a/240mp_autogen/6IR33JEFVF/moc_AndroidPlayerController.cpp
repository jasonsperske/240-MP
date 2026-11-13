/****************************************************************************
** Meta object code from reading C++ file 'AndroidPlayerController.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../src/player/AndroidPlayerController.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AndroidPlayerController.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_AndroidPlayerController_t {
    uint offsetsAndSizes[90];
    char stringdata0[24];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[3];
    char stringdata4[16];
    char stringdata5[19];
    char stringdata6[4];
    char stringdata7[14];
    char stringdata8[16];
    char stringdata9[16];
    char stringdata10[7];
    char stringdata11[14];
    char stringdata12[23];
    char stringdata13[20];
    char stringdata14[12];
    char stringdata15[4];
    char stringdata16[13];
    char stringdata17[11];
    char stringdata18[9];
    char stringdata19[9];
    char stringdata20[9];
    char stringdata21[5];
    char stringdata22[14];
    char stringdata23[19];
    char stringdata24[10];
    char stringdata25[10];
    char stringdata26[8];
    char stringdata27[8];
    char stringdata28[10];
    char stringdata29[17];
    char stringdata30[13];
    char stringdata31[10];
    char stringdata32[14];
    char stringdata33[10];
    char stringdata34[5];
    char stringdata35[7];
    char stringdata36[11];
    char stringdata37[8];
    char stringdata38[4];
    char stringdata39[18];
    char stringdata40[15];
    char stringdata41[26];
    char stringdata42[9];
    char stringdata43[9];
    char stringdata44[12];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_AndroidPlayerController_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_AndroidPlayerController_t qt_meta_stringdata_AndroidPlayerController = {
    {
        QT_MOC_LITERAL(0, 23),  // "AndroidPlayerController"
        QT_MOC_LITERAL(24, 15),  // "positionChanged"
        QT_MOC_LITERAL(40, 0),  // ""
        QT_MOC_LITERAL(41, 2),  // "ms"
        QT_MOC_LITERAL(44, 15),  // "durationChanged"
        QT_MOC_LITERAL(60, 18),  // "playlistPosChanged"
        QT_MOC_LITERAL(79, 3),  // "pos"
        QT_MOC_LITERAL(83, 13),  // "playbackEnded"
        QT_MOC_LITERAL(97, 15),  // "finalPositionMs"
        QT_MOC_LITERAL(113, 15),  // "finalDurationMs"
        QT_MOC_LITERAL(129, 6),  // "reason"
        QT_MOC_LITERAL(136, 13),  // "skipRequested"
        QT_MOC_LITERAL(150, 22),  // "subtitleCycleRequested"
        QT_MOC_LITERAL(173, 19),  // "audioCycleRequested"
        QT_MOC_LITERAL(193, 11),  // "loadAndPlay"
        QT_MOC_LITERAL(205, 3),  // "url"
        QT_MOC_LITERAL(209, 12),  // "startSeconds"
        QT_MOC_LITERAL(222, 10),  // "audioTrack"
        QT_MOC_LITERAL(233, 8),  // "subTrack"
        QT_MOC_LITERAL(242, 8),  // "subFiles"
        QT_MOC_LITERAL(251, 8),  // "subLangs"
        QT_MOC_LITERAL(260, 4),  // "loop"
        QT_MOC_LITERAL(265, 13),  // "playlistStart"
        QT_MOC_LITERAL(279, 18),  // "transcodeOffsetSec"
        QT_MOC_LITERAL(298, 9),  // "plexToken"
        QT_MOC_LITERAL(308, 9),  // "muteAudio"
        QT_MOC_LITERAL(318, 7),  // "oscMode"
        QT_MOC_LITERAL(326, 7),  // "shuffle"
        QT_MOC_LITERAL(334, 9),  // "subTitles"
        QT_MOC_LITERAL(344, 16),  // "imageDurationSec"
        QT_MOC_LITERAL(361, 12),  // "imageContent"
        QT_MOC_LITERAL(374, 9),  // "extraArgs"
        QT_MOC_LITERAL(384, 13),  // "jellyfinToken"
        QT_MOC_LITERAL(398, 9),  // "extraUrls"
        QT_MOC_LITERAL(408, 4),  // "stop"
        QT_MOC_LITERAL(413, 6),  // "seekTo"
        QT_MOC_LITERAL(420, 10),  // "positionMs"
        QT_MOC_LITERAL(431, 7),  // "sendKey"
        QT_MOC_LITERAL(439, 3),  // "key"
        QT_MOC_LITERAL(443, 17),  // "showOsdSkipPrompt"
        QT_MOC_LITERAL(461, 14),  // "clearOsdPrompt"
        QT_MOC_LITERAL(476, 25),  // "hasSmoothPlaybackTradeoff"
        QT_MOC_LITERAL(502, 8),  // "position"
        QT_MOC_LITERAL(511, 8),  // "duration"
        QT_MOC_LITERAL(520, 11)   // "playlistPos"
    },
    "AndroidPlayerController",
    "positionChanged",
    "",
    "ms",
    "durationChanged",
    "playlistPosChanged",
    "pos",
    "playbackEnded",
    "finalPositionMs",
    "finalDurationMs",
    "reason",
    "skipRequested",
    "subtitleCycleRequested",
    "audioCycleRequested",
    "loadAndPlay",
    "url",
    "startSeconds",
    "audioTrack",
    "subTrack",
    "subFiles",
    "subLangs",
    "loop",
    "playlistStart",
    "transcodeOffsetSec",
    "plexToken",
    "muteAudio",
    "oscMode",
    "shuffle",
    "subTitles",
    "imageDurationSec",
    "imageContent",
    "extraArgs",
    "jellyfinToken",
    "extraUrls",
    "stop",
    "seekTo",
    "positionMs",
    "sendKey",
    "key",
    "showOsdSkipPrompt",
    "clearOsdPrompt",
    "hasSmoothPlaybackTradeoff",
    "position",
    "duration",
    "playlistPos"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_AndroidPlayerController[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      29,   14, // methods
       3,  601, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  188,    2, 0x06,    4 /* Public */,
       4,    1,  191,    2, 0x06,    6 /* Public */,
       5,    1,  194,    2, 0x06,    8 /* Public */,
       7,    3,  197,    2, 0x06,   10 /* Public */,
      11,    0,  204,    2, 0x06,   14 /* Public */,
      12,    0,  205,    2, 0x06,   15 /* Public */,
      13,    0,  206,    2, 0x06,   16 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      14,   19,  207,    2, 0x02,   17 /* Public */,
      14,   18,  246,    2, 0x22,   37 /* Public | MethodCloned */,
      14,   17,  283,    2, 0x22,   56 /* Public | MethodCloned */,
      14,   16,  318,    2, 0x22,   74 /* Public | MethodCloned */,
      14,   15,  351,    2, 0x22,   91 /* Public | MethodCloned */,
      14,   14,  382,    2, 0x22,  107 /* Public | MethodCloned */,
      14,   13,  411,    2, 0x22,  122 /* Public | MethodCloned */,
      14,   12,  438,    2, 0x22,  136 /* Public | MethodCloned */,
      14,   11,  463,    2, 0x22,  149 /* Public | MethodCloned */,
      14,   10,  486,    2, 0x22,  161 /* Public | MethodCloned */,
      14,    9,  507,    2, 0x22,  172 /* Public | MethodCloned */,
      14,    8,  526,    2, 0x22,  182 /* Public | MethodCloned */,
      14,    7,  543,    2, 0x22,  191 /* Public | MethodCloned */,
      14,    6,  558,    2, 0x22,  199 /* Public | MethodCloned */,
      14,    5,  571,    2, 0x22,  206 /* Public | MethodCloned */,
      14,    4,  582,    2, 0x22,  212 /* Public | MethodCloned */,
      34,    0,  591,    2, 0x02,  217 /* Public */,
      35,    1,  592,    2, 0x02,  218 /* Public */,
      37,    1,  595,    2, 0x02,  220 /* Public */,
      39,    0,  598,    2, 0x02,  222 /* Public */,
      40,    0,  599,    2, 0x02,  223 /* Public */,
      41,    0,  600,    2, 0x102,  224 /* Public | MethodIsConst  */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString,    8,    9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Float, QMetaType::Int, QMetaType::Int, QMetaType::QStringList, QMetaType::QStringList, QMetaType::Bool, QMetaType::Int, QMetaType::Float, QMetaType::QString, QMetaType::Bool, QMetaType::QString, QMetaType::Bool, QMetaType::QStringList, QMetaType::Float, QMetaType::Bool, QMetaType::QStringList, QMetaType::QString, QMetaType::QStringList,   15,   16,   17,   18,   19,   20,   21,   22,   23,   24,   25,   26,   27,   28,   29,   30,   31,   32,   33,
    QMetaType::Void, QMetaType::QString, QMetaType::Float, QMetaType::Int, QMetaType::Int, QMetaType::QStringList, QMetaType::QStringList, QMetaType::Bool, QMetaType::Int, QMetaType::Float, QMetaType::QString, QMetaType::Bool, QMetaType::QString, QMetaType::Bool, QMetaType::QStringList, QMetaType::Float, QMetaType::Bool, QMetaType::QStringList, QMetaType::QString,   15,   16,   17,   18,   19,   20,   21,   22,   23,   24,   25,   26,   27,   28,   29,   30,   31,   32,
    QMetaType::Void, QMetaType::QString, QMetaType::Float, QMetaType::Int, QMetaType::Int, QMetaType::QStringList, QMetaType::QStringList, QMetaType::Bool, QMetaType::Int, QMetaType::Float, QMetaType::QString, QMetaType::Bool, QMetaType::QString, QMetaType::Bool, QMetaType::QStringList, QMetaType::Float, QMetaType::Bool, QMetaType::QStringList,   15,   16,   17,   18,   19,   20,   21,   22,   23,   24,   25,   26,   27,   28,   29,   30,   31,
    QMetaType::Void, QMetaType::QString, QMetaType::Float, QMetaType::Int, QMetaType::Int, QMetaType::QStringList, QMetaType::QStringList, QMetaType::Bool, QMetaType::Int, QMetaType::Float, QMetaType::QString, QMetaType::Bool, QMetaType::QString, QMetaType::Bool, QMetaType::QStringList, QMetaType::Float, QMetaType::Bool,   15,   16,   17,   18,   19,   20,   21,   22,   23,   24,   25,   26,   27,   28,   29,   30,
    QMetaType::Void, QMetaType::QString, QMetaType::Float, QMetaType::Int, QMetaType::Int, QMetaType::QStringList, QMetaType::QStringList, QMetaType::Bool, QMetaType::Int, QMetaType::Float, QMetaType::QString, QMetaType::Bool, QMetaType::QString, QMetaType::Bool, QMetaType::QStringList, QMetaType::Float,   15,   16,   17,   18,   19,   20,   21,   22,   23,   24,   25,   26,   27,   28,   29,
    QMetaType::Void, QMetaType::QString, QMetaType::Float, QMetaType::Int, QMetaType::Int, QMetaType::QStringList, QMetaType::QStringList, QMetaType::Bool, QMetaType::Int, QMetaType::Float, QMetaType::QString, QMetaType::Bool, QMetaType::QString, QMetaType::Bool, QMetaType::QStringList,   15,   16,   17,   18,   19,   20,   21,   22,   23,   24,   25,   26,   27,   28,
    QMetaType::Void, QMetaType::QString, QMetaType::Float, QMetaType::Int, QMetaType::Int, QMetaType::QStringList, QMetaType::QStringList, QMetaType::Bool, QMetaType::Int, QMetaType::Float, QMetaType::QString, QMetaType::Bool, QMetaType::QString, QMetaType::Bool,   15,   16,   17,   18,   19,   20,   21,   22,   23,   24,   25,   26,   27,
    QMetaType::Void, QMetaType::QString, QMetaType::Float, QMetaType::Int, QMetaType::Int, QMetaType::QStringList, QMetaType::QStringList, QMetaType::Bool, QMetaType::Int, QMetaType::Float, QMetaType::QString, QMetaType::Bool, QMetaType::QString,   15,   16,   17,   18,   19,   20,   21,   22,   23,   24,   25,   26,
    QMetaType::Void, QMetaType::QString, QMetaType::Float, QMetaType::Int, QMetaType::Int, QMetaType::QStringList, QMetaType::QStringList, QMetaType::Bool, QMetaType::Int, QMetaType::Float, QMetaType::QString, QMetaType::Bool,   15,   16,   17,   18,   19,   20,   21,   22,   23,   24,   25,
    QMetaType::Void, QMetaType::QString, QMetaType::Float, QMetaType::Int, QMetaType::Int, QMetaType::QStringList, QMetaType::QStringList, QMetaType::Bool, QMetaType::Int, QMetaType::Float, QMetaType::QString,   15,   16,   17,   18,   19,   20,   21,   22,   23,   24,
    QMetaType::Void, QMetaType::QString, QMetaType::Float, QMetaType::Int, QMetaType::Int, QMetaType::QStringList, QMetaType::QStringList, QMetaType::Bool, QMetaType::Int, QMetaType::Float,   15,   16,   17,   18,   19,   20,   21,   22,   23,
    QMetaType::Void, QMetaType::QString, QMetaType::Float, QMetaType::Int, QMetaType::Int, QMetaType::QStringList, QMetaType::QStringList, QMetaType::Bool, QMetaType::Int,   15,   16,   17,   18,   19,   20,   21,   22,
    QMetaType::Void, QMetaType::QString, QMetaType::Float, QMetaType::Int, QMetaType::Int, QMetaType::QStringList, QMetaType::QStringList, QMetaType::Bool,   15,   16,   17,   18,   19,   20,   21,
    QMetaType::Void, QMetaType::QString, QMetaType::Float, QMetaType::Int, QMetaType::Int, QMetaType::QStringList, QMetaType::QStringList,   15,   16,   17,   18,   19,   20,
    QMetaType::Void, QMetaType::QString, QMetaType::Float, QMetaType::Int, QMetaType::Int, QMetaType::QStringList,   15,   16,   17,   18,   19,
    QMetaType::Void, QMetaType::QString, QMetaType::Float, QMetaType::Int, QMetaType::Int,   15,   16,   17,   18,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   36,
    QMetaType::Void, QMetaType::QString,   38,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,

 // properties: name, type, flags
      42, QMetaType::Int, 0x00015001, uint(0), 0,
      43, QMetaType::Int, 0x00015001, uint(1), 0,
      44, QMetaType::Int, 0x00015001, uint(2), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject AndroidPlayerController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_AndroidPlayerController.offsetsAndSizes,
    qt_meta_data_AndroidPlayerController,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_AndroidPlayerController_t,
        // property 'position'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'duration'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'playlistPos'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<AndroidPlayerController, std::true_type>,
        // method 'positionChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'durationChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'playlistPosChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'playbackEnded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'skipRequested'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'subtitleCycleRequested'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'audioCycleRequested'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'loadAndPlay'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>,
        // method 'loadAndPlay'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'loadAndPlay'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>,
        // method 'loadAndPlay'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'loadAndPlay'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        // method 'loadAndPlay'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>,
        // method 'loadAndPlay'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'loadAndPlay'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'loadAndPlay'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'loadAndPlay'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'loadAndPlay'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        // method 'loadAndPlay'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'loadAndPlay'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'loadAndPlay'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>,
        // method 'loadAndPlay'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>,
        // method 'loadAndPlay'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'stop'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'seekTo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'sendKey'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'showOsdSkipPrompt'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'clearOsdPrompt'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'hasSmoothPlaybackTradeoff'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>
    >,
    nullptr
} };

void AndroidPlayerController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AndroidPlayerController *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->positionChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->durationChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->playlistPosChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->playbackEnded((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 4: _t->skipRequested(); break;
        case 5: _t->subtitleCycleRequested(); break;
        case 6: _t->audioCycleRequested(); break;
        case 7: _t->loadAndPlay((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[8])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[9])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[10])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[11])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[12])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[13])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[14])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[15])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[16])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[17])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[18])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[19]))); break;
        case 8: _t->loadAndPlay((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[8])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[9])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[10])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[11])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[12])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[13])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[14])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[15])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[16])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[17])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[18]))); break;
        case 9: _t->loadAndPlay((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[8])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[9])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[10])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[11])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[12])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[13])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[14])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[15])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[16])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[17]))); break;
        case 10: _t->loadAndPlay((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[8])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[9])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[10])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[11])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[12])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[13])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[14])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[15])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[16]))); break;
        case 11: _t->loadAndPlay((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[8])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[9])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[10])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[11])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[12])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[13])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[14])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[15]))); break;
        case 12: _t->loadAndPlay((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[8])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[9])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[10])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[11])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[12])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[13])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[14]))); break;
        case 13: _t->loadAndPlay((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[8])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[9])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[10])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[11])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[12])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[13]))); break;
        case 14: _t->loadAndPlay((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[8])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[9])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[10])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[11])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[12]))); break;
        case 15: _t->loadAndPlay((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[8])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[9])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[10])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[11]))); break;
        case 16: _t->loadAndPlay((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[8])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[9])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[10]))); break;
        case 17: _t->loadAndPlay((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[8])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[9]))); break;
        case 18: _t->loadAndPlay((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[8]))); break;
        case 19: _t->loadAndPlay((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[7]))); break;
        case 20: _t->loadAndPlay((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[6]))); break;
        case 21: _t->loadAndPlay((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[5]))); break;
        case 22: _t->loadAndPlay((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4]))); break;
        case 23: _t->stop(); break;
        case 24: _t->seekTo((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 25: _t->sendKey((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 26: _t->showOsdSkipPrompt(); break;
        case 27: _t->clearOsdPrompt(); break;
        case 28: { bool _r = _t->hasSmoothPlaybackTradeoff();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AndroidPlayerController::*)(int );
            if (_t _q_method = &AndroidPlayerController::positionChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AndroidPlayerController::*)(int );
            if (_t _q_method = &AndroidPlayerController::durationChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (AndroidPlayerController::*)(int );
            if (_t _q_method = &AndroidPlayerController::playlistPosChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (AndroidPlayerController::*)(int , int , const QString & );
            if (_t _q_method = &AndroidPlayerController::playbackEnded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (AndroidPlayerController::*)();
            if (_t _q_method = &AndroidPlayerController::skipRequested; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (AndroidPlayerController::*)();
            if (_t _q_method = &AndroidPlayerController::subtitleCycleRequested; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (AndroidPlayerController::*)();
            if (_t _q_method = &AndroidPlayerController::audioCycleRequested; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
    }else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<AndroidPlayerController *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->position(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->duration(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->playlistPos(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *AndroidPlayerController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AndroidPlayerController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AndroidPlayerController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AndroidPlayerController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 29)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 29;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 29)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 29;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void AndroidPlayerController::positionChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AndroidPlayerController::durationChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void AndroidPlayerController::playlistPosChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void AndroidPlayerController::playbackEnded(int _t1, int _t2, const QString & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void AndroidPlayerController::skipRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void AndroidPlayerController::subtitleCycleRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void AndroidPlayerController::audioCycleRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
