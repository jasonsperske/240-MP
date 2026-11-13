/****************************************************************************
** Meta object code from reading C++ file 'JellyfinBackend.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/modules/jellyfin/JellyfinBackend.h"
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'JellyfinBackend.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_JellyfinBackend_t {
    uint offsetsAndSizes[208];
    char stringdata0[16];
    char stringdata1[17];
    char stringdata2[1];
    char stringdata3[16];
    char stringdata4[10];
    char stringdata5[12];
    char stringdata6[6];
    char stringdata7[11];
    char stringdata8[7];
    char stringdata9[15];
    char stringdata10[9];
    char stringdata11[21];
    char stringdata12[21];
    char stringdata13[14];
    char stringdata14[8];
    char stringdata15[15];
    char stringdata16[9];
    char stringdata17[23];
    char stringdata18[13];
    char stringdata19[18];
    char stringdata20[15];
    char stringdata21[4];
    char stringdata22[20];
    char stringdata23[4];
    char stringdata24[8];
    char stringdata25[14];
    char stringdata26[7];
    char stringdata27[9];
    char stringdata28[14];
    char stringdata29[8];
    char stringdata30[15];
    char stringdata31[12];
    char stringdata32[22];
    char stringdata33[5];
    char stringdata34[7];
    char stringdata35[21];
    char stringdata36[19];
    char stringdata37[31];
    char stringdata38[14];
    char stringdata39[17];
    char stringdata40[13];
    char stringdata41[17];
    char stringdata42[17];
    char stringdata43[9];
    char stringdata44[6];
    char stringdata45[9];
    char stringdata46[16];
    char stringdata47[14];
    char stringdata48[11];
    char stringdata49[7];
    char stringdata50[23];
    char stringdata51[10];
    char stringdata52[19];
    char stringdata53[27];
    char stringdata54[21];
    char stringdata55[15];
    char stringdata56[11];
    char stringdata57[9];
    char stringdata58[13];
    char stringdata59[7];
    char stringdata60[17];
    char stringdata61[14];
    char stringdata62[21];
    char stringdata63[21];
    char stringdata64[13];
    char stringdata65[9];
    char stringdata66[14];
    char stringdata67[9];
    char stringdata68[23];
    char stringdata69[13];
    char stringdata70[20];
    char stringdata71[17];
    char stringdata72[14];
    char stringdata73[17];
    char stringdata74[20];
    char stringdata75[15];
    char stringdata76[18];
    char stringdata77[14];
    char stringdata78[25];
    char stringdata79[14];
    char stringdata80[9];
    char stringdata81[24];
    char stringdata82[7];
    char stringdata83[22];
    char stringdata84[14];
    char stringdata85[17];
    char stringdata86[19];
    char stringdata87[14];
    char stringdata88[18];
    char stringdata89[17];
    char stringdata90[15];
    char stringdata91[13];
    char stringdata92[18];
    char stringdata93[28];
    char stringdata94[24];
    char stringdata95[20];
    char stringdata96[18];
    char stringdata97[24];
    char stringdata98[22];
    char stringdata99[21];
    char stringdata100[10];
    char stringdata101[8];
    char stringdata102[13];
    char stringdata103[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_JellyfinBackend_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_JellyfinBackend_t qt_meta_stringdata_JellyfinBackend = {
    {
        QT_MOC_LITERAL(0, 15),  // "JellyfinBackend"
        QT_MOC_LITERAL(16, 16),  // "authStateChanged"
        QT_MOC_LITERAL(33, 0),  // ""
        QT_MOC_LITERAL(34, 15),  // "librariesLoaded"
        QT_MOC_LITERAL(50, 9),  // "libraries"
        QT_MOC_LITERAL(60, 11),  // "itemsLoaded"
        QT_MOC_LITERAL(72, 5),  // "items"
        QT_MOC_LITERAL(78, 10),  // "itemLoaded"
        QT_MOC_LITERAL(89, 6),  // "detail"
        QT_MOC_LITERAL(96, 14),  // "childrenLoaded"
        QT_MOC_LITERAL(111, 8),  // "children"
        QT_MOC_LITERAL(120, 20),  // "boxsetChildrenLoaded"
        QT_MOC_LITERAL(141, 20),  // "folderChildrenLoaded"
        QT_MOC_LITERAL(162, 13),  // "seasonsLoaded"
        QT_MOC_LITERAL(176, 7),  // "seasons"
        QT_MOC_LITERAL(184, 14),  // "episodesLoaded"
        QT_MOC_LITERAL(199, 8),  // "episodes"
        QT_MOC_LITERAL(208, 22),  // "continueWatchingLoaded"
        QT_MOC_LITERAL(231, 12),  // "upNextLoaded"
        QT_MOC_LITERAL(244, 17),  // "seriesNextUpReady"
        QT_MOC_LITERAL(262, 14),  // "streamUrlReady"
        QT_MOC_LITERAL(277, 3),  // "url"
        QT_MOC_LITERAL(281, 19),  // "dynamicOptionsReady"
        QT_MOC_LITERAL(301, 3),  // "key"
        QT_MOC_LITERAL(305, 7),  // "options"
        QT_MOC_LITERAL(313, 13),  // "segmentsReady"
        QT_MOC_LITERAL(327, 6),  // "itemId"
        QT_MOC_LITERAL(334, 8),  // "segments"
        QT_MOC_LITERAL(343, 13),  // "errorOccurred"
        QT_MOC_LITERAL(357, 7),  // "message"
        QT_MOC_LITERAL(365, 14),  // "logoutComplete"
        QT_MOC_LITERAL(380, 11),  // "authRevoked"
        QT_MOC_LITERAL(392, 21),  // "quickConnectCodeReady"
        QT_MOC_LITERAL(414, 4),  // "code"
        QT_MOC_LITERAL(419, 6),  // "secret"
        QT_MOC_LITERAL(426, 20),  // "quickConnectApproved"
        QT_MOC_LITERAL(447, 18),  // "quickConnectFailed"
        QT_MOC_LITERAL(466, 30),  // "serverLanguagePreferencesReady"
        QT_MOC_LITERAL(497, 13),  // "audioLanguage"
        QT_MOC_LITERAL(511, 16),  // "subtitleLanguage"
        QT_MOC_LITERAL(528, 12),  // "subtitleMode"
        QT_MOC_LITERAL(541, 16),  // "nextEpisodeReady"
        QT_MOC_LITERAL(558, 16),  // "onSettingChanged"
        QT_MOC_LITERAL(575, 8),  // "moduleId"
        QT_MOC_LITERAL(584, 5),  // "value"
        QT_MOC_LITERAL(590, 8),  // "has_auth"
        QT_MOC_LITERAL(599, 15),  // "get_server_name"
        QT_MOC_LITERAL(615, 13),  // "get_user_name"
        QT_MOC_LITERAL(629, 10),  // "check_auth"
        QT_MOC_LITERAL(640, 6),  // "logout"
        QT_MOC_LITERAL(647, 22),  // "quick_connect_initiate"
        QT_MOC_LITERAL(670, 9),  // "serverUrl"
        QT_MOC_LITERAL(680, 18),  // "quick_connect_poll"
        QT_MOC_LITERAL(699, 26),  // "quick_connect_authenticate"
        QT_MOC_LITERAL(726, 20),  // "quick_connect_cancel"
        QT_MOC_LITERAL(747, 14),  // "load_libraries"
        QT_MOC_LITERAL(762, 10),  // "load_items"
        QT_MOC_LITERAL(773, 8),  // "parentId"
        QT_MOC_LITERAL(782, 12),  // "includeTypes"
        QT_MOC_LITERAL(795, 6),  // "sortBy"
        QT_MOC_LITERAL(802, 16),  // "load_item_detail"
        QT_MOC_LITERAL(819, 13),  // "load_children"
        QT_MOC_LITERAL(833, 20),  // "load_boxset_children"
        QT_MOC_LITERAL(854, 20),  // "load_folder_children"
        QT_MOC_LITERAL(875, 12),  // "load_seasons"
        QT_MOC_LITERAL(888, 8),  // "seriesId"
        QT_MOC_LITERAL(897, 13),  // "load_episodes"
        QT_MOC_LITERAL(911, 8),  // "seasonId"
        QT_MOC_LITERAL(920, 22),  // "load_continue_watching"
        QT_MOC_LITERAL(943, 12),  // "load_up_next"
        QT_MOC_LITERAL(956, 19),  // "load_series_next_up"
        QT_MOC_LITERAL(976, 16),  // "get_playback_url"
        QT_MOC_LITERAL(993, 13),  // "mediaSourceId"
        QT_MOC_LITERAL(1007, 16),  // "audioStreamIndex"
        QT_MOC_LITERAL(1024, 19),  // "subtitleStreamIndex"
        QT_MOC_LITERAL(1044, 14),  // "forceTranscode"
        QT_MOC_LITERAL(1059, 17),  // "load_next_episode"
        QT_MOC_LITERAL(1077, 13),  // "currentItemId"
        QT_MOC_LITERAL(1091, 24),  // "update_playback_progress"
        QT_MOC_LITERAL(1116, 13),  // "positionTicks"
        QT_MOC_LITERAL(1130, 8),  // "isPaused"
        QT_MOC_LITERAL(1139, 23),  // "report_playback_stopped"
        QT_MOC_LITERAL(1163, 6),  // "failed"
        QT_MOC_LITERAL(1170, 21),  // "report_playback_start"
        QT_MOC_LITERAL(1192, 13),  // "audioStreamId"
        QT_MOC_LITERAL(1206, 16),  // "subtitleStreamId"
        QT_MOC_LITERAL(1223, 18),  // "startPositionTicks"
        QT_MOC_LITERAL(1242, 13),  // "fetchSegments"
        QT_MOC_LITERAL(1256, 17),  // "probeCapabilities"
        QT_MOC_LITERAL(1274, 16),  // "get_access_token"
        QT_MOC_LITERAL(1291, 14),  // "get_auth_state"
        QT_MOC_LITERAL(1306, 12),  // "getLibraries"
        QT_MOC_LITERAL(1319, 17),  // "getVideoQualities"
        QT_MOC_LITERAL(1337, 27),  // "get_resume_playback_options"
        QT_MOC_LITERAL(1365, 23),  // "load_server_preferences"
        QT_MOC_LITERAL(1389, 19),  // "get_last_audio_lang"
        QT_MOC_LITERAL(1409, 17),  // "get_last_sub_lang"
        QT_MOC_LITERAL(1427, 23),  // "get_last_audio_lang_idx"
        QT_MOC_LITERAL(1451, 21),  // "get_last_sub_lang_idx"
        QT_MOC_LITERAL(1473, 20),  // "set_last_track_langs"
        QT_MOC_LITERAL(1494, 9),  // "audioLang"
        QT_MOC_LITERAL(1504, 7),  // "subLang"
        QT_MOC_LITERAL(1512, 12),  // "audioLangIdx"
        QT_MOC_LITERAL(1525, 10)   // "subLangIdx"
    },
    "JellyfinBackend",
    "authStateChanged",
    "",
    "librariesLoaded",
    "libraries",
    "itemsLoaded",
    "items",
    "itemLoaded",
    "detail",
    "childrenLoaded",
    "children",
    "boxsetChildrenLoaded",
    "folderChildrenLoaded",
    "seasonsLoaded",
    "seasons",
    "episodesLoaded",
    "episodes",
    "continueWatchingLoaded",
    "upNextLoaded",
    "seriesNextUpReady",
    "streamUrlReady",
    "url",
    "dynamicOptionsReady",
    "key",
    "options",
    "segmentsReady",
    "itemId",
    "segments",
    "errorOccurred",
    "message",
    "logoutComplete",
    "authRevoked",
    "quickConnectCodeReady",
    "code",
    "secret",
    "quickConnectApproved",
    "quickConnectFailed",
    "serverLanguagePreferencesReady",
    "audioLanguage",
    "subtitleLanguage",
    "subtitleMode",
    "nextEpisodeReady",
    "onSettingChanged",
    "moduleId",
    "value",
    "has_auth",
    "get_server_name",
    "get_user_name",
    "check_auth",
    "logout",
    "quick_connect_initiate",
    "serverUrl",
    "quick_connect_poll",
    "quick_connect_authenticate",
    "quick_connect_cancel",
    "load_libraries",
    "load_items",
    "parentId",
    "includeTypes",
    "sortBy",
    "load_item_detail",
    "load_children",
    "load_boxset_children",
    "load_folder_children",
    "load_seasons",
    "seriesId",
    "load_episodes",
    "seasonId",
    "load_continue_watching",
    "load_up_next",
    "load_series_next_up",
    "get_playback_url",
    "mediaSourceId",
    "audioStreamIndex",
    "subtitleStreamIndex",
    "forceTranscode",
    "load_next_episode",
    "currentItemId",
    "update_playback_progress",
    "positionTicks",
    "isPaused",
    "report_playback_stopped",
    "failed",
    "report_playback_start",
    "audioStreamId",
    "subtitleStreamId",
    "startPositionTicks",
    "fetchSegments",
    "probeCapabilities",
    "get_access_token",
    "get_auth_state",
    "getLibraries",
    "getVideoQualities",
    "get_resume_playback_options",
    "load_server_preferences",
    "get_last_audio_lang",
    "get_last_sub_lang",
    "get_last_audio_lang_idx",
    "get_last_sub_lang_idx",
    "set_last_track_langs",
    "audioLang",
    "subLang",
    "audioLangIdx",
    "subLangIdx"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_JellyfinBackend[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      67,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      23,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  416,    2, 0x06,    1 /* Public */,
       3,    1,  417,    2, 0x06,    2 /* Public */,
       5,    1,  420,    2, 0x06,    4 /* Public */,
       7,    1,  423,    2, 0x06,    6 /* Public */,
       9,    1,  426,    2, 0x06,    8 /* Public */,
      11,    1,  429,    2, 0x06,   10 /* Public */,
      12,    1,  432,    2, 0x06,   12 /* Public */,
      13,    1,  435,    2, 0x06,   14 /* Public */,
      15,    1,  438,    2, 0x06,   16 /* Public */,
      17,    1,  441,    2, 0x06,   18 /* Public */,
      18,    1,  444,    2, 0x06,   20 /* Public */,
      19,    1,  447,    2, 0x06,   22 /* Public */,
      20,    1,  450,    2, 0x06,   24 /* Public */,
      22,    2,  453,    2, 0x06,   26 /* Public */,
      25,    2,  458,    2, 0x06,   29 /* Public */,
      28,    1,  463,    2, 0x06,   32 /* Public */,
      30,    0,  466,    2, 0x06,   34 /* Public */,
      31,    0,  467,    2, 0x06,   35 /* Public */,
      32,    2,  468,    2, 0x06,   36 /* Public */,
      35,    0,  473,    2, 0x06,   39 /* Public */,
      36,    1,  474,    2, 0x06,   40 /* Public */,
      37,    3,  477,    2, 0x06,   42 /* Public */,
      41,    1,  484,    2, 0x06,   46 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      42,    3,  487,    2, 0x0a,   48 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      45,    0,  494,    2, 0x02,   52 /* Public */,
      46,    0,  495,    2, 0x02,   53 /* Public */,
      47,    0,  496,    2, 0x02,   54 /* Public */,
      48,    0,  497,    2, 0x02,   55 /* Public */,
      49,    0,  498,    2, 0x02,   56 /* Public */,
      50,    1,  499,    2, 0x02,   57 /* Public */,
      52,    1,  502,    2, 0x02,   59 /* Public */,
      53,    1,  505,    2, 0x02,   61 /* Public */,
      54,    0,  508,    2, 0x02,   63 /* Public */,
      55,    0,  509,    2, 0x02,   64 /* Public */,
      56,    3,  510,    2, 0x02,   65 /* Public */,
      60,    1,  517,    2, 0x02,   69 /* Public */,
      61,    1,  520,    2, 0x02,   71 /* Public */,
      62,    1,  523,    2, 0x02,   73 /* Public */,
      63,    1,  526,    2, 0x02,   75 /* Public */,
      64,    1,  529,    2, 0x02,   77 /* Public */,
      66,    2,  532,    2, 0x02,   79 /* Public */,
      68,    0,  537,    2, 0x02,   82 /* Public */,
      69,    0,  538,    2, 0x02,   83 /* Public */,
      70,    1,  539,    2, 0x02,   84 /* Public */,
      71,    5,  542,    2, 0x02,   86 /* Public */,
      71,    4,  553,    2, 0x22,   92 /* Public | MethodCloned */,
      76,    1,  562,    2, 0x02,   97 /* Public */,
      78,    4,  565,    2, 0x02,   99 /* Public */,
      81,    4,  574,    2, 0x02,  104 /* Public */,
      81,    3,  583,    2, 0x22,  109 /* Public | MethodCloned */,
      83,    5,  590,    2, 0x02,  113 /* Public */,
      83,    4,  601,    2, 0x22,  119 /* Public | MethodCloned */,
      87,    1,  610,    2, 0x02,  124 /* Public */,
      88,    0,  613,    2, 0x02,  126 /* Public */,
      89,    0,  614,    2, 0x102,  127 /* Public | MethodIsConst  */,
      90,    0,  615,    2, 0x02,  128 /* Public */,
      91,    0,  616,    2, 0x02,  129 /* Public */,
      92,    0,  617,    2, 0x02,  130 /* Public */,
      93,    0,  618,    2, 0x02,  131 /* Public */,
      94,    0,  619,    2, 0x02,  132 /* Public */,
      95,    0,  620,    2, 0x102,  133 /* Public | MethodIsConst  */,
      96,    0,  621,    2, 0x102,  134 /* Public | MethodIsConst  */,
      97,    0,  622,    2, 0x102,  135 /* Public | MethodIsConst  */,
      98,    0,  623,    2, 0x102,  136 /* Public | MethodIsConst  */,
      99,    4,  624,    2, 0x02,  137 /* Public */,
      99,    3,  633,    2, 0x22,  142 /* Public | MethodCloned */,
      99,    2,  640,    2, 0x22,  146 /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariant,    4,
    QMetaType::Void, QMetaType::QVariant,    6,
    QMetaType::Void, QMetaType::QVariant,    8,
    QMetaType::Void, QMetaType::QVariant,   10,
    QMetaType::Void, QMetaType::QVariant,   10,
    QMetaType::Void, QMetaType::QVariant,   10,
    QMetaType::Void, QMetaType::QVariant,   14,
    QMetaType::Void, QMetaType::QVariant,   16,
    QMetaType::Void, QMetaType::QVariant,    6,
    QMetaType::Void, QMetaType::QVariant,    6,
    QMetaType::Void, QMetaType::QVariantMap,    8,
    QMetaType::Void, QMetaType::QString,   21,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant,   23,   24,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariantList,   26,   27,
    QMetaType::Void, QMetaType::QString,   29,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   33,   34,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   29,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   38,   39,   40,
    QMetaType::Void, QMetaType::QVariantMap,    8,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QVariant,   43,   23,   44,

 // methods: parameters
    QMetaType::Bool,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   51,
    QMetaType::Void, QMetaType::QString,   34,
    QMetaType::Void, QMetaType::QString,   34,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   57,   58,   59,
    QMetaType::Void, QMetaType::QString,   26,
    QMetaType::Void, QMetaType::QString,   26,
    QMetaType::Void, QMetaType::QString,   57,
    QMetaType::Void, QMetaType::QString,   57,
    QMetaType::Void, QMetaType::QString,   65,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   65,   67,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   65,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Bool,   26,   72,   73,   74,   75,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int,   26,   72,   73,   74,
    QMetaType::Void, QMetaType::QString,   77,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::LongLong, QMetaType::Bool,   26,   72,   79,   80,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::LongLong, QMetaType::Bool,   26,   72,   79,   82,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::LongLong,   26,   72,   79,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::LongLong,   26,   72,   84,   85,   86,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   26,   72,   84,   85,
    QMetaType::Void, QMetaType::QString,   26,
    QMetaType::Void,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int,  100,  101,  102,  103,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int,  100,  101,  102,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,  100,  101,

       0        // eod
};

