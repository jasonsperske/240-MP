#pragma once
#include <QObject>
#include <QString>
#include <QTimer>
#include <QVariantMap>

// Backend for the exercise module (Android only: the gen 1 Peloton Bike's tablet).
//
// Exercise mode itself runs in the player (android/src/com/mp240/android/PlayerActivity.kt): the
// video plays only while the rider holds the workout's cadence and resistance. This backend
// serves the module's Ride Check screen: live readings from the bike (through RideBridge.kt and
// soloton's bike library) and a preview of the workout a video would get, built by the same
// Kotlin code the player uses (android/exercise-core).
class ExerciseBackend : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString state     READ state     NOTIFY readingChanged)
    Q_PROPERTY(bool connected    READ connected NOTIFY readingChanged)
    Q_PROPERTY(bool live         READ live      NOTIFY readingChanged)
    Q_PROPERTY(bool absent       READ absent    NOTIFY readingChanged)
    Q_PROPERTY(int rpm           READ rpm       NOTIFY readingChanged)
    Q_PROPERTY(int watts         READ watts     NOTIFY readingChanged)
    Q_PROPERTY(int resistance    READ resistance NOTIFY readingChanged)

public:
    explicit ExerciseBackend(QObject *parent = nullptr);
    ~ExerciseBackend() override;

    QString state() const { return m_state; }
    bool connected() const { return m_connected; }
    bool live() const { return m_live; }
    bool absent() const { return m_absent; }
    int rpm() const { return m_rpm; }
    int watts() const { return m_watts; }
    int resistance() const { return m_resistance; }

    // Connects to the bike and polls it while Ride Check is open.
    Q_INVOKABLE void startMonitoring();
    Q_INVOKABLE void stopMonitoring();

    // The program [workout] at [difficulty] lays over a video of [minutes]:
    // {workout, difficulty, lengthMs, repeats, segments: [{startMs, endMs, label, rpm, resistance}]}.
    Q_INVOKABLE QVariantMap previewProgram(const QString &workout, const QString &difficulty, int minutes) const;

    // Opens the bike library's sensor diagnostics screen.
    Q_INVOKABLE void openDiagnostics();

signals:
    void readingChanged();

private:
    void poll();

    QTimer  m_poll;
    QString m_state = QStringLiteral("Not started");
    bool    m_connected = false;
    bool    m_live = false;
    bool    m_absent = false;
    int     m_rpm = 0;
    int     m_watts = 0;
    int     m_resistance = 0;
};
