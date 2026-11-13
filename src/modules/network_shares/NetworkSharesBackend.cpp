#include "NetworkSharesBackend.h"
#include "../../AppCore.h"

#include <QCoreApplication>
#include <QFile>
#include <QJniEnvironment>
#include <QJniObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QPointer>
#include <QUrl>

namespace {
constexpr const char *kBridge = "com/mp240/android/smb/SmbBridge";
constexpr const char *kModule = "com.240mp.network_shares";
constexpr int kDefaultPort = 445;

QPointer<NetworkSharesBackend> g_backend;

QString fromJString(JNIEnv *env, jstring s) {
    const char *chars = env->GetStringUTFChars(s, nullptr);
    const QString out = QString::fromUtf8(chars);
    env->ReleaseStringUTFChars(s, chars);
    return out;
}

void JNICALL nativeTestResult(JNIEnv *env, jclass, jint requestId, jboolean ok, jstring message) {
    const QString msg = fromJString(env, message);
    if (NetworkSharesBackend *b = g_backend.data())
        QMetaObject::invokeMethod(b, [b, requestId, ok, msg]() { b->onTestResult(requestId, ok, msg); }, Qt::QueuedConnection);
}

void JNICALL nativeListResult(JNIEnv *env, jclass, jint requestId, jstring json) {
    const QString text = fromJString(env, json);
    if (NetworkSharesBackend *b = g_backend.data())
        QMetaObject::invokeMethod(b, [b, requestId, text]() { b->onListResult(requestId, text); }, Qt::QueuedConnection);
}

void callBridge(const char *method, const char *signature, jint requestId, const QString &arg) {
    QJniObject::callStaticMethod<void>(kBridge, method, signature, requestId,
                                       QJniObject::fromString(arg).object<jstring>());
    QJniEnvironment env;
    if (env.checkAndClearExceptions())
        qWarning("[NetworkShares] SmbBridge.%s failed", method);
}
} // namespace

NetworkSharesBackend::NetworkSharesBackend(const QString &dataRoot, AppCore *appCore, QObject *parent)
    : QObject(parent), m_dataRoot(dataRoot), m_appCore(appCore)
{
    g_backend = this;
    const JNINativeMethod methods[] = {
        {"nativeTestResult", "(IZLjava/lang/String;)V", reinterpret_cast<void *>(nativeTestResult)},
        {"nativeListResult", "(ILjava/lang/String;)V", reinterpret_cast<void *>(nativeListResult)},
    };
    QJniEnvironment env;
    if (!env.registerNativeMethods(kBridge, methods, 2))
        qWarning("[NetworkShares] could not register SmbBridge natives");

    // The player streams smb:// through the same Kotlin connection, so it needs the saved
    // server from the start, not only after the module is opened.
    pushConfig(savedServer());
}

NetworkSharesBackend::~NetworkSharesBackend() {
    if (g_backend == this)
        g_backend = nullptr;
}

QString NetworkSharesBackend::get_auth_state() const {
    return savedServer().valid() ? QStringLiteral("authed") : QStringLiteral("none");
}

QVariantMap NetworkSharesBackend::serverSettings() const {
    const Server s = savedServer();
    QString host = s.host;
    if (s.port != kDefaultPort && !host.isEmpty())
        host += QLatin1Char(':') + QString::number(s.port);
    return {
        {"host", host},
        {"share", s.share},
        {"username", s.username},
        {"domain", s.domain},
        {"hasPassword", !s.password.isEmpty()},
    };
}

void NetworkSharesBackend::connectToShare(const QString &host, const QString &share, const QString &username,
                                          const QString &password, const QString &domain) {
    const QString pw = password.isEmpty() ? savedServer().password : password;
    const Server s = parse(host, share, username, pw, domain);
    if (!s.valid()) {
        emit connectResult(false, QStringLiteral("Enter the server and the share"));
        return;
    }
    const int id = m_nextRequest++;
    m_pendingConnects.insert(id, s);
    callBridge("test", "(ILjava/lang/String;)V", id, toJson(s));
}

void NetworkSharesBackend::onTestResult(int requestId, bool ok, const QString &message) {
    if (!m_pendingConnects.contains(requestId)) return;
    const Server s = m_pendingConnects.take(requestId);
    if (ok && m_appCore) {
        QString host = s.host;
        if (s.port != kDefaultPort)
            host += QLatin1Char(':') + QString::number(s.port);
        m_appCore->save_setting(kModule, QStringLiteral("host"), host);
        m_appCore->save_setting(kModule, QStringLiteral("share"), s.share);
        m_appCore->save_setting(kModule, QStringLiteral("username"), s.username);
        m_appCore->save_setting(kModule, QStringLiteral("password"), s.password);
        m_appCore->save_setting(kModule, QStringLiteral("domain"), s.domain);
        pushConfig(s);
        emit authStateChanged();
    }
    emit connectResult(ok, ok ? QString() : message);
}

int NetworkSharesBackend::listFolder(const QString &path) {
    const int id = m_nextRequest++;
    m_pendingLists.insert(id, path);
    callBridge("list", "(ILjava/lang/String;)V", id, path);
    return id;
}

void NetworkSharesBackend::onListResult(int requestId, const QString &json) {
    if (!m_pendingLists.contains(requestId)) return;
    const QString path = m_pendingLists.take(requestId);
    const QJsonObject o = QJsonDocument::fromJson(json.toUtf8()).object();
    if (!o.value("ok").toBool()) {
        emit folderListed(requestId, path, {}, o.value("error").toString(QStringLiteral("Could not list the folder")));
        return;
    }
    emit folderListed(requestId, path, o.value("items").toArray().toVariantList(), QString());
}