Q_CONSTINIT const QMetaObject JellyfinBackend::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_JellyfinBackend.offsetsAndSizes,
    qt_meta_data_JellyfinBackend,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_JellyfinBackend_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<JellyfinBackend, std::true_type>,
        // method 'authStateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'librariesLoaded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariant &, std::false_type>,
        // method 'itemsLoaded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariant &, std::false_type>,
        // method 'itemLoaded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariant &, std::false_type>,
        // method 'childrenLoaded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariant &, std::false_type>,
        // method 'boxsetChildrenLoaded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariant &, std::false_type>,
        // method 'folderChildrenLoaded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariant &, std::false_type>,
        // method 'seasonsLoaded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariant &, std::false_type>,
        // method 'episodesLoaded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariant &, std::false_type>,
        // method 'continueWatchingLoaded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariant &, std::false_type>,
        // method 'upNextLoaded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariant &, std::false_type>,
        // method 'seriesNextUpReady'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariantMap &, std::false_type>,
        // method 'streamUrlReady'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'dynamicOptionsReady'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariant &, std::false_type>,
        // method 'segmentsReady'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariantList &, std::false_type>,
        // method 'errorOccurred'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'logoutComplete'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'authRevoked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'quickConnectCodeReady'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'quickConnectApproved'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'quickConnectFailed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'serverLanguagePreferencesReady'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'nextEpisodeReady'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariantMap &, std::false_type>,
        // method 'onSettingChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariant &, std::false_type>,
        // method 'has_auth'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'get_server_name'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_user_name'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'check_auth'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'logout'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'quick_connect_initiate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'quick_connect_poll'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'quick_connect_authenticate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'quick_connect_cancel'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'load_libraries'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'load_items'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'load_item_detail'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'load_children'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'load_boxset_children'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'load_folder_children'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'load_seasons'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'load_episodes'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'load_continue_watching'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'load_up_next'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'load_series_next_up'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'get_playback_url'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'get_playback_url'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'load_next_episode'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'update_playback_progress'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<qint64, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'report_playback_stopped'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<qint64, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'report_playback_stopped'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<qint64, std::false_type>,
        // method 'report_playback_start'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<qint64, std::false_type>,
        // method 'report_playback_start'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'fetchSegments'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'probeCapabilities'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'get_access_token'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_auth_state'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getLibraries'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'getVideoQualities'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'get_resume_playback_options'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'load_server_preferences'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'get_last_audio_lang'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_last_sub_lang'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_last_audio_lang_idx'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'get_last_sub_lang_idx'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'set_last_track_langs'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'set_last_track_langs'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'set_last_track_langs'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
    >,
    nullptr
} };

