/****************************************************************************
** Meta object code from reading C++ file 'PlexBackend.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../src/modules/plex/PlexBackend.h"
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PlexBackend.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_PlexBackend_t {
    uint offsetsAndSizes[266];
    char stringdata0[12];
    char stringdata1[9];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[6];
    char stringdata5[12];
    char stringdata6[12];
    char stringdata7[6];
    char stringdata8[14];
    char stringdata9[8];
    char stringdata10[15];
    char stringdata11[17];
    char stringdata12[12];
    char stringdata13[16];
    char stringdata14[7];
    char stringdata15[9];
    char stringdata16[16];
    char stringdata17[10];
    char stringdata18[23];
    char stringdata19[6];
    char stringdata20[11];
    char stringdata21[5];
    char stringdata22[12];
    char stringdata23[18];
    char stringdata24[12];
    char stringdata25[16];
    char stringdata26[10];
    char stringdata27[17];
    char stringdata28[11];
    char stringdata29[13];
    char stringdata30[19];
    char stringdata31[13];
    char stringdata32[11];
    char stringdata33[7];
    char stringdata34[14];
    char stringdata35[14];
    char stringdata36[5];
    char stringdata37[15];
    char stringdata38[4];
    char stringdata39[10];
    char stringdata40[15];
    char stringdata41[13];
    char stringdata42[24];
    char stringdata43[5];
    char stringdata44[17];
    char stringdata45[11];
    char stringdata46[11];
    char stringdata47[14];
    char stringdata48[15];
    char stringdata49[10];
    char stringdata50[8];
    char stringdata51[19];
    char stringdata52[9];
    char stringdata53[20];
    char stringdata54[4];
    char stringdata55[8];
    char stringdata56[14];
    char stringdata57[15];
    char stringdata58[21];
    char stringdata59[23];
    char stringdata60[23];
    char stringdata61[17];
    char stringdata62[10];
    char stringdata63[8];
    char stringdata64[10];
    char stringdata65[15];
    char stringdata66[22];
    char stringdata67[12];
    char stringdata68[4];
    char stringdata69[19];
    char stringdata70[17];
    char stringdata71[19];
    char stringdata72[14];
    char stringdata73[10];
    char stringdata74[7];
    char stringdata75[15];
    char stringdata76[23];
    char stringdata77[18];
    char stringdata78[10];
    char stringdata79[19];
    char stringdata80[7];
    char stringdata81[17];
    char stringdata82[17];
    char stringdata83[22];
    char stringdata84[15];
    char stringdata85[20];
    char stringdata86[16];
    char stringdata87[20];
    char stringdata88[10];
    char stringdata89[12];
    char stringdata90[10];
    char stringdata91[27];
    char stringdata92[14];
    char stringdata93[12];
    char stringdata94[17];
    char stringdata95[18];
    char stringdata96[17];
    char stringdata97[15];
    char stringdata98[17];
    char stringdata99[13];
    char stringdata100[5];
    char stringdata101[5];
    char stringdata102[19];
    char stringdata103[4];
    char stringdata104[20];
    char stringdata105[15];
    char stringdata106[13];
    char stringdata107[16];
    char stringdata108[18];
    char stringdata109[8];
    char stringdata110[11];
    char stringdata111[9];
    char stringdata112[16];
    char stringdata113[6];
    char stringdata114[7];
    char stringdata115[11];
    char stringdata116[17];
    char stringdata117[9];
    char stringdata118[7];
    char stringdata119[20];
    char stringdata120[19];
    char stringdata121[13];
    char stringdata122[10];
    char stringdata123[21];
    char stringdata124[18];
    char stringdata125[9];
    char stringdata126[11];
    char stringdata127[13];
    char stringdata128[18];
    char stringdata129[28];
    char stringdata130[24];
    char stringdata131[26];
    char stringdata132[19];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_PlexBackend_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_PlexBackend_t qt_meta_stringdata_PlexBackend = {
    {
        QT_MOC_LITERAL(0, 11),  // "PlexBackend"
        QT_MOC_LITERAL(12, 8),  // "pinReady"
        QT_MOC_LITERAL(21, 0),  // ""
        QT_MOC_LITERAL(22, 4),  // "code"
        QT_MOC_LITERAL(27, 5),  // "pinId"
        QT_MOC_LITERAL(33, 11),  // "authSuccess"
        QT_MOC_LITERAL(45, 11),  // "usersLoaded"
        QT_MOC_LITERAL(57, 5),  // "users"
        QT_MOC_LITERAL(63, 13),  // "serversLoaded"
        QT_MOC_LITERAL(77, 7),  // "servers"
        QT_MOC_LITERAL(85, 14),  // "logoutComplete"
        QT_MOC_LITERAL(100, 16),  // "authStateChanged"
        QT_MOC_LITERAL(117, 11),  // "authRevoked"
        QT_MOC_LITERAL(129, 15),  // "userPinRequired"
        QT_MOC_LITERAL(145, 6),  // "userId"
        QT_MOC_LITERAL(152, 8),  // "wrongPin"
        QT_MOC_LITERAL(161, 15),  // "librariesLoaded"
        QT_MOC_LITERAL(177, 9),  // "libraries"
        QT_MOC_LITERAL(187, 22),  // "continueWatchingLoaded"
        QT_MOC_LITERAL(210, 5),  // "items"
        QT_MOC_LITERAL(216, 10),  // "hubsLoaded"
        QT_MOC_LITERAL(227, 4),  // "hubs"
        QT_MOC_LITERAL(232, 11),  // "itemsLoaded"
        QT_MOC_LITERAL(244, 17),  // "collectionsLoaded"
        QT_MOC_LITERAL(262, 11),  // "collections"
        QT_MOC_LITERAL(274, 15),  // "playlistsLoaded"
        QT_MOC_LITERAL(290, 9),  // "playlists"
        QT_MOC_LITERAL(300, 16),  // "categoriesLoaded"
        QT_MOC_LITERAL(317, 10),  // "categories"
        QT_MOC_LITERAL(328, 12),  // "folderLoaded"
        QT_MOC_LITERAL(341, 18),  // "capabilitiesLoaded"
        QT_MOC_LITERAL(360, 12),  // "capabilities"
        QT_MOC_LITERAL(373, 10),  // "itemLoaded"
        QT_MOC_LITERAL(384, 6),  // "detail"
        QT_MOC_LITERAL(391, 13),  // "showYearReady"
        QT_MOC_LITERAL(405, 13),  // "showRatingKey"
        QT_MOC_LITERAL(419, 4),  // "year"
        QT_MOC_LITERAL(424, 14),  // "streamUrlReady"
        QT_MOC_LITERAL(439, 3),  // "url"
        QT_MOC_LITERAL(443, 9),  // "plexToken"
        QT_MOC_LITERAL(453, 14),  // "childrenLoaded"
        QT_MOC_LITERAL(468, 12),  // "extrasLoaded"
        QT_MOC_LITERAL(481, 23),  // "inProgressEpisodeLoaded"
        QT_MOC_LITERAL(505, 4),  // "item"
        QT_MOC_LITERAL(510, 16),  // "nextEpisodeReady"
        QT_MOC_LITERAL(527, 10),  // "queueReady"
        QT_MOC_LITERAL(538, 10),  // "ratingKeys"
        QT_MOC_LITERAL(549, 13),  // "cardItemReady"
        QT_MOC_LITERAL(563, 14),  // "cardQueueReady"
        QT_MOC_LITERAL(578, 9),  // "cardError"
        QT_MOC_LITERAL(588, 7),  // "message"
        QT_MOC_LITERAL(596, 18),  // "liveChannelsLoaded"
        QT_MOC_LITERAL(615, 8),  // "channels"
        QT_MOC_LITERAL(624, 19),  // "dynamicOptionsReady"
        QT_MOC_LITERAL(644, 3),  // "key"
        QT_MOC_LITERAL(648, 7),  // "options"
        QT_MOC_LITERAL(656, 13),  // "errorOccurred"
        QT_MOC_LITERAL(670, 14),  // "get_auth_state"
        QT_MOC_LITERAL(685, 20),  // "get_active_user_name"
        QT_MOC_LITERAL(706, 22),  // "get_active_server_name"
        QT_MOC_LITERAL(729, 22),  // "get_switchable_servers"
        QT_MOC_LITERAL(752, 16),  // "build_stream_url"
        QT_MOC_LITERAL(769, 9),  // "ratingKey"
        QT_MOC_LITERAL(779, 7),  // "partKey"
        QT_MOC_LITERAL(787, 9),  // "sessionId"
        QT_MOC_LITERAL(797, 14),  // "start_pin_auth"
        QT_MOC_LITERAL(812, 21),  // "load_users_from_cache"
        QT_MOC_LITERAL(834, 11),  // "select_user"
        QT_MOC_LITERAL(846, 3),  // "pin"
        QT_MOC_LITERAL(850, 18),  // "reauth_select_user"
        QT_MOC_LITERAL(869, 16),  // "pending_pin_user"
        QT_MOC_LITERAL(886, 18),  // "cancel_pending_pin"
        QT_MOC_LITERAL(905, 13),  // "select_server"
        QT_MOC_LITERAL(919, 9),  // "machineId"
        QT_MOC_LITERAL(929, 6),  // "logout"
        QT_MOC_LITERAL(936, 14),  // "load_libraries"
        QT_MOC_LITERAL(951, 22),  // "load_continue_watching"
        QT_MOC_LITERAL(974, 17),  // "load_section_hubs"
        QT_MOC_LITERAL(992, 9),  // "sectionId"
        QT_MOC_LITERAL(1002, 18),  // "load_items_for_hub"
        QT_MOC_LITERAL(1021, 6),  // "hubKey"
        QT_MOC_LITERAL(1028, 16),  // "load_library_all"
        QT_MOC_LITERAL(1045, 16),  // "load_collections"
        QT_MOC_LITERAL(1062, 21),  // "load_collection_items"
        QT_MOC_LITERAL(1084, 14),  // "load_playlists"
        QT_MOC_LITERAL(1099, 19),  // "load_playlist_items"
        QT_MOC_LITERAL(1119, 15),  // "load_categories"
        QT_MOC_LITERAL(1135, 19),  // "load_category_items"
        QT_MOC_LITERAL(1155, 9),  // "filterKey"
        QT_MOC_LITERAL(1165, 11),  // "load_folder"
        QT_MOC_LITERAL(1177, 9),  // "folderKey"
        QT_MOC_LITERAL(1187, 26),  // "check_section_capabilities"
        QT_MOC_LITERAL(1214, 13),  // "load_children"
        QT_MOC_LITERAL(1228, 11),  // "load_extras"
        QT_MOC_LITERAL(1240, 16),  // "load_on_deck_for"
        QT_MOC_LITERAL(1257, 17),  // "load_next_episode"
        QT_MOC_LITERAL(1275, 16),  // "currentRatingKey"
        QT_MOC_LITERAL(1292, 14),  // "load_show_year"
        QT_MOC_LITERAL(1307, 16),  // "load_item_detail"
        QT_MOC_LITERAL(1324, 12),  // "resolve_card"
        QT_MOC_LITERAL(1337, 4),  // "guid"
        QT_MOC_LITERAL(1342, 4),  // "mode"
        QT_MOC_LITERAL(1347, 18),  // "resolve_card_queue"
        QT_MOC_LITERAL(1366, 3),  // "ref"
        QT_MOC_LITERAL(1370, 19),  // "load_random_episode"
        QT_MOC_LITERAL(1390, 14),  // "scopeRatingKey"
        QT_MOC_LITERAL(1405, 12),  // "expand_queue"
        QT_MOC_LITERAL(1418, 15),  // "load_queue_item"
        QT_MOC_LITERAL(1434, 17),  // "request_transcode"
        QT_MOC_LITERAL(1452, 7),  // "audioId"
        QT_MOC_LITERAL(1460, 10),  // "subtitleId"
        QT_MOC_LITERAL(1471, 8),  // "offsetMs"
        QT_MOC_LITERAL(1480, 15),  // "update_timeline"
        QT_MOC_LITERAL(1496, 5),  // "state"
        QT_MOC_LITERAL(1502, 6),  // "timeMs"
        QT_MOC_LITERAL(1509, 10),  // "durationMs"
        QT_MOC_LITERAL(1520, 16),  // "set_audio_stream"
        QT_MOC_LITERAL(1537, 8),  // "streamId"
        QT_MOC_LITERAL(1546, 6),  // "partId"
        QT_MOC_LITERAL(1553, 19),  // "set_subtitle_stream"
        QT_MOC_LITERAL(1573, 18),  // "load_live_channels"
        QT_MOC_LITERAL(1592, 12),  // "tune_channel"
        QT_MOC_LITERAL(1605, 9),  // "channelId"
        QT_MOC_LITERAL(1615, 20),  // "update_live_timeline"
        QT_MOC_LITERAL(1636, 17),  // "stop_live_session"
        QT_MOC_LITERAL(1654, 8),  // "getUsers"
        QT_MOC_LITERAL(1663, 10),  // "getServers"
        QT_MOC_LITERAL(1674, 12),  // "getLibraries"
        QT_MOC_LITERAL(1687, 17),  // "getVideoQualities"
        QT_MOC_LITERAL(1705, 27),  // "get_resume_playback_options"
        QT_MOC_LITERAL(1733, 23),  // "applyCurrentUserSetting"
        QT_MOC_LITERAL(1757, 25),  // "applyCurrentServerSetting"
        QT_MOC_LITERAL(1783, 18)   // "reset_device_check"
    },
    "PlexBackend",
    "pinReady",
    "",
    "code",
    "pinId",
    "authSuccess",
    "usersLoaded",
    "users",
    "serversLoaded",
    "servers",
    "logoutComplete",
    "authStateChanged",
    "authRevoked",
    "userPinRequired",
    "userId",
    "wrongPin",
    "librariesLoaded",
    "libraries",
    "continueWatchingLoaded",
    "items",
    "hubsLoaded",
    "hubs",
    "itemsLoaded",
    "collectionsLoaded",
    "collections",
    "playlistsLoaded",
    "playlists",
    "categoriesLoaded",
    "categories",
    "folderLoaded",
    "capabilitiesLoaded",
    "capabilities",
    "itemLoaded",
    "detail",
    "showYearReady",
    "showRatingKey",
    "year",
    "streamUrlReady",
    "url",
    "plexToken",
    "childrenLoaded",
    "extrasLoaded",
    "inProgressEpisodeLoaded",
    "item",
    "nextEpisodeReady",
    "queueReady",
    "ratingKeys",
    "cardItemReady",
    "cardQueueReady",
    "cardError",
    "message",
    "liveChannelsLoaded",
    "channels",
    "dynamicOptionsReady",
    "key",
    "options",
    "errorOccurred",
    "get_auth_state",
    "get_active_user_name",
    "get_active_server_name",
    "get_switchable_servers",
    "build_stream_url",
    "ratingKey",
    "partKey",
    "sessionId",
    "start_pin_auth",
    "load_users_from_cache",
    "select_user",
    "pin",
    "reauth_select_user",
    "pending_pin_user",
    "cancel_pending_pin",
    "select_server",
    "machineId",
    "logout",
    "load_libraries",
    "load_continue_watching",
    "load_section_hubs",
    "sectionId",
    "load_items_for_hub",
    "hubKey",
    "load_library_all",
    "load_collections",
    "load_collection_items",
    "load_playlists",
    "load_playlist_items",
    "load_categories",
    "load_category_items",
    "filterKey",
    "load_folder",
    "folderKey",
    "check_section_capabilities",
    "load_children",
    "load_extras",
    "load_on_deck_for",
    "load_next_episode",
    "currentRatingKey",
    "load_show_year",
    "load_item_detail",
    "resolve_card",
    "guid",
    "mode",
    "resolve_card_queue",
    "ref",
    "load_random_episode",
    "scopeRatingKey",
    "expand_queue",
    "load_queue_item",
    "request_transcode",
    "audioId",
    "subtitleId",
    "offsetMs",
    "update_timeline",
    "state",
    "timeMs",
    "durationMs",
    "set_audio_stream",
    "streamId",
    "partId",
    "set_subtitle_stream",
    "load_live_channels",
    "tune_channel",
    "channelId",
    "update_live_timeline",
    "stop_live_session",
    "getUsers",
    "getServers",
    "getLibraries",
    "getVideoQualities",
    "get_resume_playback_options",
    "applyCurrentUserSetting",
    "applyCurrentServerSetting",
    "reset_device_check"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_PlexBackend[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      86,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      31,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,  530,    2, 0x06,    1 /* Public */,
       5,    0,  535,    2, 0x06,    4 /* Public */,
       6,    1,  536,    2, 0x06,    5 /* Public */,
       8,    1,  539,    2, 0x06,    7 /* Public */,
      10,    0,  542,    2, 0x06,    9 /* Public */,
      11,    0,  543,    2, 0x06,   10 /* Public */,
      12,    0,  544,    2, 0x06,   11 /* Public */,
      13,    2,  545,    2, 0x06,   12 /* Public */,
      16,    1,  550,    2, 0x06,   15 /* Public */,
      18,    1,  553,    2, 0x06,   17 /* Public */,
      20,    1,  556,    2, 0x06,   19 /* Public */,
      22,    1,  559,    2, 0x06,   21 /* Public */,
      23,    1,  562,    2, 0x06,   23 /* Public */,
      25,    1,  565,    2, 0x06,   25 /* Public */,
      27,    1,  568,    2, 0x06,   27 /* Public */,
      29,    1,  571,    2, 0x06,   29 /* Public */,
      30,    1,  574,    2, 0x06,   31 /* Public */,
      32,    1,  577,    2, 0x06,   33 /* Public */,
      34,    2,  580,    2, 0x06,   35 /* Public */,
      37,    2,  585,    2, 0x06,   38 /* Public */,
      40,    1,  590,    2, 0x06,   41 /* Public */,
      41,    1,  593,    2, 0x06,   43 /* Public */,
      42,    1,  596,    2, 0x06,   45 /* Public */,
      44,    1,  599,    2, 0x06,   47 /* Public */,
      45,    1,  602,    2, 0x06,   49 /* Public */,
      47,    1,  605,    2, 0x06,   51 /* Public */,
      48,    1,  608,    2, 0x06,   53 /* Public */,
      49,    1,  611,    2, 0x06,   55 /* Public */,
      51,    1,  614,    2, 0x06,   57 /* Public */,
      53,    2,  617,    2, 0x06,   59 /* Public */,
      56,    1,  622,    2, 0x06,   62 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      57,    0,  625,    2, 0x02,   64 /* Public */,
      58,    0,  626,    2, 0x02,   65 /* Public */,
      59,    0,  627,    2, 0x02,   66 /* Public */,
      60,    0,  628,    2, 0x02,   67 /* Public */,
      61,    3,  629,    2, 0x02,   68 /* Public */,
      65,    0,  636,    2, 0x02,   72 /* Public */,
      66,    0,  637,    2, 0x02,   73 /* Public */,
      67,    2,  638,    2, 0x02,   74 /* Public */,
      67,    1,  643,    2, 0x22,   77 /* Public | MethodCloned */,
      69,    2,  646,    2, 0x02,   79 /* Public */,
      69,    1,  651,    2, 0x22,   82 /* Public | MethodCloned */,
      70,    0,  654,    2, 0x102,   84 /* Public | MethodIsConst  */,
      71,    0,  655,    2, 0x02,   85 /* Public */,
      72,    1,  656,    2, 0x02,   86 /* Public */,
      74,    0,  659,    2, 0x02,   88 /* Public */,
      75,    0,  660,    2, 0x02,   89 /* Public */,
      76,    0,  661,    2, 0x02,   90 /* Public */,
      77,    1,  662,    2, 0x02,   91 /* Public */,
      79,    1,  665,    2, 0x02,   93 /* Public */,
      81,    1,  668,    2, 0x02,   95 /* Public */,
      82,    1,  671,    2, 0x02,   97 /* Public */,
      83,    1,  674,    2, 0x02,   99 /* Public */,
      84,    1,  677,    2, 0x02,  101 /* Public */,
      85,    1,  680,    2, 0x02,  103 /* Public */,
      86,    1,  683,    2, 0x02,  105 /* Public */,
      87,    2,  686,    2, 0x02,  107 /* Public */,
      89,    2,  691,    2, 0x02,  110 /* Public */,
      91,    1,  696,    2, 0x02,  113 /* Public */,
      92,    1,  699,    2, 0x02,  115 /* Public */,
      93,    1,  702,    2, 0x02,  117 /* Public */,
      94,    1,  705,    2, 0x02,  119 /* Public */,
      95,    1,  708,    2, 0x02,  121 /* Public */,
      97,    1,  711,    2, 0x02,  123 /* Public */,
      98,    1,  714,    2, 0x02,  125 /* Public */,
      99,    2,  717,    2, 0x02,  127 /* Public */,
     102,    1,  722,    2, 0x02,  130 /* Public */,
     104,    1,  725,    2, 0x02,  132 /* Public */,
     106,    1,  728,    2, 0x02,  134 /* Public */,
     107,    1,  731,    2, 0x02,  136 /* Public */,
     108,    6,  734,    2, 0x02,  138 /* Public */,
     112,    5,  747,    2, 0x02,  145 /* Public */,
     116,    2,  758,    2, 0x02,  151 /* Public */,
     119,    2,  763,    2, 0x02,  154 /* Public */,
     120,    0,  768,    2, 0x02,  157 /* Public */,
     121,    2,  769,    2, 0x02,  158 /* Public */,
     123,    1,  774,    2, 0x02,  161 /* Public */,
     124,    1,  777,    2, 0x02,  163 /* Public */,
     125,    0,  780,    2, 0x02,  165 /* Public */,
     126,    0,  781,    2, 0x02,  166 /* Public */,
     127,    0,  782,    2, 0x02,  167 /* Public */,
     128,    0,  783,    2, 0x02,  168 /* Public */,
     129,    0,  784,    2, 0x02,  169 /* Public */,
     130,    0,  785,    2, 0x02,  170 /* Public */,
     131,    0,  786,    2, 0x02,  171 /* Public */,
     132,    0,  787,    2, 0x02,  172 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariant,    7,
    QMetaType::Void, QMetaType::QVariant,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,   14,   15,
    QMetaType::Void, QMetaType::QVariant,   17,
    QMetaType::Void, QMetaType::QVariant,   19,
    QMetaType::Void, QMetaType::QVariant,   21,
    QMetaType::Void, QMetaType::QVariant,   19,
    QMetaType::Void, QMetaType::QVariant,   24,
    QMetaType::Void, QMetaType::QVariant,   26,
    QMetaType::Void, QMetaType::QVariant,   28,
    QMetaType::Void, QMetaType::QVariant,   19,
    QMetaType::Void, QMetaType::QVariant,   31,
    QMetaType::Void, QMetaType::QVariant,   33,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   35,   36,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   38,   39,
    QMetaType::Void, QMetaType::QVariant,   19,
    QMetaType::Void, QMetaType::QVariant,   19,
    QMetaType::Void, QMetaType::QVariant,   43,
    QMetaType::Void, QMetaType::QVariant,   33,
    QMetaType::Void, QMetaType::QStringList,   46,
    QMetaType::Void, QMetaType::QVariant,   33,
    QMetaType::Void, QMetaType::QVariant,   19,
    QMetaType::Void, QMetaType::QString,   50,
    QMetaType::Void, QMetaType::QVariant,   52,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant,   54,   55,
    QMetaType::Void, QMetaType::QString,   50,

 // methods: parameters
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QVariantList,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   62,   63,   64,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   14,   68,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   14,   68,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::QString,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   73,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   78,
    QMetaType::Void, QMetaType::QString,   80,
    QMetaType::Void, QMetaType::QString,   78,
    QMetaType::Void, QMetaType::QString,   78,
    QMetaType::Void, QMetaType::QString,   62,
    QMetaType::Void, QMetaType::QString,   78,
    QMetaType::Void, QMetaType::QString,   62,
    QMetaType::Void, QMetaType::QString,   78,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   78,   88,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   78,   90,
    QMetaType::Void, QMetaType::QString,   78,
    QMetaType::Void, QMetaType::QString,   62,
    QMetaType::Void, QMetaType::QString,   62,
    QMetaType::Void, QMetaType::QString,   62,
    QMetaType::Void, QMetaType::QString,   96,
    QMetaType::Void, QMetaType::QString,   35,
    QMetaType::Void, QMetaType::QString,   62,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,  100,  101,
    QMetaType::Void, QMetaType::QString,  103,
    QMetaType::Void, QMetaType::QString,  105,
    QMetaType::Void, QMetaType::QVariantList,   19,
    QMetaType::Void, QMetaType::QString,   62,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int,   62,   63,   64,  109,  110,  111,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int,   62,   63,  113,  114,  115,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,  117,  118,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,  117,  118,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,  122,   64,
    QMetaType::Void, QMetaType::QString,  113,
    QMetaType::Void, QMetaType::QString,   64,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject PlexBackend::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_PlexBackend.offsetsAndSizes,
    qt_meta_data_PlexBackend,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_PlexBackend_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<PlexBackend, std::true_type>,
        // method 'pinReady'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'authSuccess'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'usersLoaded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariant &, std::false_type>,
        // method 'serversLoaded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariant &, std::false_type>,
        // method 'logoutComplete'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'authStateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'authRevoked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'userPinRequired'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'librariesLoaded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariant &, std::false_type>,
        // method 'continueWatchingLoaded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariant &, std::false_type>,
        // method 'hubsLoaded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariant &, std::false_type>,
        // method 'itemsLoaded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariant &, std::false_type>,
        // method 'collectionsLoaded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariant &, std::false_type>,
        // method 'playlistsLoaded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariant &, std::false_type>,
        // method 'categoriesLoaded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariant &, std::false_type>,
        // method 'folderLoaded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariant &, std::false_type>,
        // method 'capabilitiesLoaded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariant &, std::false_type>,
        // method 'itemLoaded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariant &, std::false_type>,
        // method 'showYearReady'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'streamUrlReady'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'childrenLoaded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariant &, std::false_type>,
        // method 'extrasLoaded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariant &, std::false_type>,
        // method 'inProgressEpisodeLoaded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariant &, std::false_type>,
        // method 'nextEpisodeReady'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariant &, std::false_type>,
        // method 'queueReady'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>,
        // method 'cardItemReady'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariant &, std::false_type>,
        // method 'cardQueueReady'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariant &, std::false_type>,
        // method 'cardError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'liveChannelsLoaded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariant &, std::false_type>,
        // method 'dynamicOptionsReady'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariant &, std::false_type>,
        // method 'errorOccurred'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'get_auth_state'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_active_user_name'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_active_server_name'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_switchable_servers'
        QtPrivate::TypeAndForceComplete<QVariantList, std::false_type>,
        // method 'build_stream_url'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'start_pin_auth'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'load_users_from_cache'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'select_user'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'select_user'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'reauth_select_user'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'reauth_select_user'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'pending_pin_user'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'cancel_pending_pin'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'select_server'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'logout'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'load_libraries'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'load_continue_watching'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'load_section_hubs'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'load_items_for_hub'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'load_library_all'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'load_collections'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'load_collection_items'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'load_playlists'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'load_playlist_items'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'load_categories'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'load_category_items'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'load_folder'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'check_section_capabilities'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'load_children'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'load_extras'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'load_on_deck_for'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'load_next_episode'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'load_show_year'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'load_item_detail'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'resolve_card'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'resolve_card_queue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'load_random_episode'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'expand_queue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariantList &, std::false_type>,
        // method 'load_queue_item'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'request_transcode'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'update_timeline'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'set_audio_stream'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'set_subtitle_stream'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'load_live_channels'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'tune_channel'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'update_live_timeline'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'stop_live_session'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'getUsers'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'getServers'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'getLibraries'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'getVideoQualities'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'get_resume_playback_options'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'applyCurrentUserSetting'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'applyCurrentServerSetting'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'reset_device_check'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void PlexBackend::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PlexBackend *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->pinReady((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 1: _t->authSuccess(); break;
        case 2: _t->usersLoaded((*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[1]))); break;
        case 3: _t->serversLoaded((*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[1]))); break;
        case 4: _t->logoutComplete(); break;
        case 5: _t->authStateChanged(); break;
        case 6: _t->authRevoked(); break;
        case 7: _t->userPinRequired((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 8: _t->librariesLoaded((*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[1]))); break;
        case 9: _t->continueWatchingLoaded((*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[1]))); break;
        case 10: _t->hubsLoaded((*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[1]))); break;
        case 11: _t->itemsLoaded((*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[1]))); break;
        case 12: _t->collectionsLoaded((*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[1]))); break;
        case 13: _t->playlistsLoaded((*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[1]))); break;
        case 14: _t->categoriesLoaded((*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[1]))); break;
        case 15: _t->folderLoaded((*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[1]))); break;
        case 16: _t->capabilitiesLoaded((*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[1]))); break;
        case 17: _t->itemLoaded((*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[1]))); break;
        case 18: _t->showYearReady((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 19: _t->streamUrlReady((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 20: _t->childrenLoaded((*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[1]))); break;
        case 21: _t->extrasLoaded((*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[1]))); break;
        case 22: _t->inProgressEpisodeLoaded((*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[1]))); break;
        case 23: _t->nextEpisodeReady((*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[1]))); break;
        case 24: _t->queueReady((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 25: _t->cardItemReady((*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[1]))); break;
        case 26: _t->cardQueueReady((*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[1]))); break;
        case 27: _t->cardError((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 28: _t->liveChannelsLoaded((*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[1]))); break;
        case 29: _t->dynamicOptionsReady((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[2]))); break;
        case 30: _t->errorOccurred((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 31: { QString _r = _t->get_auth_state();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 32: { QString _r = _t->get_active_user_name();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 33: { QString _r = _t->get_active_server_name();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 34: { QVariantList _r = _t->get_switchable_servers();
            if (_a[0]) *reinterpret_cast< QVariantList*>(_a[0]) = std::move(_r); }  break;
        case 35: _t->build_stream_url((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 36: _t->start_pin_auth(); break;
        case 37: _t->load_users_from_cache(); break;
        case 38: _t->select_user((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 39: _t->select_user((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 40: _t->reauth_select_user((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 41: _t->reauth_select_user((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 42: { QString _r = _t->pending_pin_user();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 43: _t->cancel_pending_pin(); break;
        case 44: _t->select_server((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 45: _t->logout(); break;
        case 46: _t->load_libraries(); break;
        case 47: _t->load_continue_watching(); break;
        case 48: _t->load_section_hubs((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 49: _t->load_items_for_hub((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 50: _t->load_library_all((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 51: _t->load_collections((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 52: _t->load_collection_items((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 53: _t->load_playlists((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 54: _t->load_playlist_items((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 55: _t->load_categories((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 56: _t->load_category_items((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 57: _t->load_folder((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 58: _t->check_section_capabilities((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 59: _t->load_children((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 60: _t->load_extras((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 61: _t->load_on_deck_for((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 62: _t->load_next_episode((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 63: _t->load_show_year((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 64: _t->load_item_detail((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 65: _t->resolve_card((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 66: _t->resolve_card_queue((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 67: _t->load_random_episode((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 68: _t->expand_queue((*reinterpret_cast< std::add_pointer_t<QVariantList>>(_a[1]))); break;
        case 69: _t->load_queue_item((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 70: _t->request_transcode((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[6]))); break;
        case 71: _t->update_timeline((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5]))); break;
        case 72: _t->set_audio_stream((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 73: _t->set_subtitle_stream((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 74: _t->load_live_channels(); break;
        case 75: _t->tune_channel((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 76: _t->update_live_timeline((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 77: _t->stop_live_session((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 78: _t->getUsers(); break;
        case 79: _t->getServers(); break;
        case 80: _t->getLibraries(); break;
        case 81: _t->getVideoQualities(); break;
        case 82: _t->get_resume_playback_options(); break;
        case 83: _t->applyCurrentUserSetting(); break;
        case 84: _t->applyCurrentServerSetting(); break;
        case 85: _t->reset_device_check(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PlexBackend::*)(const QString & , const QString & );
            if (_t _q_method = &PlexBackend::pinReady; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PlexBackend::*)();
            if (_t _q_method = &PlexBackend::authSuccess; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PlexBackend::*)(const QVariant & );
            if (_t _q_method = &PlexBackend::usersLoaded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (PlexBackend::*)(const QVariant & );
            if (_t _q_method = &PlexBackend::serversLoaded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (PlexBackend::*)();
            if (_t _q_method = &PlexBackend::logoutComplete; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (PlexBackend::*)();
            if (_t _q_method = &PlexBackend::authStateChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (PlexBackend::*)();
            if (_t _q_method = &PlexBackend::authRevoked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (PlexBackend::*)(const QString & , bool );
            if (_t _q_method = &PlexBackend::userPinRequired; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (PlexBackend::*)(const QVariant & );
            if (_t _q_method = &PlexBackend::librariesLoaded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (PlexBackend::*)(const QVariant & );
            if (_t _q_method = &PlexBackend::continueWatchingLoaded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (PlexBackend::*)(const QVariant & );
            if (_t _q_method = &PlexBackend::hubsLoaded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (PlexBackend::*)(const QVariant & );
            if (_t _q_method = &PlexBackend::itemsLoaded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (PlexBackend::*)(const QVariant & );
            if (_t _q_method = &PlexBackend::collectionsLoaded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (PlexBackend::*)(const QVariant & );
            if (_t _q_method = &PlexBackend::playlistsLoaded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (PlexBackend::*)(const QVariant & );
            if (_t _q_method = &PlexBackend::categoriesLoaded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (PlexBackend::*)(const QVariant & );
            if (_t _q_method = &PlexBackend::folderLoaded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (PlexBackend::*)(const QVariant & );
            if (_t _q_method = &PlexBackend::capabilitiesLoaded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (PlexBackend::*)(const QVariant & );
            if (_t _q_method = &PlexBackend::itemLoaded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (PlexBackend::*)(const QString & , int );
            if (_t _q_method = &PlexBackend::showYearReady; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 18;
                return;
            }
        }
        {
            using _t = void (PlexBackend::*)(const QString & , const QString & );
            if (_t _q_method = &PlexBackend::streamUrlReady; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 19;
                return;
            }
        }
        {
            using _t = void (PlexBackend::*)(const QVariant & );
            if (_t _q_method = &PlexBackend::childrenLoaded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 20;
                return;
            }
        }
        {
            using _t = void (PlexBackend::*)(const QVariant & );
            if (_t _q_method = &PlexBackend::extrasLoaded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 21;
                return;
            }
        }
        {
            using _t = void (PlexBackend::*)(const QVariant & );
            if (_t _q_method = &PlexBackend::inProgressEpisodeLoaded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 22;
                return;
            }
        }
        {
            using _t = void (PlexBackend::*)(const QVariant & );
            if (_t _q_method = &PlexBackend::nextEpisodeReady; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 23;
                return;
            }
        }
        {
            using _t = void (PlexBackend::*)(const QStringList & );
            if (_t _q_method = &PlexBackend::queueReady; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 24;
                return;
            }
        }
        {
            using _t = void (PlexBackend::*)(const QVariant & );
            if (_t _q_method = &PlexBackend::cardItemReady; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 25;
                return;
            }
        }
        {
            using _t = void (PlexBackend::*)(const QVariant & );
            if (_t _q_method = &PlexBackend::cardQueueReady; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 26;
                return;
            }
        }
        {
            using _t = void (PlexBackend::*)(const QString & );
            if (_t _q_method = &PlexBackend::cardError; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 27;
                return;
            }
        }
        {
            using _t = void (PlexBackend::*)(const QVariant & );
            if (_t _q_method = &PlexBackend::liveChannelsLoaded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 28;
                return;
            }
        }
        {
            using _t = void (PlexBackend::*)(const QString & , const QVariant & );
            if (_t _q_method = &PlexBackend::dynamicOptionsReady; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 29;
                return;
            }
        }
        {
            using _t = void (PlexBackend::*)(const QString & );
            if (_t _q_method = &PlexBackend::errorOccurred; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 30;
                return;
            }
        }
    }
}

const QMetaObject *PlexBackend::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlexBackend::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PlexBackend.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int PlexBackend::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 86)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 86;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 86)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 86;
    }
    return _id;
}

// SIGNAL 0
void PlexBackend::pinReady(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PlexBackend::authSuccess()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void PlexBackend::usersLoaded(const QVariant & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void PlexBackend::serversLoaded(const QVariant & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void PlexBackend::logoutComplete()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void PlexBackend::authStateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void PlexBackend::authRevoked()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void PlexBackend::userPinRequired(const QString & _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void PlexBackend::librariesLoaded(const QVariant & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void PlexBackend::continueWatchingLoaded(const QVariant & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void PlexBackend::hubsLoaded(const QVariant & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void PlexBackend::itemsLoaded(const QVariant & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void PlexBackend::collectionsLoaded(const QVariant & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void PlexBackend::playlistsLoaded(const QVariant & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void PlexBackend::categoriesLoaded(const QVariant & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void PlexBackend::folderLoaded(const QVariant & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void PlexBackend::capabilitiesLoaded(const QVariant & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void PlexBackend::itemLoaded(const QVariant & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void PlexBackend::showYearReady(const QString & _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void PlexBackend::streamUrlReady(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void PlexBackend::childrenLoaded(const QVariant & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void PlexBackend::extrasLoaded(const QVariant & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 21, _a);
}

// SIGNAL 22
void PlexBackend::inProgressEpisodeLoaded(const QVariant & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 22, _a);
}

// SIGNAL 23
void PlexBackend::nextEpisodeReady(const QVariant & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 23, _a);
}

// SIGNAL 24
void PlexBackend::queueReady(const QStringList & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 24, _a);
}

// SIGNAL 25
void PlexBackend::cardItemReady(const QVariant & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 25, _a);
}

// SIGNAL 26
void PlexBackend::cardQueueReady(const QVariant & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 26, _a);
}

// SIGNAL 27
void PlexBackend::cardError(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 27, _a);
}

// SIGNAL 28
void PlexBackend::liveChannelsLoaded(const QVariant & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 28, _a);
}

// SIGNAL 29
void PlexBackend::dynamicOptionsReady(const QString & _t1, const QVariant & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 29, _a);
}

// SIGNAL 30
void PlexBackend::errorOccurred(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 30, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
