#include "AppBundle.h"

#include <QDir>
#include <QDirIterator>
#include <QFile>
#include <QFileInfo>
#include <QStandardPaths>

namespace {
constexpr const char *kBundlePrefix = ":/app";

// True when [dest] already holds exactly [contents].
bool same(const QString &dest, const QByteArray &contents) {
    QFile f(dest);
    if (!f.exists() || f.size() != contents.size()) return false;
    if (!f.open(QIODevice::ReadOnly)) return false;
    return f.readAll() == contents;
}
} // namespace

QString appbundle::extract() {
    const QString root = QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation)
                         + QStringLiteral("/bundle");
    if (!QDir().mkpath(root)) {
        qWarning("[AppBundle] cannot create %s", qPrintable(root));
        return {};
    }

    int written = 0, total = 0;
    QDirIterator it(QString::fromLatin1(kBundlePrefix), QDir::Files, QDirIterator::Subdirectories);
    while (it.hasNext()) {
        const QString src = it.next();
        const QString rel = src.mid(int(qstrlen(kBundlePrefix)));   // keeps the leading '/'
        const QString dest = root + rel;
        ++total;

        QFile in(src);
        if (!in.open(QIODevice::ReadOnly)) {
            qWarning("[AppBundle] cannot read %s", qPrintable(src));
            continue;
        }
        const QByteArray contents = in.readAll();
        if (same(dest, contents)) continue;

        QDir().mkpath(QFileInfo(dest).absolutePath());
        QFile out(dest);
        if (!out.open(QIODevice::WriteOnly | QIODevice::Truncate) || out.write(contents) != contents.size()) {
            qWarning("[AppBundle] cannot write %s", qPrintable(dest));
            continue;
        }
        ++written;
    }
    qInfo("[AppBundle] %d of %d bundled files updated in %s", written, total, qPrintable(root));
    return total > 0 ? root : QString();
}
