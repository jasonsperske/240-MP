#pragma once
#include <QObject>
#include <QString>
#include <QStringList>

class AppCore;

// Android's stand-in for MpvController, exposed to QML under the same name ("mpvController")
// with the same properties, slots and signals, so every module's Player view works unchanged.
//
// There is no mpv process on Android. loadAndPlay hands the video to PlayerActivity
// (android/src/com/mp240/android/PlayerActivity.kt, Media3/ExoPlayer) through
// PlayerBridge.play, and the activity reports progress and its end back through JNI natives
// registered here. Same hand-off as the desktop: the shell browses, a dedicated full-screen
// player plays, and the shell resumes when it closes.
//
// Exercise mode lives in that activity. This class reads the exercise module's settings
// (modules.com.240mp.exercise) and passes them along with each video.
class AndroidPlayerController : public QObject {
    Q_OBJECT
    Q_PROPERTY(int position    READ position    NOTIFY positionChanged)
    Q_PROPERTY(int duration    READ duration    NOTIFY durationChanged)
    Q_PROPERTY(int playlistPos READ playlistPos NOTIFY playlistPosChanged)

public:
    explicit AndroidPlayerController(const QString &appRoot, AppCore *appCore, QObject *parent = nullptr);
    ~AndroidPlayerController() override;

    int position()    const { return m_position;    }
    int duration()    const { return m_duration;    }
    int playlistPos() const { return m_playlistPos; }

    // Same signature as MpvController::loadAndPlay. Arguments that only mean something to mpv
    // (oscMode, extraArgs, transcodeOffsetSec, imageDurationSec, imageContent) are accepted and
    // ignored.
    Q_INVOKABLE void loadAndPlay(const QString &url, float startSeconds,
                                  int audioTrack, int subTrack,
                                  const QStringList &subFiles = {},
                                  const QStringList &subLangs = {},
                                  bool loop = false,
                                  int playlistStart = -1,
                                  float transcodeOffsetSec = 0.0f,
                                  const QString &plexToken = {},
                                  bool muteAudio = false,
                                  const QString &oscMode = {},
                                  bool shuffle = false,
                                  const QStringList &subTitles = {},
                                  float imageDurationSec = 0.0f,
                                  bool imageContent = false,
                                  const QStringList &extraArgs = {},
                                  const QString &jellyfinToken = {},
                                  const QStringList &extraUrls = {});
    Q_INVOKABLE void stop();
    Q_INVOKABLE void seekTo(int positionMs);
    Q_INVOKABLE void sendKey(const QString &key) { Q_UNUSED(key) }   // the activity has the keys
    Q_INVOKABLE void showOsdSkipPrompt();
    Q_INVOKABLE void clearOsdPrompt();
    Q_INVOKABLE bool hasSmoothPlaybackTradeoff() const { return false; }

    // Called from the JNI natives (on Android's main thread), queued onto this object's thread.
    // [session] is the number loadAndPlay gave the playback; reports from an older one are dropped.
    void onProgress(int session, int positionMs, int durationMs, int playlistPos);
    void onEnded(int session, int positionMs, int durationMs, const QString &reason);
    void onSkipRequested(int session);
    // Saves a Stats View / Stats Corner change made in the player (exercise module settings).
    void saveExerciseSetting(const QString &key, const QString &value);

signals:
    void positionChanged(int ms);
    void durationChanged(int ms);
    void playlistPosChanged(int pos);
    // As MpvController: exactly once per loadAndPlay, reason "eof", "stopped" or "failed".
    void playbackEnded(int finalPositionMs, int finalDurationMs, const QString &reason);
    void skipRequested();
    // Never emitted on Android (ExoPlayer cycles tracks itself); declared so QML Connections bind.
    void subtitleCycleRequested();
    void audioCycleRequested();

private:
    QString m_appRoot;
    AppCore *m_appCore = nullptr;
    bool m_active = false;   // a playback is running and owes a playbackEnded
    int m_session = 0;       // numbers each loadAndPlay
    int m_position = 0;
    int m_duration = 0;
    int m_playlistPos = -1;
};