void NetworkSharesBackend::runDiagnostics(const QString &host, const QString &share, const QString &username,
                                          const QString &password, const QString &domain) {
    // No server given (from the folder browser): check the saved settings as they are.
    const Server s = host.trimmed().isEmpty()
        ? savedServer()
        : parse(host, share, username, password.isEmpty() ? savedServer().password : password, domain);
    QJniObject::callStaticMethod<void>(kBridge, "diagnose", "(Ljava/lang/String;)V",
                                       QJniObject::fromString(toJson(s)).object<jstring>());
    QJniEnvironment env;
    if (env.checkAndClearExceptions())
        qWarning("[NetworkShares] SmbBridge.diagnose failed");
}

QString NetworkSharesBackend::diagnosticsLog() const {
    const QJniObject text = QJniObject::callStaticObjectMethod(kBridge, "logText", "()Ljava/lang/String;");
    QJniEnvironment env;
    if (env.checkAndClearExceptions() || !text.isValid())
        return QString();
    return text.toString();
}

QString NetworkSharesBackend::mediaUrl(const QString &path) const {
    const Server s = savedServer();
    QUrl url;
    url.setScheme(QStringLiteral("smb"));
    url.setHost(s.host);
    if (s.port != kDefaultPort)
        url.setPort(s.port);
    url.setPath(QLatin1Char('/') + s.share + QLatin1Char('/') + path);
    return url.toString(QUrl::FullyEncoded);
}

QStringList NetworkSharesBackend::mediaUrls(const QStringList &paths) const {
    QStringList out;
    for (const QString &p : paths)
        out << mediaUrl(p);
    return out;
}

QVariantMap NetworkSharesBackend::getSavedPosition(const QString &path) const {
    return loadPositions().value(positionKey(path)).toMap();
}

void NetworkSharesBackend::savePosition(const QString &path, int positionMs) {
    QVariantMap positions = loadPositions();
    positions.insert(positionKey(path), QVariantMap{{"pos", positionMs}});
    savePositions(positions);
}

void NetworkSharesBackend::clearPosition(const QString &path) {
    QVariantMap positions = loadPositions();
    positions.remove(positionKey(path));
    savePositions(positions);
}

void NetworkSharesBackend::forgetServer() {
    if (!m_appCore) return;
    for (const char *key : {"host", "share", "username", "password", "domain"})
        m_appCore->save_setting(kModule, QString::fromLatin1(key), QString());
    pushConfig(Server{});
    emit authStateChanged();
}

// ── Helpers ───────────────────────────────────────────────────────────────────

NetworkSharesBackend::Server NetworkSharesBackend::savedServer() const {
    if (!m_appCore) return {};
    auto get = [this](const char *key) {
        return m_appCore->get_setting(kModule, QString::fromLatin1(key)).toString();
    };
    return parse(get("host"), get("share"), get("username"), get("password"), get("domain"));
}

NetworkSharesBackend::Server NetworkSharesBackend::parse(const QString &hostField, const QString &share,
                                                         const QString &username, const QString &password,
                                                         const QString &domain) {
    Server s;
    // "nas.local", "192.168.1.20", "nas.local:4445"; a pasted "smb://nas.local/" works too.
    QString host = hostField.trimmed();
    if (host.startsWith(QLatin1String("smb://"), Qt::CaseInsensitive))
        host = host.mid(6);
    host = host.section(QLatin1Char('/'), 0, 0);
    const int colon = host.lastIndexOf(QLatin1Char(':'));
    if (colon > 0 && host.count(QLatin1Char(':')) == 1) {
        bool ok = false;
        const int port = host.mid(colon + 1).toInt(&ok);
        if (ok && port > 0 && port < 65536) {
            s.port = port;
            host = host.left(colon);
        }
    }
    s.host = host;
    QString shareName = share.trimmed();
    while (shareName.startsWith(QLatin1Char('/')) || shareName.startsWith(QLatin1Char('\\'))) shareName.remove(0, 1);
    while (shareName.endsWith(QLatin1Char('/')) || shareName.endsWith(QLatin1Char('\\'))) shareName.chop(1);
    s.share = shareName;
    s.username = username.trimmed();
    s.password = password;
    s.domain = domain.trimmed();
    return s;
}

QString NetworkSharesBackend::toJson(const Server &s) {
    return QString::fromUtf8(QJsonDocument(QJsonObject{
        {"host", s.host}, {"port", s.port}, {"share", s.share},
        {"username", s.username}, {"password", s.password}, {"domain", s.domain},
    }).toJson(QJsonDocument::Compact));
}

void NetworkSharesBackend::pushConfig(const Server &s) {
    QJniObject::callStaticMethod<void>(kBridge, "configure", "(Ljava/lang/String;)V",
                                       QJniObject::fromString(s.valid() ? toJson(s) : QString()).object<jstring>());
    QJniEnvironment env;
    if (env.checkAndClearExceptions())
        qWarning("[NetworkShares] SmbBridge.configure failed");
}

QString NetworkSharesBackend::positionKey(const QString &path) const {
    const Server s = savedServer();
    return s.host + QLatin1Char('/') + s.share + QLatin1Char('/') + path;
}

QVariantMap NetworkSharesBackend::loadPositions() const {
    QFile f(m_dataRoot + QStringLiteral("/network_shares_positions.json"));
    if (!f.open(QIODevice::ReadOnly)) return {};
    return QJsonDocument::fromJson(f.readAll()).object().toVariantMap();
}

void NetworkSharesBackend::savePositions(const QVariantMap &positions) const {
    QFile f(m_dataRoot + QStringLiteral("/network_shares_positions.json"));
    if (f.open(QIODevice::WriteOnly | QIODevice::Truncate))
        f.write(QJsonDocument(QJsonObject::fromVariantMap(positions)).toJson(QJsonDocument::Compact));
}
