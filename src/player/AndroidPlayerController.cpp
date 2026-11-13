#include "AndroidPlayerController.h"
#include "../AppCore.h"

#include <QCoreApplication>   // QNativeInterface::QAndroidApplication
#include <QJniEnvironment>
#include <QJniObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QPointer>
#include <QTimer>

namespace {
constexpr const char *kBridge = "com/mp240/android/PlayerBridge";
constexpr const char *kExerciseModule = "com.240mp.exercise";

// The one controller the JNI natives report to (main.cpp makes exactly one).
QPointer<AndroidPlayerController> g_controller;

template <typename F>
void onController(F &&f) {
    // Natives run on Android's main thread; the controller lives on Qt's.
    if (AndroidPlayerController *c = g_controller.data())
        QMetaObject::invokeMethod(c, [c, f = std::forward<F>(f)]() { f(c); }, Qt::QueuedConnection);
}

void JNICALL nativeProgress(JNIEnv *, jclass, jint session, jint positionMs, jint durationMs, jint playlistPos) {
    onController([=](AndroidPlayerController *c) { c->onProgress(session, positionMs, durationMs, playlistPos); });
}

void JNICALL nativeEnded(JNIEnv *env, jclass, jint session, jint positionMs, jint durationMs, jstring reason) {
    const char *chars = env->GetStringUTFChars(reason, nullptr);
    const QString r = QString::fromUtf8(chars);
    env->ReleaseStringUTFChars(reason, chars);
    onController([=](AndroidPlayerController *c) { c->onEnded(session, positionMs, durationMs, r); });
}

void JNICALL nativeSkipRequested(JNIEnv *, jclass, jint session) {
    onController([=](AndroidPlayerController *c) { c->onSkipRequested(session); });
}

QJsonArray toArray(const QStringList &l) { return QJsonArray::fromStringList(l); }

// A toggle setting: "ON"/"OFF" as Settings writes them (case-insensitively), or the default.
bool toggleOn(const QVariant &v, bool fallback) {
    const QString s = v.toString().trimmed();
    if (s.isEmpty()) return fallback;
    return s.compare(QLatin1String("ON"), Qt::CaseInsensitive) == 0
        || s.compare(QLatin1String("true"), Qt::CaseInsensitive) == 0;
}

QJniObject androidContext() {
    return QJniObject(QNativeInterface::QAndroidApplication::context());
}
} // namespace

AndroidPlayerController::AndroidPlayerController(const QString &appRoot, AppCore *appCore, QObject *parent)
    : QObject(parent), m_appRoot(appRoot), m_appCore(appCore)
{
    g_controller = this;
    const JNINativeMethod methods[] = {
        {"nativeProgress", "(IIII)V", reinterpret_cast<void *>(nativeProgress)},
        {"nativeEnded", "(IIILjava/lang/String;)V", reinterpret_cast<void *>(nativeEnded)},
        {"nativeSkipRequested", "(I)V", reinterpret_cast<void *>(nativeSkipRequested)},
    };
    QJniEnvironment env;
    if (!env.registerNativeMethods(kBridge, methods, 3))
        qWarning("[AndroidPlayer] could not register PlayerBridge natives — playback reports will be lost");
}

AndroidPlayerController::~AndroidPlayerController() {
    if (g_controller == this)
        g_controller = nullptr;
}

