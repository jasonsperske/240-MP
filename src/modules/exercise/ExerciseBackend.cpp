#include "ExerciseBackend.h"

#include <QJniEnvironment>
#include <QJniObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QCoreApplication>   // QNativeInterface::QAndroidApplication

namespace {
constexpr const char *kRideBridge = "com/mp240/android/RideBridge";
constexpr int kPollMs = 250;

QJniObject androidContext() {
    return QJniObject(QNativeInterface::QAndroidApplication::context());
}

QJsonObject parse(const QString &json) {
    return QJsonDocument::fromJson(json.toUtf8()).object();
}
} // namespace

ExerciseBackend::ExerciseBackend(QObject *parent) : QObject(parent) {
    m_poll.setInterval(kPollMs);
    connect(&m_poll, &QTimer::timeout, this, &ExerciseBackend::poll);
}

ExerciseBackend::~ExerciseBackend() {
    stopMonitoring();
}

void ExerciseBackend::startMonitoring() {
    if (m_poll.isActive()) return;
    QJniObject::callStaticMethod<void>(kRideBridge, "start", "(Landroid/content/Context;)V",
                                       androidContext().object());
    QJniEnvironment env;
    if (env.checkAndClearExceptions()) {
        qWarning("[Exercise] could not start the bike connection");
        return;
    }
    m_poll.start();
    poll();
}

void ExerciseBackend::stopMonitoring() {
    if (!m_poll.isActive()) return;
    m_poll.stop();
    QJniObject::callStaticMethod<void>(kRideBridge, "stop", "()V");
}

void ExerciseBackend::poll() {
    const QJniObject json = QJniObject::callStaticObjectMethod(kRideBridge, "status", "()Ljava/lang/String;");
    QJniEnvironment env;
    if (env.checkAndClearExceptions() || !json.isValid()) return;
    const QJsonObject o = parse(json.toString());
    m_state      = o.value("state").toString();
    m_connected  = o.value("connected").toBool();
    m_live       = o.value("live").toBool();
    m_absent     = o.value("absent").toBool();
    m_rpm        = o.value("rpm").toInt();
    m_watts      = o.value("watts").toInt();
    m_resistance = o.value("resistance").toInt();
    emit readingChanged();
}

QVariantMap ExerciseBackend::previewProgram(const QString &workout, const QString &difficulty, int minutes) const {
    const QJniObject json = QJniObject::callStaticObjectMethod(
        kRideBridge, "preview", "(Ljava/lang/String;Ljava/lang/String;I)Ljava/lang/String;",
        QJniObject::fromString(workout).object<jstring>(),
        QJniObject::fromString(difficulty).object<jstring>(),
        jint(qMax(0, minutes) * 60));
    QJniEnvironment env;
    if (env.checkAndClearExceptions() || !json.isValid()) return {};
    return parse(json.toString()).toVariantMap();
}

void ExerciseBackend::openDiagnostics() {
    QJniObject::callStaticMethod<void>(kRideBridge, "openDiagnostics", "(Landroid/content/Context;)V",
                                       androidContext().object());
    QJniEnvironment env;
    if (env.checkAndClearExceptions())
        qWarning("[Exercise] could not open bike diagnostics");
}