void JellyfinBackend::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<JellyfinBackend *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->authStateChanged(); break;
        case 1: _t->librariesLoaded((*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[1]))); break;
        case 2: _t->itemsLoaded((*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[1]))); break;
        case 3: _t->itemLoaded((*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[1]))); break;
        case 4: _t->childrenLoaded((*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[1]))); break;
        case 5: _t->boxsetChildrenLoaded((*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[1]))); break;
        case 6: _t->folderChildrenLoaded((*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[1]))); break;
        case 7: _t->seasonsLoaded((*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[1]))); break;
        case 8: _t->episodesLoaded((*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[1]))); break;
        case 9: _t->continueWatchingLoaded((*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[1]))); break;
        case 10: _t->upNextLoaded((*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[1]))); break;
        case 11: _t->seriesNextUpReady((*reinterpret_cast< std::add_pointer_t<QVariantMap>>(_a[1]))); break;
        case 12: _t->streamUrlReady((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 13: _t->dynamicOptionsReady((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[2]))); break;
        case 14: _t->segmentsReady((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QVariantList>>(_a[2]))); break;
        case 15: _t->errorOccurred((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 16: _t->logoutComplete(); break;
        case 17: _t->authRevoked(); break;
        case 18: _t->quickConnectCodeReady((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 19: _t->quickConnectApproved(); break;
        case 20: _t->quickConnectFailed((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 21: _t->serverLanguagePreferencesReady((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 22: _t->nextEpisodeReady((*reinterpret_cast< std::add_pointer_t<QVariantMap>>(_a[1]))); break;
        case 23: _t->onSettingChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[3]))); break;
        case 24: { bool _r = _t->has_auth();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 25: { QString _r = _t->get_server_name();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 26: { QString _r = _t->get_user_name();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 27: _t->check_auth(); break;
        case 28: _t->logout(); break;
        case 29: _t->quick_connect_initiate((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 30: _t->quick_connect_poll((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 31: _t->quick_connect_authenticate((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 32: _t->quick_connect_cancel(); break;
        case 33: _t->load_libraries(); break;
        case 34: _t->load_items((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 35: _t->load_item_detail((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 36: _t->load_children((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 37: _t->load_boxset_children((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 38: _t->load_folder_children((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 39: _t->load_seasons((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 40: _t->load_episodes((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 41: _t->load_continue_watching(); break;
        case 42: _t->load_up_next(); break;
        case 43: _t->load_series_next_up((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 44: _t->get_playback_url((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[5]))); break;
        case 45: _t->get_playback_url((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4]))); break;
        case 46: _t->load_next_episode((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 47: _t->update_playback_progress((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<qint64>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[4]))); break;
        case 48: _t->report_playback_stopped((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<qint64>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[4]))); break;
        case 49: _t->report_playback_stopped((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<qint64>>(_a[3]))); break;
        case 50: _t->report_playback_start((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<qint64>>(_a[5]))); break;
        case 51: _t->report_playback_start((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4]))); break;
        case 52: _t->fetchSegments((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 53: _t->probeCapabilities(); break;
        case 54: { QString _r = _t->get_access_token();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 55: { QString _r = _t->get_auth_state();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 56: _t->getLibraries(); break;
        case 57: _t->getVideoQualities(); break;
        case 58: _t->get_resume_playback_options(); break;
        case 59: _t->load_server_preferences(); break;
        case 60: { QString _r = _t->get_last_audio_lang();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 61: { QString _r = _t->get_last_sub_lang();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 62: { int _r = _t->get_last_audio_lang_idx();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 63: { int _r = _t->get_last_sub_lang_idx();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 64: _t->set_last_track_langs((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4]))); break;
        case 65: _t->set_last_track_langs((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 66: _t->set_last_track_langs((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (JellyfinBackend::*)();
            if (_t _q_method = &JellyfinBackend::authStateChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (JellyfinBackend::*)(const QVariant & );
            if (_t _q_method = &JellyfinBackend::librariesLoaded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (JellyfinBackend::*)(const QVariant & );
            if (_t _q_method = &JellyfinBackend::itemsLoaded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (JellyfinBackend::*)(const QVariant & );
            if (_t _q_method = &JellyfinBackend::itemLoaded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (JellyfinBackend::*)(const QVariant & );
            if (_t _q_method = &JellyfinBackend::childrenLoaded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (JellyfinBackend::*)(const QVariant & );
            if (_t _q_method = &JellyfinBackend::boxsetChildrenLoaded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (JellyfinBackend::*)(const QVariant & );
            if (_t _q_method = &JellyfinBackend::folderChildrenLoaded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (JellyfinBackend::*)(const QVariant & );
            if (_t _q_method = &JellyfinBackend::seasonsLoaded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (JellyfinBackend::*)(const QVariant & );
            if (_t _q_method = &JellyfinBackend::episodesLoaded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (JellyfinBackend::*)(const QVariant & );
            if (_t _q_method = &JellyfinBackend::continueWatchingLoaded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (JellyfinBackend::*)(const QVariant & );
            if (_t _q_method = &JellyfinBackend::upNextLoaded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (JellyfinBackend::*)(const QVariantMap & );
            if (_t _q_method = &JellyfinBackend::seriesNextUpReady; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (JellyfinBackend::*)(const QString & );
            if (_t _q_method = &JellyfinBackend::streamUrlReady; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (JellyfinBackend::*)(const QString & , const QVariant & );
            if (_t _q_method = &JellyfinBackend::dynamicOptionsReady; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (JellyfinBackend::*)(const QString & , const QVariantList & );
            if (_t _q_method = &JellyfinBackend::segmentsReady; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (JellyfinBackend::*)(const QString & );
            if (_t _q_method = &JellyfinBackend::errorOccurred; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (JellyfinBackend::*)();
            if (_t _q_method = &JellyfinBackend::logoutComplete; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (JellyfinBackend::*)();
            if (_t _q_method = &JellyfinBackend::authRevoked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (JellyfinBackend::*)(const QString & , const QString & );
            if (_t _q_method = &JellyfinBackend::quickConnectCodeReady; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 18;
                return;
            }
        }
        {
            using _t = void (JellyfinBackend::*)();
            if (_t _q_method = &JellyfinBackend::quickConnectApproved; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 19;
                return;
            }
        }
        {
            using _t = void (JellyfinBackend::*)(const QString & );
            if (_t _q_method = &JellyfinBackend::quickConnectFailed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 20;
                return;
            }
        }
        {
            using _t = void (JellyfinBackend::*)(const QString & , const QString & , const QString & );
            if (_t _q_method = &JellyfinBackend::serverLanguagePreferencesReady; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 21;
                return;
            }
        }
        {
            using _t = void (JellyfinBackend::*)(const QVariantMap & );
            if (_t _q_method = &JellyfinBackend::nextEpisodeReady; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 22;
                return;
            }
        }
    }
}

const QMetaObject *JellyfinBackend::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *JellyfinBackend::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_JellyfinBackend.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int JellyfinBackend::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 67)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 67;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 67)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 67;
    }
    return _id;
}

// SIGNAL 0
void JellyfinBackend::authStateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void JellyfinBackend::librariesLoaded(const QVariant & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void JellyfinBackend::itemsLoaded(const QVariant & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void JellyfinBackend::itemLoaded(const QVariant & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void JellyfinBackend::childrenLoaded(const QVariant & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void JellyfinBackend::boxsetChildrenLoaded(const QVariant & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void JellyfinBackend::folderChildrenLoaded(const QVariant & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void JellyfinBackend::seasonsLoaded(const QVariant & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void JellyfinBackend::episodesLoaded(const QVariant & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void JellyfinBackend::continueWatchingLoaded(const QVariant & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void JellyfinBackend::upNextLoaded(const QVariant & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void JellyfinBackend::seriesNextUpReady(const QVariantMap & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void JellyfinBackend::streamUrlReady(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void JellyfinBackend::dynamicOptionsReady(const QString & _t1, const QVariant & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void JellyfinBackend::segmentsReady(const QString & _t1, const QVariantList & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void JellyfinBackend::errorOccurred(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void JellyfinBackend::logoutComplete()
{
    QMetaObject::activate(this, &staticMetaObject, 16, nullptr);
}

// SIGNAL 17
void JellyfinBackend::authRevoked()
{
    QMetaObject::activate(this, &staticMetaObject, 17, nullptr);
}

// SIGNAL 18
void JellyfinBackend::quickConnectCodeReady(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void JellyfinBackend::quickConnectApproved()
{
    QMetaObject::activate(this, &staticMetaObject, 19, nullptr);
}

// SIGNAL 20
void JellyfinBackend::quickConnectFailed(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void JellyfinBackend::serverLanguagePreferencesReady(const QString & _t1, const QString & _t2, const QString & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 21, _a);
}

// SIGNAL 22
void JellyfinBackend::nextEpisodeReady(const QVariantMap & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 22, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