void AndroidPlayerController::loadAndPlay(const QString &url, float startSeconds,
                                          int audioTrack, int subTrack,
                                          const QStringList &subFiles,
                                          const QStringList &subLangs, bool loop,
                                          int playlistStart, float transcodeOffsetSec,
                                          const QString &plexToken, bool muteAudio,
                                          const QString &oscMode, bool shuffle,
                                          const QStringList &subTitles, float imageDurationSec,
                                          bool imageContent, const QStringList &extraArgs,
                                          const QString &jellyfinToken,
                                          const QStringList &extraUrls) {
    Q_UNUSED(transcodeOffsetSec) Q_UNUSED(oscMode) Q_UNUSED(imageDurationSec)
    Q_UNUSED(imageContent) Q_UNUSED(extraArgs)

    // A new video while one is playing replaces it, as with mpv: the old one ends "stopped".
    // Its activity's own late reports carry the old session number and are dropped.
    if (m_active)
        onEnded(m_session, m_position, m_duration, QStringLiteral("stopped"));
    ++m_session;

    m_position = 0;
    m_duration = 0;
    m_playlistPos = -1;

    QJsonObject headers;
    if (!plexToken.isEmpty())
        headers.insert(QStringLiteral("X-Plex-Token"), plexToken);
    if (!jellyfinToken.isEmpty())
        headers.insert(QStringLiteral("Authorization"), QStringLiteral("MediaBrowser Token=\"%1\"").arg(jellyfinToken));

    QJsonObject exercise;
    if (m_appCore) {
        exercise.insert(QStringLiteral("enabled"),
                        toggleOn(m_appCore->get_setting(kExerciseModule, QStringLiteral("exercise_mode")), true)
                        && toggleOn(m_appCore->get_setting(kExerciseModule, QStringLiteral("enabled")), true));
        exercise.insert(QStringLiteral("workout"),
                        m_appCore->get_setting(kExerciseModule, QStringLiteral("workout")).toString());
        exercise.insert(QStringLiteral("difficulty"),
                        m_appCore->get_setting(kExerciseModule, QStringLiteral("difficulty")).toString());
        exercise.insert(QStringLiteral("simulate"),
                        toggleOn(m_appCore->get_setting(kExerciseModule, QStringLiteral("simulate_bike")), false));
    }

    QStringList urls{url};
    urls << extraUrls;
    QJsonObject req{
        {QStringLiteral("session"), m_session},
        {QStringLiteral("urls"), toArray(urls)},
        {QStringLiteral("playlistStart"), qMax(0, playlistStart)},
        {QStringLiteral("startMs"), qint64(startSeconds > 0.5f ? double(startSeconds) * 1000.0 : 0.0)},
        {QStringLiteral("loop"), loop},
        {QStringLiteral("shuffle"), shuffle},
        {QStringLiteral("mute"), muteAudio},
        {QStringLiteral("headers"), headers},
        {QStringLiteral("subFiles"), toArray(subFiles)},
        {QStringLiteral("subLangs"), toArray(subLangs)},
        {QStringLiteral("subTitles"), toArray(subTitles)},
        {QStringLiteral("subTrack"), subTrack},
        {QStringLiteral("audioTrack"), audioTrack},
        {QStringLiteral("fontPath"), m_appRoot + QStringLiteral("/assets/fonts/VCR_OSD_MONO_1.001.ttf")},
        {QStringLiteral("exercise"), exercise},
    };
    const QString json = QString::fromUtf8(QJsonDocument(req).toJson(QJsonDocument::Compact));

    m_active = true;
    QJniObject::callStaticMethod<void>(kBridge, "play", "(Landroid/content/Context;Ljava/lang/String;)V",
                                       androidContext().object(),
                                       QJniObject::fromString(json).object<jstring>());
    QJniEnvironment env;
    if (env.checkAndClearExceptions()) {
        qWarning("[AndroidPlayer] could not start PlayerActivity");
        const int session = m_session;
        QTimer::singleShot(0, this, [this, session]() { onEnded(session, 0, 0, QStringLiteral("failed")); });
    }
}

void AndroidPlayerController::stop() {
    QJniObject::callStaticMethod<void>(kBridge, "stop", "()V");
}

void AndroidPlayerController::seekTo(int positionMs) {
    QJniObject::callStaticMethod<void>(kBridge, "seekTo", "(I)V", jint(positionMs));
}

void AndroidPlayerController::showOsdSkipPrompt() {
    QJniObject::callStaticMethod<void>(kBridge, "showSkipPrompt", "(Z)V", jboolean(true));
}

void AndroidPlayerController::onSkipRequested(int session) {
    if (m_active && session == m_session)
        emit skipRequested();
}

void AndroidPlayerController::clearOsdPrompt() {
    QJniObject::callStaticMethod<void>(kBridge, "showSkipPrompt", "(Z)V", jboolean(false));
}

void AndroidPlayerController::onProgress(int session, int positionMs, int durationMs, int playlistPos) {
    if (!m_active || session != m_session) return;
    if (positionMs != m_position) { m_position = positionMs; emit positionChanged(m_position); }
    if (durationMs != m_duration) { m_duration = durationMs; emit durationChanged(m_duration); }
    if (playlistPos != m_playlistPos) { m_playlistPos = playlistPos; emit playlistPosChanged(m_playlistPos); }
}

void AndroidPlayerController::onEnded(int session, int positionMs, int durationMs, const QString &reason) {
    if (!m_active || session != m_session) return;   // exactly once per loadAndPlay
    m_active = false;
    if (positionMs > 0) m_position = positionMs;
    if (durationMs > 0) m_duration = durationMs;
    emit playbackEnded(m_position, m_duration, reason);
}
