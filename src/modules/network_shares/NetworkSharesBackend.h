#pragma once
#include <QHash>
#include <QObject>
#include <QString>
#include <QStringList>
#include <QVariantList>
#include <QVariantMap>

class AppCore;

// Backend for the Network Shares module (Android only): browse and play videos straight from an
// SMB 2/3 share on a NAS or computer, signed in with a username and password.
//
// The SMB work is Kotlin (android/src/com/mp240/android/smb/, on the smbj library): SmbBridge
// lists folders and tests sign-in over JNI, and the player streams smb:// addresses through
// SmbDataSource. This class keeps the server settings in the module's config, hands them to the
// Kotlin side, turns share paths into smb:// addresses for mpvController.loadAndPlay, and stores
// resume positions.
//
// Settings (modules.com.240mp.network_shares): host ("nas.local" or "nas.local:4445"), share,
// username, password, domain. The password sits in config.json in the app's private storage,
// as Plex's and Jellyfin's tokens do.
class NetworkSharesBackend : public QObject {
    Q_OBJECT
public:
    explicit NetworkSharesBackend(const QString &dataRoot, AppCore *appCore, QObject *parent = nullptr);
    ~NetworkSharesBackend() override;

    // "authed" once a share has been set up and signed in to; "none" before. Gates the
    // manifest's requires_auth settings and picks the module's first screen.
    Q_INVOKABLE QString get_auth_state() const;

    // The saved server settings for the setup screen: {host, share, username, domain, hasPassword}.
    Q_INVOKABLE QVariantMap serverSettings() const;

    // Signs in to the share; on success saves the settings and uses them from then on. An empty
    // password keeps the saved one (the setup screen never shows it). Answers with connectResult.
    Q_INVOKABLE void connectToShare(const QString &host, const QString &share, const QString &username,
                                    const QString &password, const QString &domain);

    // Lists a folder of the share ("" for its top, "/" separated). Answers with folderListed,
    // carrying the returned request id: [{name, path, isFolder, size, subtitles: [paths]}].
    Q_INVOKABLE int listFolder(const QString &path);

    // smb:// addresses for share paths, for mpvController.loadAndPlay (url and subtitle files).
    Q_INVOKABLE QString mediaUrl(const QString &path) const;
    Q_INVOKABLE QStringList mediaUrls(const QStringList &paths) const;

    // Resume positions, keyed by share and path.
    Q_INVOKABLE QVariantMap getSavedPosition(const QString &path) const;
    Q_INVOKABLE void savePosition(const QString &path, int positionMs);
    Q_INVOKABLE void clearPosition(const QString &path);

    // Called by the JNI natives (on the SMB thread); queued onto this object's thread.
    void onTestResult(int requestId, bool ok, const QString &message);
    void onListResult(int requestId, const QString &json);

public slots:
    // Settings > Network Shares > Forget Server (manifest action).
    void forgetServer();

signals:
    void authStateChanged();
    void connectResult(bool ok, const QString &message);
    void folderListed(int requestId, const QString &path, const QVariantList &items, const QString &error);

private:
    struct Server {
        QString host;
        int port = 445;
        QString share;
        QString username;
        QString password;
        QString domain;
        bool valid() const { return !host.isEmpty() && !share.isEmpty(); }
    };

    Server savedServer() const;
    static Server parse(const QString &hostField, const QString &share, const QString &username,
                        const QString &password, const QString &domain);
    static QString toJson(const Server &s);
    void pushConfig(const Server &s);
    QString positionKey(const QString &path) const;
    QVariantMap loadPositions() const;
    void savePositions(const QVariantMap &positions) const;

    QString m_dataRoot;
    AppCore *m_appCore = nullptr;
    int m_nextRequest = 1;
    QHash<int, QString> m_pendingLists;    // request id -> folder path
    QHash<int, Server> m_pendingConnects;  // request id -> settings being tried
};
