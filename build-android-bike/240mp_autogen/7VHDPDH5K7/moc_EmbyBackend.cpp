/****************************************************************************
** Meta object code from reading C++ file 'EmbyBackend.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/modules/emby/EmbyBackend.h"
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'EmbyBackend.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_EmbyBackend_t {
    uint offsetsAndSizes[210];
    char stringdata0[12];
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
    char stringdata32[20];
    char stringdata33[8];
    char stringdata34[14];
    char stringdata35[31];
    char stringdata36[14];
    char stringdata37[17];
    char stringdata38[13];
    char stringdata39[17];
    char stringdata40[17];
    char stringdata41[9];
    char stringdata42[6];
    char stringdata43[9];
    char stringdata44[16];
    char stringdata45[14];
    char stringdata46[11];
    char stringdata47[7];
    char stringdata48[13];
    char stringdata49[10];
    char stringdata50[9];
    char stringdata51[9];
    char stringdata52[21];
    char stringdata53[16];
    char stringdata54[22];
    char stringdata55[10];
    char stringdata56[15];
    char stringdata57[11];
    char stringdata58[9];
    char stringdata59[13];
    char stringdata60[7];
    char stringdata61[17];
    char stringdata62[14];
    char stringdata63[21];
    char stringdata64[21];
    char stringdata65[13];
    char stringdata66[9];
    char stringdata67[14];
    char stringdata68[9];
    char stringdata69[23];
    char stringdata70[13];
    char stringdata71[20];
    char stringdata72[17];
    char stringdata73[14];
    char stringdata74[17];
    char stringdata75[20];
    char stringdata76[15];
    char stringdata77[18];
    char stringdata78[14];
    char stringdata79[25];
    char stringdata80[14];
    char stringdata81[9];
    char stringdata82[24];
    char stringdata83[7];
    char stringdata84[22];
    char stringdata85[14];
    char stringdata86[17];
    char stringdata87[19];
    char stringdata88[14];
    char stringdata89[17];
    char stringdata90[15];
    char stringdata91[15];
    char stringdata92[13];
    char stringdata93[18];
    char stringdata94[28];
    char stringdata95[24];
    char stringdata96[20];
    char stringdata97[18];
    char stringdata98[24];
    char stringdata99[22];
    char stringdata100[21];
    char stringdata101[10];
    char stringdata102[8];
    char stringdata103[13];
    char stringdata104[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_EmbyBackend_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_EmbyBackend_t qt_meta_stringdata_EmbyBackend = {
    {
        QT_MOC_LITERAL(0, 11),  // "EmbyBackend"
        QT_MOC_LITERAL(12, 16),  // "authStateChanged"
        QT_MOC_LITERAL(29, 0),  // ""
        QT_MOC_LITERAL(30, 15),  // "librariesLoaded"
        QT_MOC_LITERAL(46, 9),  // "libraries"
        QT_MOC_LITERAL(56, 11),  // "itemsLoaded"
        QT_MOC_LITERAL(68, 5),  // "items"
        QT_MOC_LITERAL(74, 10),  // "itemLoaded"
        QT_MOC_LITERAL(85, 6),  // "detail"
        QT_MOC_LITERAL(92, 14),  // "childrenLoaded"
        QT_MOC_LITERAL(107, 8),  // "children"
        QT_MOC_LITERAL(116, 20),  // "boxsetChildrenLoaded"
        QT_MOC_LITERAL(137, 20),  // "folderChildrenLoaded"
        QT_MOC_LITERAL(158, 13),  // "seasonsLoaded"
        QT_MOC_LITERAL(172, 7),  // "seasons"
        QT_MOC_LITERAL(180, 14),  // "episodesLoaded"
        QT_MOC_LITERAL(195, 8),  // "episodes"
        QT_MOC_LITERAL(204, 22),  // "continueWatchingLoaded"
        QT_MOC_LITERAL(227, 12),  // "upNextLoaded"
        QT_MOC_LITERAL(240, 17),  // "seriesNextUpReady"
        QT_MOC_LITERAL(258, 14),  // "streamUrlReady"
        QT_MOC_LITERAL(273, 3),  // "url"
        QT_MOC_LITERAL(277, 19),  // "dynamicOptionsReady"
        QT_MOC_LITERAL(297, 3),  // "key"
        QT_MOC_LITERAL(301, 7),  // "options"
        QT_MOC_LITERAL(309, 13),  // "segmentsReady"
        QT_MOC_LITERAL(323, 6),  // "itemId"
        QT_MOC_LITERAL(330, 8),  // "segments"
        QT_MOC_LITERAL(339, 13),  // "errorOccurred"
        QT_MOC_LITERAL(353, 7),  // "message"
        QT_MOC_LITERAL(361, 14),  // "logoutComplete"
        QT_MOC_LITERAL(376, 11),  // "authRevoked"
        QT_MOC_LITERAL(388, 19),  // "connectServersReady"
        QT_MOC_LITERAL(408, 7),  // "servers"
        QT_MOC_LITERAL(416, 13),  // "connectFailed"
        QT_MOC_LITERAL(430, 30),  // "serverLanguagePreferencesReady"
        QT_MOC_LITERAL(461, 13),  // "audioLanguage"
        QT_MOC_LITERAL(475, 16),  // "subtitleLanguage"
        QT_MOC_LITERAL(492, 12),  // "subtitleMode"
        QT_MOC_LITERAL(505, 16),  // "nextEpisodeReady"
        QT_MOC_LITERAL(522, 16),  // "onSettingChanged"
        QT_MOC_LITERAL(539, 8),  // "moduleId"
        QT_MOC_LITERAL(548, 5),  // "value"
        QT_MOC_LITERAL(554, 8),  // "has_auth"
        QT_MOC_LITERAL(563, 15),  // "get_server_name"
        QT_MOC_LITERAL(579, 13),  // "get_user_name"
        QT_MOC_LITERAL(593, 10),  // "check_auth"
        QT_MOC_LITERAL(604, 6),  // "logout"
        QT_MOC_LITERAL(611, 12),  // "authenticate"
        QT_MOC_LITERAL(624, 9),  // "serverUrl"
        QT_MOC_LITERAL(634, 8),  // "username"
        QT_MOC_LITERAL(643, 8),  // "password"
        QT_MOC_LITERAL(652, 20),  // "connect_authenticate"
        QT_MOC_LITERAL(673, 15),  // "usernameOrEmail"
        QT_MOC_LITERAL(689, 21),  // "connect_select_server"
        QT_MOC_LITERAL(711, 9),  // "accessKey"
        QT_MOC_LITERAL(721, 14),  // "load_libraries"
        QT_MOC_LITERAL(736, 10),  // "load_items"
        QT_MOC_LITERAL(747, 8),  // "parentId"
        QT_MOC_LITERAL(756, 12),  // "includeTypes"
        QT_MOC_LITERAL(769, 6),  // "sortBy"
        QT_MOC_LITERAL(776, 16),  // "load_item_detail"
        QT_MOC_LITERAL(793, 13),  // "load_children"
        QT_MOC_LITERAL(807, 20),  // "load_boxset_children"
        QT_MOC_LITERAL(828, 20),  // "load_folder_children"
        QT_MOC_LITERAL(849, 12),  // "load_seasons"
        QT_MOC_LITERAL(862, 8),  // "seriesId"
        QT_MOC_LITERAL(871, 13),  // "load_episodes"
        QT_MOC_LITERAL(885, 8),  // "seasonId"
        QT_MOC_LITERAL(894, 22),  // "load_continue_watching"
        QT_MOC_LITERAL(917, 12),  // "load_up_next"
        QT_MOC_LITERAL(930, 19),  // "load_series_next_up"
        QT_MOC_LITERAL(950, 16),  // "get_playback_url"
        QT_MOC_LITERAL(967, 13),  // "mediaSourceId"
        QT_MOC_LITERAL(981, 16),  // "audioStreamIndex"
        QT_MOC_LITERAL(998, 19),  // "subtitleStreamIndex"
        QT_MOC_LITERAL(1018, 14),  // "forceTranscode"
        QT_MOC_LITERAL(1033, 17),  // "load_next_episode"
        QT_MOC_LITERAL(1051, 13),  // "currentItemId"
        QT_MOC_LITERAL(1065, 24),  // "update_playback_progress"
        QT_MOC_LITERAL(1090, 13),  // "positionTicks"
        QT_MOC_LITERAL(1104, 8),  // "isPaused"
        QT_MOC_LITERAL(1113, 23),  // "report_playback_stopped"
        QT_MOC_LITERAL(1137, 6),  // "failed"
        QT_MOC_LITERAL(1144, 21),  // "report_playback_start"
        QT_MOC_LITERAL(1166, 13),  // "audioStreamId"
        QT_MOC_LITERAL(1180, 16),  // "subtitleStreamId"
        QT_MOC_LITERAL(1197, 18),  // "startPositionTicks"
        QT_MOC_LITERAL(1216, 13),  // "fetchSegments"
        QT_MOC_LITERAL(1230, 16),  // "get_access_token"
        QT_MOC_LITERAL(1247, 14),  // "get_server_url"
        QT_MOC_LITERAL(1262, 14),  // "get_auth_state"
        QT_MOC_LITERAL(1277, 12),  // "getLibraries"
        QT_MOC_LITERAL(1290, 17),  // "getVideoQualities"
        QT_MOC_LITERAL(1308, 27),  // "get_resume_playback_options"
        QT_MOC_LITERAL(1336, 23),  // "load_server_preferences"
        QT_MOC_LITERAL(1360, 19),  // "get_last_audio_lang"
        QT_MOC_LITERAL(1380, 17),  // "get_last_sub_lang"
        QT_MOC_LITERAL(1398, 23),  // "get_last_audio_lang_idx"
        QT_MOC_LITERAL(1422, 21),  // "get_last_sub_lang_idx"
        QT_MOC_LITERAL(1444, 20),  // "set_last_track_langs"
        QT_MOC_LITERAL(1465, 9),  // "audioLang"
        QT_MOC_LITERAL(1475, 7),  // "subLang"
        QT_MOC_LITERAL(1483, 12),  // "audioLangIdx"
        QT_MOC_LITERAL(1496, 10)   // "subLangIdx"
    },
    "EmbyBackend",
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
    "connectServersReady",
    "servers",
    "connectFailed",
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
    "authenticate",
    "serverUrl",
    "username",
    "password",
    "connect_authenticate",
    "usernameOrEmail",
    "connect_select_server",
    "accessKey",
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
    "get_access_token",
    "get_server_url",
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

Q_CONSTINIT static const uint qt_meta_data_EmbyBackend[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      65,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      22,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  404,    2, 0x06,    1 /* Public */,
       3,    1,  405,    2, 0x06,    2 /* Public */,
       5,    1,  408,    2, 0x06,    4 /* Public */,
       7,    1,  411,    2, 0x06,    6 /* Public */,
       9,    1,  414,    2, 0x06,    8 /* Public */,
      11,    1,  417,    2, 0x06,   10 /* Public */,
      12,    1,  420,    2, 0x06,   12 /* Public */,
      13,    1,  423,    2, 0x06,   14 /* Public */,
      15,    1,  426,    2, 0x06,   16 /* Public */,
      17,    1,  429,    2, 0x06,   18 /* Public */,
      18,    1,  432,    2, 0x06,   20 /* Public */,
      19,    1,  435,    2, 0x06,   22 /* Public */,
      20,    1,  438,    2, 0x06,   24 /* Public */,
      22,    2,  441,    2, 0x06,   26 /* Public */,
      25,    2,  446,    2, 0x06,   29 /* Public */,
      28,    1,  451,    2, 0x06,   32 /* Public */,
      30,    0,  454,    2, 0x06,   34 /* Public */,
      31,    0,  455,    2, 0x06,   35 /* Public */,
      32,    1,  456,    2, 0x06,   36 /* Public */,
      34,    1,  459,    2, 0x06,   38 /* Public */,
      35,    3,  462,    2, 0x06,   40 /* Public */,
      39,    1,  469,    2, 0x06,   44 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      40,    3,  472,    2, 0x0a,   46 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      43,    0,  479,    2, 0x02,   50 /* Public */,
      44,    0,  480,    2, 0x02,   51 /* Public */,
      45,    0,  481,    2, 0x02,   52 /* Public */,
      46,    0,  482,    2, 0x02,   53 /* Public */,
      47,    0,  483,    2, 0x02,   54 /* Public */,
      48,    3,  484,    2, 0x02,   55 /* Public */,
      52,    2,  491,    2, 0x02,   59 /* Public */,
      54,    2,  496,    2, 0x02,   62 /* Public */,
      56,    0,  501,    2, 0x02,   65 /* Public */,
      57,    3,  502,    2, 0x02,   66 /* Public */,
      61,    1,  509,    2, 0x02,   70 /* Public */,
      62,    1,  512,    2, 0x02,   72 /* Public */,
      63,    1,  515,    2, 0x02,   74 /* Public */,
      64,    1,  518,    2, 0x02,   76 /* Public */,
      65,    1,  521,    2, 0x02,   78 /* Public */,
      67,    2,  524,    2, 0x02,   80 /* Public */,
      69,    0,  529,    2, 0x02,   83 /* Public */,
      70,    0,  530,    2, 0x02,   84 /* Public */,
      71,    1,  531,    2, 0x02,   85 /* Public */,
      72,    5,  534,    2, 0x02,   87 /* Public */,
      72,    4,  545,    2, 0x22,   93 /* Public | MethodCloned */,
      77,    1,  554,    2, 0x02,   98 /* Public */,
      79,    4,  557,    2, 0x02,  100 /* Public */,
      82,    4,  566,    2, 0x02,  105 /* Public */,
      82,    3,  575,    2, 0x22,  110 /* Public | MethodCloned */,
      84,    5,  582,    2, 0x02,  114 /* Public */,
      84,    4,  593,    2, 0x22,  120 /* Public | MethodCloned */,
      88,    1,  602,    2, 0x02,  125 /* Public */,
      89,    0,  605,    2, 0x102,  127 /* Public | MethodIsConst  */,
      90,    0,  606,    2, 0x102,  128 /* Public | MethodIsConst  */,
      91,    0,  607,    2, 0x02,  129 /* Public */,
      92,    0,  608,    2, 0x02,  130 /* Public */,
      93,    0,  609,    2, 0x02,  131 /* Public */,
      94,    0,  610,    2, 0x02,  132 /* Public */,
      95,    0,  611,    2, 0x02,  133 /* Public */,
      96,    0,  612,    2, 0x102,  134 /* Public | MethodIsConst  */,
      97,    0,  613,    2, 0x102,  135 /* Public | MethodIsConst  */,
      98,    0,  614,    2, 0x102,  136 /* Public | MethodIsConst  */,
      99,    0,  615,    2, 0x102,  137 /* Public | MethodIsConst  */,
     100,    4,  616,    2, 0x02,  138 /* Public */,
     100,    3,  625,    2, 0x22,  143 /* Public | MethodCloned */,
     100,    2,  632,    2, 0x22,  147 /* Public | MethodCloned */,

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
    QMetaType::Void, QMetaType::QVariantList,   33,
    QMetaType::Void, QMetaType::QString,   29,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   36,   37,   38,
    QMetaType::Void, QMetaType::QVariantMap,    8,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QVariant,   41,   23,   42,

 // methods: parameters
    QMetaType::Bool,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   49,   50,   51,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   53,   51,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   49,   55,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   58,   59,   60,
    QMetaType::Void, QMetaType::QString,   26,
    QMetaType::Void, QMetaType::QString,   26,
    QMetaType::Void, QMetaType::QString,   58,
    QMetaType::Void, QMetaType::QString,   58,
    QMetaType::Void, QMetaType::QString,   66,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   66,   68,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   66,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Bool,   26,   73,   74,   75,   76,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int,   26,   73,   74,   75,
    QMetaType::Void, QMetaType::QString,   78,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::LongLong, QMetaType::Bool,   26,   73,   80,   81,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::LongLong, QMetaType::Bool,   26,   73,   80,   83,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::LongLong,   26,   73,   80,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::LongLong,   26,   73,   85,   86,   87,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   26,   73,   85,   86,
    QMetaType::Void, QMetaType::QString,   26,
    QMetaType::QString,
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
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int,  101,  102,  103,  104,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int,  101,  102,  103,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,  101,  102,

       0        // eod
};

Q_CONSTINIT const QMetaObject EmbyBackend::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_EmbyBackend.offsetsAndSizes,
    qt_meta_data_EmbyBackend,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_EmbyBackend_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<EmbyBackend, std::true_type>,
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
        // method 'connectServersReady'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariantList &, std::false_type>,
        // method 'connectFailed'
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
        // method 'authenticate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'connect_authenticate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'connect_select_server'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
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
        // method 'get_access_token'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_server_url'
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

void EmbyBackend::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<EmbyBackend *>(_o);
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
        case 18: _t->connectServersReady((*reinterpret_cast< std::add_pointer_t<QVariantList>>(_a[1]))); break;
        case 19: _t->connectFailed((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 20: _t->serverLanguagePreferencesReady((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 21: _t->nextEpisodeReady((*reinterpret_cast< std::add_pointer_t<QVariantMap>>(_a[1]))); break;
        case 22: _t->onSettingChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[3]))); break;
        case 23: { bool _r = _t->has_auth();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 24: { QString _r = _t->get_server_name();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 25: { QString _r = _t->get_user_name();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 26: _t->check_auth(); break;
        case 27: _t->logout(); break;
        case 28: _t->authenticate((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 29: _t->connect_authenticate((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 30: _t->connect_select_server((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 31: _t->load_libraries(); break;
        case 32: _t->load_items((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 33: _t->load_item_detail((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 34: _t->load_children((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 35: _t->load_boxset_children((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 36: _t->load_folder_children((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 37: _t->load_seasons((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 38: _t->load_episodes((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 39: _t->load_continue_watching(); break;
        case 40: _t->load_up_next(); break;
        case 41: _t->load_series_next_up((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 42: _t->get_playback_url((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[5]))); break;
        case 43: _t->get_playback_url((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4]))); break;
        case 44: _t->load_next_episode((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 45: _t->update_playback_progress((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<qint64>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[4]))); break;
        case 46: _t->report_playback_stopped((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<qint64>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[4]))); break;
        case 47: _t->report_playback_stopped((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<qint64>>(_a[3]))); break;
        case 48: _t->report_playback_start((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<qint64>>(_a[5]))); break;
        case 49: _t->report_playback_start((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4]))); break;
        case 50: _t->fetchSegments((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 51: { QString _r = _t->get_access_token();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 52: { QString _r = _t->get_server_url();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 53: { QString _r = _t->get_auth_state();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 54: _t->getLibraries(); break;
        case 55: _t->getVideoQualities(); break;
        case 56: _t->get_resume_playback_options(); break;
        case 57: _t->load_server_preferences(); break;
        case 58: { QString _r = _t->get_last_audio_lang();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 59: { QString _r = _t->get_last_sub_lang();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 60: { int _r = _t->get_last_audio_lang_idx();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 61: { int _r = _t->get_last_sub_lang_idx();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 62: _t->set_last_track_langs((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4]))); break;
        case 63: _t->set_last_track_langs((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 64: _t->set_last_track_langs((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (EmbyBackend::*)();
            if (_t _q_method = &EmbyBackend::authStateChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (EmbyBackend::*)(const QVariant & );
            if (_t _q_method = &EmbyBackend::librariesLoaded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (EmbyBackend::*)(const QVariant & );
            if (_t _q_method = &EmbyBackend::itemsLoaded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (EmbyBackend::*)(const QVariant & );
            if (_t _q_method = &EmbyBackend::itemLoaded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (EmbyBackend::*)(const QVariant & );
            if (_t _q_method = &EmbyBackend::childrenLoaded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (EmbyBackend::*)(const QVariant & );
            if (_t _q_method = &EmbyBackend::boxsetChildrenLoaded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (EmbyBackend::*)(const QVariant & );
            if (_t _q_method = &EmbyBackend::folderChildrenLoaded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (EmbyBackend::*)(const QVariant & );
            if (_t _q_method = &EmbyBackend::seasonsLoaded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (EmbyBackend::*)(const QVariant & );
            if (_t _q_method = &EmbyBackend::episodesLoaded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (EmbyBackend::*)(const QVariant & );
            if (_t _q_method = &EmbyBackend::continueWatchingLoaded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (EmbyBackend::*)(const QVariant & );
            if (_t _q_method = &EmbyBackend::upNextLoaded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (EmbyBackend::*)(const QVariantMap & );
            if (_t _q_method = &EmbyBackend::seriesNextUpReady; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (EmbyBackend::*)(const QString & );
            if (_t _q_method = &EmbyBackend::streamUrlReady; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (EmbyBackend::*)(const QString & , const QVariant & );
            if (_t _q_method = &EmbyBackend::dynamicOptionsReady; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (EmbyBackend::*)(const QString & , const QVariantList & );
            if (_t _q_method = &EmbyBackend::segmentsReady; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (EmbyBackend::*)(const QString & );
            if (_t _q_method = &EmbyBackend::errorOccurred; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (EmbyBackend::*)();
            if (_t _q_method = &EmbyBackend::logoutComplete; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (EmbyBackend::*)();
            if (_t _q_method = &EmbyBackend::authRevoked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (EmbyBackend::*)(const QVariantList & );
            if (_t _q_method = &EmbyBackend::connectServersReady; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 18;
                return;
            }
        }
        {
            using _t = void (EmbyBackend::*)(const QString & );
            if (_t _q_method = &EmbyBackend::connectFailed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 19;
                return;
            }
        }
        {
            using _t = void (EmbyBackend::*)(const QString & , const QString & , const QString & );
            if (_t _q_method = &EmbyBackend::serverLanguagePreferencesReady; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 20;
                return;
            }
        }
        {
            using _t = void (EmbyBackend::*)(const QVariantMap & );
            if (_t _q_method = &EmbyBackend::nextEpisodeReady; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 21;
                return;
            }
        }
    }
}

const QMetaObject *EmbyBackend::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EmbyBackend::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EmbyBackend.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int EmbyBackend::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 65)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 65;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 65)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 65;
    }
    return _id;
}

// SIGNAL 0
void EmbyBackend::authStateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void EmbyBackend::librariesLoaded(const QVariant & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void EmbyBackend::itemsLoaded(const QVariant & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void EmbyBackend::itemLoaded(const QVariant & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void EmbyBackend::childrenLoaded(const QVariant & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void EmbyBackend::boxsetChildrenLoaded(const QVariant & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void EmbyBackend::folderChildrenLoaded(const QVariant & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void EmbyBackend::seasonsLoaded(const QVariant & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void EmbyBackend::episodesLoaded(const QVariant & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void EmbyBackend::continueWatchingLoaded(const QVariant & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void EmbyBackend::upNextLoaded(const QVariant & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void EmbyBackend::seriesNextUpReady(const QVariantMap & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void EmbyBackend::streamUrlReady(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void EmbyBackend::dynamicOptionsReady(const QString & _t1, const QVariant & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void EmbyBackend::segmentsReady(const QString & _t1, const QVariantList & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void EmbyBackend::errorOccurred(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void EmbyBackend::logoutComplete()
{
    QMetaObject::activate(this, &staticMetaObject, 16, nullptr);
}

// SIGNAL 17
void EmbyBackend::authRevoked()
{
    QMetaObject::activate(this, &staticMetaObject, 17, nullptr);
}

// SIGNAL 18
void EmbyBackend::connectServersReady(const QVariantList & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void EmbyBackend::connectFailed(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void EmbyBackend::serverLanguagePreferencesReady(const QString & _t1, const QString & _t2, const QString & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void EmbyBackend::nextEpisodeReady(const QVariantMap & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 21, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
